This project consist of 3 files described as follows.

======================================================
** In file src:

1. c2java.l is the lexical specification for flex.
2. c2java.y is the syntactic specification for bison.
3. c2java.h declares the data structure of ast_node, type_node, scope_node, sym_node and other function prototypes which are used through out the building of the translator.
4. main.c contains the main() function which drives the whole parsing and translating process.
5. ast.c implements functions required for building the AST, type table, symbol table and scopes.
6. print_ast.c implements functions required for printing the AST in HTML format.
7. check_ast.c implements functions required for checking the AST types according to scopes and check the global attributs, etc.
8. trans_ast.c implements functions required for translating the abstract syntax tree to java code.

** report.pdf illustrates the design and implementations of the translator.
