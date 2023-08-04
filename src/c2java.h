/****************************************************************************

 c2java.h:
 Declares the data structure of ast_node, type_node, scope_node, sym_node and
 other functions prototypes which are used through out the building of the compiler.

*****************************************************************************/

#ifndef C2JAVA_H_
#define C2JAVA_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "c2java.tab.h"

/** Parse functions **/

extern int yylex(void);
extern void yyerror(char const *s);
extern int yyparse(void);

/** AST nodes **/

typedef struct ast_node {
    enum {
        AST_LIST,
        /*AST_VARDEF,*/ AST_FUNCDEF, AST_FUNCHEAD, AST_PARA,
        AST_STDEF, AST_VAR, AST_SUBVAR,
        AST_COMPOUND_STMT, AST_EXPR_STMT, AST_IF_STMT, AST_FOR_STMT,
        AST_RETURN_STMT, AST_CONTINUE_STMT, AST_BREAK_STMT,
        AST_DEF, AST_DEC,
        AST_BINOP, AST_PREFIX, AST_POSTFIX,
        AST_INDEXING, AST_FUNC_CALL, AST_MEMBER,
        AST_ID, AST_CONST, /*AST_INIT_ARG,*/
        AST_TYPE_LIMIT
    } type;
    
    union {
        struct {
            int type;
            struct ast_node *head;
            struct ast_node *tail;
        } list;

        struct {
            int ret_type;
            struct ast_node *funchead;
            struct ast_node *funcbody;
        } funcdef;

        struct {
            int sym_name;
            struct ast_node *paras;
        } funchead;

        struct {
            int para_type;
            struct ast_node *var;
        } para;

        struct {
            int sym_name;
            struct ast_node *defs;
        } stdef;

        struct {
            int sym_name;
        } var;

        struct {
            int index;
            struct ast_node *var;
        } subvar;

        struct {
            struct ast_node *defs;
            struct ast_node *stmts;
        } compound_stmt;

        struct {
            struct ast_node *expr;
        } expr_stmt;

        struct {
            struct ast_node *cond;
            struct ast_node *then;
            struct ast_node *els;
        } if_stmt;

        struct {
            struct ast_node *init;
            struct ast_node *cond;
            struct ast_node *incr;
            struct ast_node *body;
        } for_stmt;

        struct {
            struct ast_node *retval;
        } return_stmt;

        struct {
            int def_type;
            struct ast_node *decs;
        } def;

        struct {
            struct ast_node *var;
            struct ast_node *init;
        } dec;

        struct {
            int op;
            struct ast_node *lhs;
            struct ast_node *rhs;
        } binop;

        struct {
            int op;
            struct ast_node *unary;
        } prefix;

        struct {
            int op;
            struct ast_node *unary;
        } postfix;

        struct {
            struct ast_node *postfix;
            struct ast_node *expr;
        } indexing;

        struct {
            struct ast_node *postfix;
            struct ast_node *args;
        } func_call;

        struct {
            int sym_name;
            struct ast_node *postfix;
        } member;

        struct {
            int sym_name;
        } id;

        struct {
            int number;
        } constant;

        /*
        struct {
            int sym_name;
            struct ast_node *expr;
        } init_arg;
        */
    };
    int type_id;
    int lvalue; // 1 - left value   0 - right value
    int offset;
    int framesize;
    char fg;
} ast_node;

typedef ast_node ast_expr;
typedef ast_node ast_list;
typedef ast_node ast_stmt;


struct sym_node
{
  char str[1024];
  int sym_id;
  struct sym_node *next;
};

extern struct sym_node *sym_table;

extern int sym(char const *s);
extern char * symname(int sym_id);
extern int parse_int(char const *s);


struct vscope
{
	struct vscope *parent;
	struct vscope_node *list;
};

struct vscope_node
{
    struct vscope *scope;
	int sym_id;
	int type_id;
	int offset;
	struct vscope_node *next;
};

struct tscope
{
	struct tscope *parent;
	struct tscope_node *list;
};

