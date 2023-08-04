/****************************************************************************

 ast.c:
 Implements functions required for building the AST, type table, symbol table
 and scopes. Also some functions to find the type_node or look up the sym_id
 or offset in the scopes.

*****************************************************************************/


#include "c2java.h"

/* symble table */

static int last_sym_id = 0;

struct sym_node *sym_table = NULL;

struct sym_node* new_sym_node(const char *s, struct sym_node *next)
{
    struct sym_node *p = malloc(sizeof(struct sym_node));
    strcpy(p->str, s);
    p->sym_id = ++last_sym_id;
    p->next = next;
    return p;
}

int sym(const char *s)
{
    for (struct sym_node *p = sym_table; p; p = p->next)
        if (strcmp(s, p->str) == 0) return p->sym_id;

    sym_table = new_sym_node(s, sym_table);
    return sym_table->sym_id;
}

char* symname(int sym_id)
{
    for (struct sym_node *p = sym_table; p; p = p->next)
    {
        if (p->sym_id == sym_id) return p->str;
    }
    report_error("sym_id %d not found", sym_id);
    return NULL;
}

/* variable and function scope */

struct vscope *current_vscope = NULL;

void begin_vscope()
{
    struct vscope *new_vscope = malloc(sizeof(struct vscope));
    new_vscope->parent = current_vscope;
    new_vscope->list = NULL;
    current_vscope = new_vscope;
}

void vscope_addnode(struct vscope *v, int sym_id, int type_id, int offset)
{
    struct vscope_node *n = malloc(sizeof(struct vscope_node));
    n->scope = v;
    n->sym_id = sym_id;
    n->type_id = type_id;
    n->offset = offset;
    n->next = v->list;
    v->list = n;
}

void end_vscope()
{
    struct vscope *to_free = current_vscope;
    current_vscope = current_vscope->parent;

    //free nodes
    struct vscope_node* head = to_free->list, *tmp = NULL;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    
    free(to_free);
}

static struct vscope_node * find_vnode_rec(struct vscope *c_vscope, int sym_id)
{
    if (!c_vscope) report_error("%s not defined", symname(sym_id));

    for (struct vscope_node *p = c_vscope->list; p; p = p->next)
        if (p->sym_id == sym_id) return p;

    return find_vnode_rec(c_vscope->parent, sym_id);
}

struct vscope_node * find_vnode(int sym_id)
{
    return find_vnode_rec(current_vscope, sym_id);
}

/* type scope */

struct tscope *current_tscope = NULL;

void begin_tscope()
{
    struct tscope *new_tscope = malloc(sizeof(struct tscope));
    new_tscope->parent = current_tscope;
    new_tscope->list = NULL;
    current_tscope = new_tscope;
}

void tscope_addnode(struct tscope *t, int sym_id, int type_id)
{
    struct tscope_node *n = malloc(sizeof(struct tscope_node));
    n->sym_id = sym_id;
    n->type_id = type_id;
    n->next = t->list;
    t->list = n;
}

void end_tscope()
{
    struct tscope *to_free = current_tscope;
    current_tscope = current_tscope->parent;

    struct tscope_node* head = to_free->list, *tmp = NULL;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(to_free);
}

int lookup_ttype_rec(struct tscope *c_tscope, int sym_id)
{
    if (!c_tscope) report_error("Type not defined");

    for (struct tscope_node *p = c_tscope->list; p; p = p->next)
        if (p->sym_id == sym_id) return p->type_id;

    return lookup_ttype_rec(c_tscope->parent, sym_id);
}

int lookup_ttype(int sym_id)
{
    return lookup_ttype_rec(current_tscope, sym_id);
}


/* type table*/

static int last_type_id = 1;

static struct type_node *type_table = NULL;

struct type_node* find_type_node(int type_id)
{
    for (struct type_node *p = type_table; p; p = p->next)
        if (p->type_id == type_id) return p;
    report_error("find_type_node error");
    return NULL;
}

int get_memspace(int type_id)
{
    if (type_id == 1) return 4;
    return find_type_node(type_id)->mem_space;
}

int get_struct_offset(int type_id, int sym_id)
{
    struct field_list *f = find_type_node(type_id)->as_struct.fields;
    for (; f; f = f->next)
        if (f->sym_id == sym_id) return (f->index) * 4;
    report_error("error occurred in get_struct_offset");
    return -1;
}

int parse_int_hex(char const *s)
{
    int n = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        n *= 16;
        if ('0' <= s[i] && s[i] <= '9')
            n += s[i] - '0';
        else if ('a' <= s[i] && s[i] <= 'z')
            n += s[i] - 'a' + 10;
        else if ('A' <= s[i] && s[i] <= 'Z')
            n += s[i] - 'A' + 10;
    }
    return n;
}

