/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DEC_OP = 258,
     INC_OP = 259,
     SHR_OP = 260,
     SHL_OP = 261,
     GE_OP = 262,
     LE_OP = 263,
     NE_OP = 264,
     EQ_OP = 265,
     AND_OP = 266,
     OR_OP = 267,
     SHR_ASSIGN = 268,
     SHL_ASSIGN = 269,
     OR_ASSIGN = 270,
     XOR_ASSIGN = 271,
     AND_ASSIGN = 272,
     MOD_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MUL_ASSIGN = 275,
     SUB_ASSIGN = 276,
     ADD_ASSIGN = 277,
     IDENTIFIER = 278,
     CONSTANT = 279,
     INT = 280,
     STRUCT = 281,
     IF = 282,
     ELSE = 283,
     FOR = 284,
     CONTINUE = 285,
     BREAK = 286,
     RETURN = 287,
     READ = 288,
     EXTDEFS = 289,
     PARAS = 290,
     STMTS = 291,
     DEFS = 292,
     DECS = 293,
     ARGS = 294,
     INIT_ARGS = 295
   };
#endif
/* Tokens.  */
#define DEC_OP 258
#define INC_OP 259
#define SHR_OP 260
#define SHL_OP 261
#define GE_OP 262
#define LE_OP 263
#define NE_OP 264
#define EQ_OP 265
#define AND_OP 266
#define OR_OP 267
#define SHR_ASSIGN 268
#define SHL_ASSIGN 269
#define OR_ASSIGN 270
#define XOR_ASSIGN 271
#define AND_ASSIGN 272
#define MOD_ASSIGN 273
#define DIV_ASSIGN 274
#define MUL_ASSIGN 275
#define SUB_ASSIGN 276
#define ADD_ASSIGN 277
#define IDENTIFIER 278
#define CONSTANT 279
#define INT 280
#define STRUCT 281
#define IF 282
#define ELSE 283
#define FOR 284
#define CONTINUE 285
#define BREAK 286
#define RETURN 287
#define READ 288
#define EXTDEFS 289
#define PARAS 290
#define STMTS 291
#define DEFS 292
#define DECS 293
#define ARGS 294
#define INIT_ARGS 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 5 "c2java.y"
{
    int i;
    struct ast_node *n;
}
/* Line 1489 of yacc.c.  */
#line 134 "c2java.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

