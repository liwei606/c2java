/****************************************************************************

 main.c:
 Contains the main() function which drives the whole parsing process.

*****************************************************************************/

#include <stdio.h>
#include "c2java.h"
#include "c2java.tab.h"
#include <errno.h>

static ast_node *g_parse_tree;

void yyerror(char const *s)
{
    fprintf(stdout, "Error.\n");
    fprintf(stderr, "%s\n", s);
}

void set_parse_tree(ast_node *tree)
{
    g_parse_tree = tree;
}

FILE *freopen_s (const char *__restrict __filename,
		      const char *__restrict __modes,
		      FILE *__restrict __stream)
{
    FILE* result = freopen(__filename, __modes, __stream);
    if(result == NULL) {
        report_error("can not open file \"%s\" because: %s",
            __filename, strerror(errno));
        exit(1);
    }
    return result;
}

int main(int argc, char **argv)
{
    /* reserve built-in function names */
    sym("read");
    sym("write");
    
    if (argc > 1) {
        freopen_s(argv[1], "r", stdin);
        sym(argv[1]);
    }
    if (argc > 2) freopen_s(argv[2], "w", stdout);

    yyparse();

    if (g_parse_tree)
    {
        #ifdef DEBUG
            printf("Parse tree:\n");
            print_ast(g_parse_tree);
        #endif

        check_semantics(g_parse_tree);
        transtext_ast(g_parse_tree);
    }

    return 0;
}