int parse_int_oct(char const *s)
{
    int n = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        n = n * 8 + s[i] - '0';
    }
    return n;
}

int parse_int(char const *s)
{
    int l = strlen(s);
    if (l != 1)
    {
        if (s[0] == '0')
        {
            if (s[1] == 'x' || s[1] == 'X') return parse_int_hex(s+2);
            else return parse_int_oct(s+1);
        }
    }
    int n = 0;
    for (int i = 0; i < l; ++i)
    {
        n = n * 10 + s[i] - '0';
    }
    return n;
}

int int_type(void)
{
    return 1;
}

int struct_type(ast_node *stspec)
{
    struct type_node *n = malloc(sizeof(struct type_node));
    n->type_id = ++last_type_id;
    n->ty = STRUCTURE;
    n->as_struct.fields = NULL;
    n->as_struct.sym_name = stspec->stdef.sym_name;
    int i = 0;
    for (ast_node *defs = stspec->stdef.defs; defs; defs = defs->list.tail)
    {
        ast_node *def = defs->list.head;

        for (ast_node *decs = def->list.head; decs; decs = decs->list.tail)
        {
            ast_node *dec = decs->list.head;

            if (dec->dec.init) report_error("struct_type error");
            struct field_list *p = malloc(sizeof(struct field_list));
            p->index = i++;
            p->sym_id = dec->dec.var->var.sym_name;
            p->next = n->as_struct.fields;
            n->as_struct.fields = p;
        }
    }
    n->mem_space = i * 4;
    n->next = type_table;
    type_table = n;
    return n->type_id;
}

int array_type(ast_node *subvar, int elem_type_id)
{
    struct type_node *n = malloc(sizeof(struct type_node));
    n->type_id = ++last_type_id;
    n->ty = ARRAY;
    n->as_array.elem_type_id = elem_type_id;
    n->as_array.size = subvar->subvar.index;
    n->mem_space = n->as_array.size * get_memspace(elem_type_id);
    n->next = type_table;
    type_table = n;
    return n->type_id;
}

int func_type(ast_node *funchead)
{
    struct type_node *n = malloc(sizeof(struct type_node));
    n->type_id = ++last_type_id;
    n->ty = FUNC;
    n->as_func.ret_type = 1; // return type is INT
    n->as_func.para_num = 0;
    ast_node *p = funchead->funchead.paras;
    for (; p; p = p->list.tail)
    {
        n->as_func.para_type[n->as_func.para_num++] = p->list.head->para.para_type;
    }
    n->mem_space = n->as_func.para_num * 4; 
    n->next = type_table;
    type_table = n;
    return n->type_id;
}

int builtin_func_type(int argc)
{
    struct type_node *n = malloc(sizeof(struct type_node));
    n->type_id = ++last_type_id;
    n->ty = FUNC;
    n->as_func.ret_type = 1;
    n->as_func.para_num = argc;
    for (argc = 0; argc < n->as_func.para_num; argc++) n->as_func.para_type[argc] = 1;
    n->next = type_table;
    type_table = n;
    return n->type_id;
}

static ast_node *newast(int type)
{
    ast_node *node = malloc(sizeof(ast_node));
    node->type = type;
    node->type_id = -1;
    node->lvalue = -1;
    node->offset = -1;
    node->framesize = -1;
    node->fg = 'f';
    return node;
}


ast_list *list_new(int type, ast_node *head, ast_list *tail)
{
    ast_list *l = newast(AST_LIST);
    l->list.type = type;
    l->list.head = head;
    l->list.tail = tail;
    return l;
}

void list_append(ast_list *first, ast_list *second)
{
    while (first && first->list.tail)
    {
        first = first->list.tail;
    }
    if (first)
    {
        first->list.tail = second;
    }
}

/*
ast_node *vardef_new(int var_type, ast_list *extvars)
{
    ast_node *n = newast(AST_VARDEF);
    n->vardef.var_type = var_type;
    n->vardef.extvars = extvars;
    return n;
}
*/

ast_node *funcdef_new(int ret_type, ast_node *funchead, ast_stmt *funcbody)
{
    ast_node *n = newast(AST_FUNCDEF);
    n->funcdef.ret_type = ret_type;
    n->funcdef.funchead = funchead;
    n->funcdef.funcbody = funcbody;
    return n;
}

ast_node *funchead_new(int sym_name, ast_list *paras)
{
    ast_node *n = newast(AST_FUNCHEAD);
    n->funchead.sym_name = sym_name;
    n->funchead.paras = paras;
    return n;
}