struct tscope_node
{
	int sym_id;
	int type_id;
	struct tscope_node *next;
};

extern struct vscope *current_vscope;
extern struct tscope *current_tscope;

extern void begin_vscope();
extern void vscope_addnode(struct vscope *v, int sym_id, int type_id, int offset);
extern void end_vscope();
extern void begin_tscope();
extern void tscope_addnode(struct tscope *t, int sym_id, int type_id);
extern void end_tscope();

/* Here we don't have INT in TYPE as we can give the INT a type_id 1, thus there is no need to record in TYPE */
enum TYPE {STRUCTURE, ARRAY, FUNC};

struct field_list
{
	int sym_id;
	int index;
	struct field_list *next;
};

struct type_node
{
  int type_id;
  enum TYPE ty;
  union
  {
    struct
    {
      int sym_name;
      struct field_list *fields;
    } as_struct;
    struct 
    {
      int elem_type_id;
      int size;
    } as_array;
    struct
    {
      int ret_type;
      int para_num; 
      int para_type[1000];
    } as_func;
  };
  int mem_space;
  struct type_node *next;
};


extern int int_type(void);
extern int struct_type(ast_node *stspec);
extern int array_type(ast_node *subvar, int elem_type_id);
extern int func_type(ast_node *funchead);
extern int builtin_func_type(int);

extern struct type_node* find_type_node(int type_id);
extern int get_memspace(int type_id);
extern int get_struct_offset(int type_id, int sym_id);

extern struct vscope_node * find_vnode(int sym_id);
extern int lookup_ttype(int sym_id);

extern ast_list *list_new(int type, ast_node *head, ast_list *tail);
extern void list_append(ast_list *first, ast_list *second);

// extern ast_node *vardef_new(int var_type, ast_list *extvars);
extern ast_node *funcdef_new(int ret_type, ast_node *funchead, ast_stmt *funcbody);
extern ast_node *funchead_new(int sym_name, ast_list *paras);
extern ast_node *para_new(int para_type, ast_node *var);

extern ast_node *stdef_new(int sym_name, ast_list *defs);

extern ast_node *var_new(int sym_name);
extern ast_node *subvar_new(ast_node *var, int index);

extern ast_stmt *compound_stmt_new(ast_list *defs, ast_list *stmts);
extern ast_stmt *expr_stmt_new(ast_expr *expr);
extern ast_stmt *if_stmt_new(ast_expr *cond, ast_stmt *then, ast_stmt *els);
extern ast_stmt *for_stmt_new(ast_expr *init, ast_expr *cond, ast_expr *incr, ast_stmt *body);
extern ast_stmt *return_stmt_new(ast_expr *retval);
extern ast_stmt *continue_stmt_new();
extern ast_stmt *break_stmt_new();

extern ast_node *def_new(int def_type, ast_list *decs);
extern ast_node *dec_new(ast_node *var, ast_node *init);

extern ast_expr *binop_new(int op, ast_expr *lhs, ast_expr *rhs);
extern ast_expr *prefix_new(int op, ast_expr *unary);
extern ast_expr *postfix_new(int op, ast_expr *unary);
extern ast_expr *indexing_new(ast_expr *postfix, ast_expr *expr);
extern ast_expr *func_call_new(ast_expr *postfix, ast_list *args);
extern ast_expr *member_new(ast_expr *postfix, int sym_name);
extern ast_expr *id_new(int sym_name);
extern ast_expr *const_new(int number);

extern ast_node *init_arg_new(int sym_name, ast_expr *expr);

/** Declarations **/

extern void set_parse_tree(ast_node *tree);
#ifdef DEBUG
extern void print_ast(ast_node *n);
#endif
extern void report_error(const char *fmt, ...);
extern void check_ast(ast_node *n);
extern void check_semantics(ast_node *ast);
extern void trans_ast(ast_node *ast);
extern void transtext_ast(ast_node *ast);

extern int binop_reuse(int op);

#endif
