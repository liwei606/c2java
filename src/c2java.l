%option noyywrap nodefault yylineno
%{
#include "c2java.h"
%}

%%

"break"     { return BREAK; }
"continue"  { return CONTINUE; }
"else"      { return ELSE; }
"for"       { return FOR; }
"if"        { return IF; }
"int"       { return INT; }
"return"    { return RETURN; }
"struct"    { return STRUCT; }
"read"      { return READ; }

[a-zA-Z_][0-9a-zA-Z_]*   { yylval.i = sym(yytext); return IDENTIFIER; }

0[xX][a-fA-F0-9]+   { yylval.i = parse_int(yytext); return CONSTANT; }
0[0-7]+             { yylval.i = parse_int(yytext); return CONSTANT; }
[0-9]+              { yylval.i = parse_int(yytext); return CONSTANT; }

";"     { return ';'; }
","     { return ','; }
"("     { return '('; }
")"     { return ')'; }
"["     { return '['; }
"]"     { return ']'; }
"{"     { return '{'; }
"}"     { return '}'; }
"."     { return '.'; }
"!"     { return '!'; }
"++"    { return INC_OP; }
"--"    { return DEC_OP; }
"~"     { return '~'; }
"*"     { return '*'; }
"/"     { return '/'; }
"%"     { return '%'; }
"+"     { return '+'; }
"-"     { return '-'; }
"<<"    { return SHL_OP; }
">>"    { return SHR_OP; }
">"     { return '>'; }
">="    { return GE_OP; }
"<"     { return '<'; }
"<="    { return LE_OP; }
"=="    { return EQ_OP; }
"!="    { return NE_OP; }
"&"     { return '&'; }
"^"     { return '^'; }
"|"     { return '|'; }
"&&"    { return AND_OP; }
"||"    { return OR_OP; }
"="     { return '='; }
"+="    { return ADD_ASSIGN; }
"-="    { return SUB_ASSIGN; }
"*="    { return MUL_ASSIGN; }
"/="    { return DIV_ASSIGN; }
"%="    { return MOD_ASSIGN; }
"&="    { return AND_ASSIGN; }
"^="    { return XOR_ASSIGN; }
"|="    { return OR_ASSIGN; }
"<<="   { return SHL_ASSIGN; }
">>="   { return SHR_ASSIGN; }

[ \t\v\r\n\f]   { /* skip */ }

"//".*          { /*a C comment*/ }
"/*"(.|\n)*"*/" { /*a C comment*/ }

.       { /* ignore bad characters */ }

%%