ast_node *para_new(int para_type, ast_node *var)
{
    ast_node *n = newast(AST_PARA);
    n->para.para_type = para_type;
    n->para.var = var;
    return n;
}

ast_node *stdef_new(int sym_name, ast_list *defs)
{
    ast_node *n = newast(AST_STDEF);
    n->stdef.sym_name = sym_name;
    n->stdef.defs = defs;
    return n;
}

ast_node *var_new(int sym_name)
{
    ast_node *n = newast(AST_VAR);
    n->var.sym_name = sym_name;
    return n;
}

ast_node *subvar_new(ast_node *var, int index)
{
    ast_node *n = newast(AST_SUBVAR);
    n->subvar.var = var;
    n->subvar.index = index;
    return n;
}

ast_stmt *compound_stmt_new(ast_list *defs, ast_list *stmts)
{
    ast_stmt *s = newast(AST_COMPOUND_STMT);
    s->compound_stmt.defs = defs;
    s->compound_stmt.stmts = stmts;
    return s;
}

ast_stmt *expr_stmt_new(ast_expr *expr)
{
    ast_stmt *s = newast(AST_EXPR_STMT);
    s->expr_stmt.expr = expr;
    return s;
}

ast_stmt *if_stmt_new(ast_expr *cond, ast_stmt *then, ast_stmt *els)
{
    ast_stmt *s = newast(AST_IF_STMT);
    s->if_stmt.cond = cond;
    s->if_stmt.then = then;
    s->if_stmt.els = els;
    return s;
}

ast_stmt *for_stmt_new(ast_expr *init, ast_expr *cond, ast_expr *incr, ast_stmt *body)
{
    ast_stmt *s = newast(AST_FOR_STMT);
    s->for_stmt.init = init;
    s->for_stmt.cond = cond;
    s->for_stmt.incr = incr;
    s->for_stmt.body = body;
    return s;
}

ast_stmt *return_stmt_new(ast_expr *retval)
{
    ast_stmt *s = newast(AST_RETURN_STMT);
    s->return_stmt.retval = retval;
    return s;
}

ast_stmt *continue_stmt_new()
{
    return newast(AST_CONTINUE_STMT);
}

ast_stmt *break_stmt_new()
{
    return newast(AST_BREAK_STMT);
}

ast_node *def_new(int def_type, ast_list *decs)
{
    ast_node *n = newast(AST_DEF);
    n->def.def_type = def_type;
    n->def.decs = decs;
    return n;
}

ast_node *dec_new(ast_node *var, ast_node *init)
{
    ast_node *n = newast(AST_DEC);
    n->dec.var = var;
    n->dec.init = init;
    return n;
}

ast_expr *binop_new(int op, ast_expr *lhs, ast_expr *rhs)
{
    ast_expr *e = newast(AST_BINOP);
    e->binop.op = op;
    e->binop.lhs = lhs;
    e->binop.rhs = rhs;
    return e;
}

ast_expr *prefix_new(int op, ast_expr *unary)
{
    ast_expr *e = newast(AST_PREFIX);
    e->prefix.op = op;
    e->prefix.unary = unary;
    return e;
}

ast_expr *postfix_new(int op, ast_expr *unary)
{
    ast_expr *e = newast(AST_POSTFIX);
    e->postfix.op = op;
    e->postfix.unary = unary;
    return e;
}

ast_expr *indexing_new(ast_expr *postfix, ast_expr *expr)
{
    ast_expr *e = newast(AST_INDEXING);
    e->indexing.postfix = postfix;
    e->indexing.expr = expr;
    return e;
}

ast_expr *func_call_new(ast_expr *postfix, ast_list *args)
{
    ast_expr *e = newast(AST_FUNC_CALL);
    e->func_call.postfix = postfix;
    e->func_call.args = args;
    return e;
}

ast_expr *member_new(ast_expr *postfix, int sym_name)
{
    ast_expr *e = newast(AST_MEMBER);
    e->member.postfix = postfix;
    e->member.sym_name = sym_name;
    return e;
}

ast_expr *id_new(int sym_name)
{
    ast_expr *e = newast(AST_ID);
    e->id.sym_name = sym_name;
    return e;
}

ast_expr *const_new(int number)
{
    ast_expr *e = newast(AST_CONST);
    e->constant.number = number;
    return e;
}

/*
ast_node *init_arg_new(int sym_name, ast_expr *expr)
{
    ast_node *n = newast(AST_INIT_ARG);
    n->init_arg.sym_name = sym_name;
    n->init_arg.expr = expr;
    return n;
}
*/
