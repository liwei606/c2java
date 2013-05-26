/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "c2java.y"

#include "c2java.h"


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 5 "c2java.y"
{
    int i;
    struct ast_node *n;
}
/* Line 187 of yacc.c.  */
#line 185 "c2java.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 198 "c2java.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   507

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNRULES -- Number of states.  */
#define YYNSTATES  229

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,     2,    59,    52,     2,
      44,    45,    57,    55,    46,    56,    62,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      54,    49,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,    50,    43,    61,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    16,    20,
      24,    30,    35,    38,    43,    47,    49,    53,    56,    59,
      61,    66,    68,    71,    73,    75,    77,    79,    81,    86,
      90,    94,    97,    99,   102,   108,   116,   126,   135,   144,
     152,   161,   169,   177,   184,   188,   191,   194,   196,   199,
     203,   207,   209,   213,   215,   219,   221,   225,   227,   232,
     234,   238,   242,   246,   250,   254,   258,   262,   266,   270,
     274,   278,   280,   284,   286,   290,   292,   296,   298,   302,
     304,   308,   310,   314,   318,   320,   324,   328,   332,   336,
     338,   342,   346,   348,   352,   356,   358,   362,   366,   370,
     372,   375,   378,   381,   384,   387,   389,   392,   395,   400,
     405,   409,   413,   415,   417,   421,   423,   427,   429,   433
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    -1,    65,    -1,    66,    -1,    65,    66,
      -1,    80,    -1,    67,    41,    -1,    25,    68,    74,    -1,
      67,    68,    74,    -1,    26,    23,    42,    79,    43,    -1,
      26,    42,    79,    43,    -1,    26,    23,    -1,    23,    44,
      69,    45,    -1,    23,    44,    45,    -1,    70,    -1,    69,
      46,    70,    -1,    25,    71,    -1,    67,    71,    -1,    23,
      -1,    71,    47,    24,    48,    -1,    73,    -1,    72,    73,
      -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,
      -1,    42,    79,    72,    43,    -1,    42,    79,    43,    -1,
      42,    72,    43,    -1,    42,    43,    -1,    41,    -1,    84,
      41,    -1,    27,    44,    84,    45,    73,    -1,    27,    44,
      84,    45,    73,    28,    73,    -1,    29,    44,    84,    41,
      84,    41,    84,    45,    73,    -1,    29,    44,    84,    41,
      84,    41,    45,    73,    -1,    29,    44,    84,    41,    41,
      84,    45,    73,    -1,    29,    44,    84,    41,    41,    45,
      73,    -1,    29,    44,    41,    84,    41,    84,    45,    73,
      -1,    29,    44,    41,    84,    41,    45,    73,    -1,    29,
      44,    41,    41,    84,    45,    73,    -1,    29,    44,    41,
      41,    45,    73,    -1,    32,    84,    41,    -1,    30,    41,
      -1,    31,    41,    -1,    80,    -1,    79,    80,    -1,    25,
      81,    41,    -1,    67,    81,    41,    -1,    82,    -1,    81,
      46,    82,    -1,    71,    -1,    71,    49,    83,    -1,    84,
      -1,    42,   100,    43,    -1,    85,    -1,    33,    44,    84,
      45,    -1,    86,    -1,    96,    49,    85,    -1,    96,    22,
      85,    -1,    96,    21,    85,    -1,    96,    20,    85,    -1,
      96,    19,    85,    -1,    96,    18,    85,    -1,    96,    17,
      85,    -1,    96,    16,    85,    -1,    96,    15,    85,    -1,
      96,    14,    85,    -1,    96,    13,    85,    -1,    87,    -1,
      86,    12,    87,    -1,    88,    -1,    87,    11,    88,    -1,
      89,    -1,    88,    50,    89,    -1,    90,    -1,    89,    51,
      90,    -1,    91,    -1,    90,    52,    91,    -1,    92,    -1,
      91,    10,    92,    -1,    91,     9,    92,    -1,    93,    -1,
      92,    53,    93,    -1,    92,     7,    93,    -1,    92,    54,
      93,    -1,    92,     8,    93,    -1,    94,    -1,    93,     6,
      94,    -1,    93,     5,    94,    -1,    95,    -1,    94,    55,
      95,    -1,    94,    56,    95,    -1,    96,    -1,    95,    57,
      96,    -1,    95,    58,    96,    -1,    95,    59,    96,    -1,
      97,    -1,     4,    96,    -1,     3,    96,    -1,    56,    96,
      -1,    60,    96,    -1,    61,    96,    -1,    98,    -1,    97,
       4,    -1,    97,     3,    -1,    97,    47,    84,    48,    -1,
      97,    44,    99,    45,    -1,    97,    44,    45,    -1,    97,
      62,    23,    -1,    23,    -1,    24,    -1,    44,    84,    45,
      -1,    84,    -1,    99,    46,    84,    -1,   101,    -1,   100,
      46,   101,    -1,    84,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    35,    35,    36,    40,    41,    45,    46,    47,    48,
      52,    53,    54,    58,    59,    63,    64,    68,    69,    73,
      74,    78,    79,    83,    84,    85,    86,    87,    91,    92,
      93,    94,    95,    99,   103,   104,   108,   109,   110,   111,
     112,   113,   114,   115,   119,   120,   121,   125,   126,   130,
     131,   135,   136,   140,   141,   145,   146,   150,   151,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   170,   171,   175,   176,   180,   181,   185,   186,   190,
     191,   195,   196,   197,   201,   202,   203,   204,   205,   209,
     210,   211,   215,   216,   217,   221,   222,   223,   224,   228,
     229,   230,   231,   232,   233,   237,   238,   239,   240,   241,
     242,   243,   247,   248,   249,   253,   254,   258,   259,   263
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEC_OP", "INC_OP", "SHR_OP", "SHL_OP",
  "GE_OP", "LE_OP", "NE_OP", "EQ_OP", "AND_OP", "OR_OP", "SHR_ASSIGN",
  "SHL_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "AND_ASSIGN", "MOD_ASSIGN",
  "DIV_ASSIGN", "MUL_ASSIGN", "SUB_ASSIGN", "ADD_ASSIGN", "IDENTIFIER",
  "CONSTANT", "INT", "STRUCT", "IF", "ELSE", "FOR", "CONTINUE", "BREAK",
  "RETURN", "READ", "EXTDEFS", "PARAS", "STMTS", "DEFS", "DECS", "ARGS",
  "INIT_ARGS", "';'", "'{'", "'}'", "'('", "')'", "','", "'['", "']'",
  "'='", "'|'", "'^'", "'&'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "'~'", "'.'", "$accept", "program", "extdefs", "extdef",
  "stspec", "func", "paras", "para", "var", "stmts", "stmt",
  "compound_stmt", "expr_stmt", "selection_stmt", "iteration_stmt",
  "jump_stmt", "defs", "def", "decs", "dec", "init", "expr", "assignment",
  "logical_or", "logical_and", "bit_or", "bit_xor", "bit_and", "equality",
  "relational", "shift", "additive", "multi", "unary", "postfix",
  "primary", "args", "init_args", "init_arg", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    59,   123,   125,    40,    41,    44,    91,    93,    61,
     124,    94,    38,    62,    60,    43,    45,    42,    47,    37,
      33,   126,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    74,    75,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    91,    91,    92,    92,    92,    92,    92,    93,
      93,    93,    94,    94,    94,    95,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    98,    98,    98,    99,    99,   100,   100,   101
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     2,     3,     3,
       5,     4,     2,     4,     3,     1,     3,     2,     2,     1,
       4,     1,     2,     1,     1,     1,     1,     1,     4,     3,
       3,     2,     1,     2,     5,     7,     9,     8,     8,     7,
       8,     7,     7,     6,     3,     2,     2,     1,     2,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     4,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     2,     2,     1,     2,     2,     4,     4,
       3,     3,     1,     1,     3,     1,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     3,     4,     0,     6,    19,     0,
      53,     0,    51,    12,     0,     1,     5,     7,     0,     0,
       0,    32,     0,     8,     0,     0,    49,     0,     0,     0,
       0,     0,    47,     9,    50,     0,    14,     0,     0,    15,
       0,     0,   112,   113,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,    21,    23,    24,    25,
      26,    27,     0,     0,    57,    59,    71,    73,    75,    77,
      79,    81,    84,    89,    92,    95,    99,   105,     0,     0,
      54,    55,    19,    52,     0,    11,    48,    17,    18,    13,
       0,   101,   100,     0,     0,    45,    46,     0,     0,     0,
     102,   103,   104,    30,    22,    29,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,   106,     0,
       0,     0,    20,   119,     0,   117,    10,    16,     0,     0,
       0,    44,     0,   114,    28,    72,    95,    74,    76,    78,
      80,    83,    82,    86,    88,    85,    87,    91,    90,    93,
      94,    96,    97,    98,    70,    69,    68,    67,    66,    65,
      64,    63,    62,    61,    60,   110,   115,     0,     0,   111,
      56,     0,     0,     0,     0,     0,    58,   109,     0,   108,
     118,    34,     0,     0,     0,     0,     0,   116,     0,    43,
       0,     0,     0,     0,     0,     0,    35,    42,    41,     0,
      39,     0,     0,     0,    40,    38,    37,     0,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    30,     9,    38,    39,    10,    55,
      56,    57,    58,    59,    60,    61,    31,    32,    11,    12,
      80,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,   187,   144,   145
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -51
static const yytype_int16 yypact[] =
{
      38,   -19,   -11,    32,    38,   -51,     1,   -51,     4,    30,
     -28,    16,   -51,     9,    68,   -51,   -51,   -51,    30,    20,
     -15,   -51,   171,   -51,    52,   296,   -51,    97,    68,    97,
      97,   -10,   -51,   -51,   -51,    97,   -51,    97,    77,   -51,
     205,   205,   -51,   -51,    95,    99,   105,   107,   132,   103,
     -51,   132,   205,   205,   205,   248,   -51,   -51,   -51,   -51,
     -51,   -51,   213,   108,   -51,    33,   139,   101,   102,   110,
     116,     6,   122,    74,    59,    64,     5,   -51,   109,   132,
     -51,   -51,   -51,   -51,    10,   -51,   -51,   112,   112,   -51,
     106,   -51,   -51,   132,    14,   -51,   -51,   113,   132,   119,
     -51,   -51,   -51,   -51,   -51,   -51,   283,   -51,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   -51,   -51,   331,
     132,   144,   -51,   -51,     0,   -51,   -51,   -51,   133,   362,
     140,   -51,   137,   -51,   -51,   139,   -51,   101,   102,   110,
     116,     6,     6,   122,   122,   122,   122,    74,    74,    59,
      59,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,    88,   135,   -51,
     -51,   132,   318,   365,   143,   396,   -51,   -51,   132,   -51,
     -51,   157,   318,   141,   409,   427,   146,   -51,   318,   -51,
     318,   318,   154,   318,   160,   435,   -51,   -51,   -51,   318,
     -51,   318,   318,   161,   -51,   -51,   -51,   318,   -51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,   -51,   185,     2,   201,   -51,   120,    84,   129,
     -50,    11,   -51,   -51,   -51,   -51,    22,     3,    -5,   184,
     -51,   -25,   371,   -51,   111,   114,   115,   123,   118,    24,
     -27,    21,    23,   -13,   -51,   -51,   -51,   -51,    27
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      81,    19,     6,     7,     8,   104,     6,     7,   137,   138,
      35,     2,    13,   115,   116,    29,     2,    40,    41,    24,
      23,    25,    37,    97,     8,    19,    99,    91,    92,    33,
      36,    14,    15,    85,    86,    29,     2,    42,    43,   100,
     101,   102,    17,   190,    62,   108,   191,    49,    20,   139,
      84,    28,   140,   146,   143,   149,   104,    26,    51,   117,
     118,    34,    27,     1,     2,    86,    27,   141,   148,   150,
      52,    21,    22,   152,    53,    54,    78,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    86,   163,   164,
     165,   166,    37,    29,     2,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     171,   172,   173,   136,   186,   188,   123,   124,   125,    87,
      82,    88,    89,    90,   194,   113,   114,   119,   120,   121,
     122,    35,     2,   197,   198,    40,    41,   161,   162,    93,
     167,   168,   201,    94,   169,   170,    95,    98,    96,   107,
     109,   110,   209,   111,   151,    42,    43,   142,   216,    24,
     217,   218,   112,   220,   153,    49,   143,   189,   203,   224,
     206,   225,   226,   207,    40,    41,    51,   228,   192,   212,
     214,   195,   196,   199,   204,   208,   210,   215,    52,    16,
     223,   106,    53,    54,    42,    43,    29,     2,    44,   219,
      45,    46,    47,    48,    49,   221,   227,    18,    40,    41,
     147,    83,    21,    22,    50,    51,    40,    41,   200,   155,
       0,     0,     0,   157,     0,   158,     0,    52,    42,    43,
     160,    53,    54,     0,   159,     0,    42,    43,    29,     2,
      44,     0,    45,    46,    47,    48,    49,     0,     0,    51,
       0,    40,    41,     0,    21,    22,   105,    51,     0,     0,
       0,    52,     0,     0,     0,    53,    54,     0,     0,    52,
       0,    42,    43,    53,    54,    44,     0,    45,    46,    47,
      48,    49,     0,     0,     0,     0,    40,    41,     0,    21,
      22,   103,    51,     0,     0,     0,     0,     0,     0,    40,
      41,     0,     0,     0,    52,     0,    42,    43,    53,    54,
      44,     0,    45,    46,    47,    48,    49,     0,     0,    42,
      43,    40,    41,     0,    21,    22,   154,    51,     0,    49,
       0,     0,     0,     0,    40,    41,     0,     0,    79,    52,
      51,    42,    43,    53,    54,    44,     0,    45,    46,    47,
      48,    49,    52,     0,    42,    43,    53,    54,     0,    21,
      22,     0,    51,     0,    49,    40,    41,     0,    40,    41,
       0,     0,     0,     0,    52,    51,   185,     0,    53,    54,
       0,     0,     0,     0,     0,    42,    43,    52,    42,    43,
       0,    53,    54,     0,     0,    49,     0,     0,    49,    40,
      41,     0,     0,   193,     0,     0,    51,     0,     0,    51,
     202,     0,    40,    41,     0,     0,     0,     0,    52,    42,
      43,    52,    53,    54,     0,    53,    54,     0,     0,    49,
      40,    41,    42,    43,     0,     0,     0,   205,    40,    41,
      51,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      42,    43,    52,    51,   211,     0,    53,    54,    42,    43,
      49,     0,     0,     0,     0,    52,     0,     0,    49,    53,
      54,    51,   213,     0,     0,     0,     0,     0,     0,    51,
     222,     0,     0,    52,     0,     0,     0,    53,    54,     0,
       0,    52,     0,     0,     0,    53,    54,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184
};

static const yytype_int16 yycheck[] =
{
      25,     6,     0,     0,    23,    55,     4,     4,     3,     4,
      25,    26,    23,     7,     8,    25,    26,     3,     4,    47,
       9,    49,    20,    48,    23,    30,    51,    40,    41,    18,
      45,    42,     0,    43,    31,    25,    26,    23,    24,    52,
      53,    54,    41,    43,    22,    12,    46,    33,    44,    44,
      28,    42,    47,    43,    79,    41,   106,    41,    44,    53,
      54,    41,    46,    25,    26,    62,    46,    62,    93,    94,
      56,    41,    42,    98,    60,    61,    24,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    84,   115,   116,
     117,   118,    90,    25,    26,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    49,   139,   140,    57,    58,    59,    35,
      23,    37,    45,    46,   149,     9,    10,     5,     6,    55,
      56,    25,    26,    45,    46,     3,     4,   113,   114,    44,
     119,   120,   192,    44,   121,   122,    41,    44,    41,    41,
      11,    50,   202,    51,    41,    23,    24,    48,   208,    47,
     210,   211,    52,   213,    45,    33,   191,    23,   193,   219,
     195,   221,   222,   198,     3,     4,    44,   227,    45,   204,
     205,    41,    45,    48,    41,    28,    45,    41,    56,     4,
     215,    62,    60,    61,    23,    24,    25,    26,    27,    45,
      29,    30,    31,    32,    33,    45,    45,     6,     3,     4,
      90,    27,    41,    42,    43,    44,     3,     4,   191,   108,
      -1,    -1,    -1,   109,    -1,   110,    -1,    56,    23,    24,
     112,    60,    61,    -1,   111,    -1,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    -1,    -1,    44,
      -1,     3,     4,    -1,    41,    42,    43,    44,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,    56,
      -1,    23,    24,    60,    61,    27,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,     3,     4,    -1,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    56,    -1,    23,    24,    60,    61,
      27,    -1,    29,    30,    31,    32,    33,    -1,    -1,    23,
      24,     3,     4,    -1,    41,    42,    43,    44,    -1,    33,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    42,    56,
      44,    23,    24,    60,    61,    27,    -1,    29,    30,    31,
      32,    33,    56,    -1,    23,    24,    60,    61,    -1,    41,
      42,    -1,    44,    -1,    33,     3,     4,    -1,     3,     4,
      -1,    -1,    -1,    -1,    56,    44,    45,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    23,    24,    56,    23,    24,
      -1,    60,    61,    -1,    -1,    33,    -1,    -1,    33,     3,
       4,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    44,
      45,    -1,     3,     4,    -1,    -1,    -1,    -1,    56,    23,
      24,    56,    60,    61,    -1,    60,    61,    -1,    -1,    33,
       3,     4,    23,    24,    -1,    -1,    -1,    41,     3,     4,
      44,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    56,    44,    45,    -1,    60,    61,    23,    24,
      33,    -1,    -1,    -1,    -1,    56,    -1,    -1,    33,    60,
      61,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    56,    -1,    -1,    -1,    60,    61,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    26,    64,    65,    66,    67,    80,    23,    68,
      71,    81,    82,    23,    42,     0,    66,    41,    68,    81,
      44,    41,    42,    74,    47,    49,    41,    46,    42,    25,
      67,    79,    80,    74,    41,    25,    45,    67,    69,    70,
       3,     4,    23,    24,    27,    29,    30,    31,    32,    33,
      43,    44,    56,    60,    61,    72,    73,    74,    75,    76,
      77,    78,    79,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    24,    42,
      83,    84,    23,    82,    79,    43,    80,    71,    71,    45,
      46,    96,    96,    44,    44,    41,    41,    84,    44,    84,
      96,    96,    96,    43,    73,    43,    72,    41,    12,    11,
      50,    51,    52,     9,    10,     7,     8,    53,    54,     5,
       6,    55,    56,    57,    58,    59,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    49,     3,     4,    44,
      47,    62,    48,    84,   100,   101,    43,    70,    84,    41,
      84,    41,    84,    45,    43,    87,    96,    88,    89,    90,
      91,    92,    92,    93,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    45,    84,    99,    84,    23,
      43,    46,    45,    41,    84,    41,    45,    45,    46,    48,
     101,    73,    45,    84,    41,    41,    84,    84,    28,    73,
      45,    45,    84,    45,    84,    41,    73,    73,    73,    45,
      73,    45,    45,    84,    73,    73,    73,    45,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 35 "c2java.y"
    { set_parse_tree((yyval.n) = NULL); ;}
    break;

  case 3:
#line 36 "c2java.y"
    { set_parse_tree((yyval.n) = (yyvsp[(1) - (1)].n)); ;}
    break;

  case 4:
#line 40 "c2java.y"
    { (yyval.n) = list_new(EXTDEFS, (yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 5:
#line 41 "c2java.y"
    { list_append((yyval.n) = (yyvsp[(1) - (2)].n), list_new(EXTDEFS, (yyvsp[(2) - (2)].n), NULL)); ;}
    break;

  case 6:
#line 45 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 7:
#line 46 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (2)].n); ;}
    break;

  case 8:
#line 47 "c2java.y"
    { (yyval.n) = funcdef_new(int_type(), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 9:
#line 48 "c2java.y"
    { (yyval.n) = funcdef_new(struct_type((yyvsp[(1) - (3)].n)), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 10:
#line 52 "c2java.y"
    { (yyval.n) = stdef_new((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].n)); ;}
    break;

  case 11:
#line 53 "c2java.y"
    { (yyval.n) = stdef_new(-1, (yyvsp[(3) - (4)].n)); ;}
    break;

  case 12:
#line 54 "c2java.y"
    { (yyval.n) = stdef_new((yyvsp[(2) - (2)].i), NULL); ;}
    break;

  case 13:
#line 58 "c2java.y"
    { (yyval.n) = funchead_new((yyvsp[(1) - (4)].i), (yyvsp[(3) - (4)].n)); ;}
    break;

  case 14:
#line 59 "c2java.y"
    { (yyval.n) = funchead_new((yyvsp[(1) - (3)].i), NULL); ;}
    break;

  case 15:
#line 63 "c2java.y"
    { (yyval.n) = list_new(PARAS, (yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 16:
#line 64 "c2java.y"
    { list_append((yyval.n) = (yyvsp[(1) - (3)].n), list_new(PARAS, (yyvsp[(3) - (3)].n), NULL)); ;}
    break;

  case 17:
#line 68 "c2java.y"
    { (yyval.n) = para_new(int_type(), (yyvsp[(2) - (2)].n)); ;}
    break;

  case 18:
#line 69 "c2java.y"
    { (yyval.n) = para_new(struct_type((yyvsp[(1) - (2)].n)), (yyvsp[(2) - (2)].n)); ;}
    break;

  case 19:
#line 73 "c2java.y"
    { (yyval.n) = var_new((yyvsp[(1) - (1)].i)); ;}
    break;

  case 20:
#line 74 "c2java.y"
    { (yyval.n) = subvar_new((yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].i)); ;}
    break;

  case 21:
#line 78 "c2java.y"
    { (yyval.n) = list_new(STMTS, (yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 22:
#line 79 "c2java.y"
    { list_append((yyval.n) = (yyvsp[(1) - (2)].n), list_new(STMTS, (yyvsp[(2) - (2)].n), NULL)); ;}
    break;

  case 23:
#line 83 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 24:
#line 84 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 25:
#line 85 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 26:
#line 86 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 27:
#line 87 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 28:
#line 91 "c2java.y"
    { (yyval.n) = compound_stmt_new((yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n)); ;}
    break;

  case 29:
#line 92 "c2java.y"
    { (yyval.n) = compound_stmt_new((yyvsp[(2) - (3)].n), NULL); ;}
    break;

  case 30:
#line 93 "c2java.y"
    { (yyval.n) = compound_stmt_new(NULL, (yyvsp[(2) - (3)].n)); ;}
    break;

  case 31:
#line 94 "c2java.y"
    { (yyval.n) = compound_stmt_new(NULL, NULL); ;}
    break;

  case 32:
#line 95 "c2java.y"
    { (yyval.n) = compound_stmt_new(NULL, NULL); ;}
    break;

  case 33:
#line 99 "c2java.y"
    { (yyval.n) = expr_stmt_new((yyvsp[(1) - (2)].n)); ;}
    break;

  case 34:
#line 103 "c2java.y"
    { (yyval.n) = if_stmt_new((yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n), NULL); ;}
    break;

  case 35:
#line 104 "c2java.y"
    { (yyval.n) = if_stmt_new((yyvsp[(3) - (7)].n), (yyvsp[(5) - (7)].n), (yyvsp[(7) - (7)].n)); ;}
    break;

  case 36:
#line 108 "c2java.y"
    { (yyval.n) = for_stmt_new((yyvsp[(3) - (9)].n),   (yyvsp[(5) - (9)].n),   (yyvsp[(7) - (9)].n),   (yyvsp[(9) - (9)].n)); ;}
    break;

  case 37:
#line 109 "c2java.y"
    { (yyval.n) = for_stmt_new((yyvsp[(3) - (8)].n),   (yyvsp[(5) - (8)].n),   NULL, (yyvsp[(8) - (8)].n)); ;}
    break;

  case 38:
#line 110 "c2java.y"
    { (yyval.n) = for_stmt_new((yyvsp[(3) - (8)].n),   NULL, (yyvsp[(6) - (8)].n),   (yyvsp[(8) - (8)].n)); ;}
    break;

  case 39:
#line 111 "c2java.y"
    { (yyval.n) = for_stmt_new((yyvsp[(3) - (7)].n),   NULL, NULL, (yyvsp[(7) - (7)].n)); ;}
    break;

  case 40:
#line 112 "c2java.y"
    { (yyval.n) = for_stmt_new(NULL, (yyvsp[(4) - (8)].n),   (yyvsp[(6) - (8)].n),   (yyvsp[(8) - (8)].n)); ;}
    break;

  case 41:
#line 113 "c2java.y"
    { (yyval.n) = for_stmt_new(NULL, (yyvsp[(4) - (7)].n),   NULL, (yyvsp[(7) - (7)].n)); ;}
    break;

  case 42:
#line 114 "c2java.y"
    { (yyval.n) = for_stmt_new(NULL, NULL, (yyvsp[(5) - (7)].n),   (yyvsp[(7) - (7)].n)); ;}
    break;

  case 43:
#line 115 "c2java.y"
    { (yyval.n) = for_stmt_new(NULL, NULL, NULL, (yyvsp[(6) - (6)].n)); ;}
    break;

  case 44:
#line 119 "c2java.y"
    { (yyval.n) = return_stmt_new((yyvsp[(2) - (3)].n)); ;}
    break;

  case 45:
#line 120 "c2java.y"
    { (yyval.n) = continue_stmt_new(); ;}
    break;

  case 46:
#line 121 "c2java.y"
    { (yyval.n) = break_stmt_new(); ;}
    break;

  case 47:
#line 125 "c2java.y"
    { (yyval.n) = list_new(DEFS, (yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 48:
#line 126 "c2java.y"
    { list_append((yyval.n) = (yyvsp[(1) - (2)].n), list_new(DEFS, (yyvsp[(2) - (2)].n), NULL)); ;}
    break;

  case 49:
#line 130 "c2java.y"
    { (yyval.n) = def_new(int_type(), (yyvsp[(2) - (3)].n)); ;}
    break;

  case 50:
#line 131 "c2java.y"
    { (yyval.n) = def_new(struct_type((yyvsp[(1) - (3)].n)), (yyvsp[(2) - (3)].n)); ;}
    break;

  case 51:
#line 135 "c2java.y"
    { (yyval.n) = list_new(DECS, (yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 52:
#line 136 "c2java.y"
    { list_append((yyval.n) = (yyvsp[(1) - (3)].n), list_new(DECS, (yyvsp[(3) - (3)].n), NULL)); ;}
    break;

  case 53:
#line 140 "c2java.y"
    { (yyval.n) = dec_new((yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 54:
#line 141 "c2java.y"
    { (yyval.n) = dec_new((yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 55:
#line 145 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 56:
#line 146 "c2java.y"
    { (yyval.n) = (yyvsp[(2) - (3)].n); ;}
    break;

  case 57:
#line 150 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 58:
#line 151 "c2java.y"
    { (yyval.n) = binop_new('=', (yyvsp[(3) - (4)].n), func_call_new(id_new(sym("read")), NULL)); ;}
    break;

  case 59:
#line 155 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 60:
#line 156 "c2java.y"
    { (yyval.n) = binop_new('=', (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 61:
#line 157 "c2java.y"
    { (yyval.n) = binop_new(ADD_ASSIGN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 62:
#line 158 "c2java.y"
    { (yyval.n) = binop_new(SUB_ASSIGN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 63:
#line 159 "c2java.y"
    { (yyval.n) = binop_new(MUL_ASSIGN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 64:
#line 160 "c2java.y"
    { (yyval.n) = binop_new(DIV_ASSIGN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 65:
#line 161 "c2java.y"
    { (yyval.n) = binop_new(MOD_ASSIGN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 66:
#line 162 "c2java.y"
    { (yyval.n) = binop_new(AND_ASSIGN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 67:
#line 163 "c2java.y"
    { (yyval.n) = binop_new(XOR_ASSIGN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 68:
#line 164 "c2java.y"
    { (yyval.n) = binop_new(OR_ASSIGN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 69:
#line 165 "c2java.y"
    { (yyval.n) = binop_new(SHL_ASSIGN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 70:
#line 166 "c2java.y"
    { (yyval.n) = binop_new(SHR_ASSIGN, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 71:
#line 170 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 72:
#line 171 "c2java.y"
    { (yyval.n) = binop_new(OR_OP, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 73:
#line 175 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 74:
#line 176 "c2java.y"
    { (yyval.n) = binop_new(AND_OP, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 75:
#line 180 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 76:
#line 181 "c2java.y"
    { (yyval.n) = binop_new('|', (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 77:
#line 185 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 78:
#line 186 "c2java.y"
    { (yyval.n) = binop_new('^', (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 79:
#line 190 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 80:
#line 191 "c2java.y"
    { (yyval.n) = binop_new('&', (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 81:
#line 195 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 82:
#line 196 "c2java.y"
    { (yyval.n) = binop_new(EQ_OP, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 83:
#line 197 "c2java.y"
    { (yyval.n) = binop_new(NE_OP, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 84:
#line 201 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 85:
#line 202 "c2java.y"
    { (yyval.n) = binop_new('>', (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 86:
#line 203 "c2java.y"
    { (yyval.n) = binop_new(GE_OP, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 87:
#line 204 "c2java.y"
    { (yyval.n) = binop_new('<', (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 88:
#line 205 "c2java.y"
    { (yyval.n) = binop_new(LE_OP, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 89:
#line 209 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 90:
#line 210 "c2java.y"
    { (yyval.n) = binop_new(SHL_OP, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 91:
#line 211 "c2java.y"
    { (yyval.n) = binop_new(SHR_OP, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 92:
#line 215 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 93:
#line 216 "c2java.y"
    { (yyval.n) = binop_new('+', (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 94:
#line 217 "c2java.y"
    { (yyval.n) = binop_new('-', (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 95:
#line 221 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 96:
#line 222 "c2java.y"
    { (yyval.n) = binop_new('*', (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 97:
#line 223 "c2java.y"
    { (yyval.n) = binop_new('/', (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 98:
#line 224 "c2java.y"
    { (yyval.n) = binop_new('%', (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); ;}
    break;

  case 99:
#line 228 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 100:
#line 229 "c2java.y"
    { (yyval.n) = prefix_new(INC_OP, (yyvsp[(2) - (2)].n)); ;}
    break;

  case 101:
#line 230 "c2java.y"
    { (yyval.n) = prefix_new(DEC_OP, (yyvsp[(2) - (2)].n)); ;}
    break;

  case 102:
#line 231 "c2java.y"
    { (yyval.n) = prefix_new('-', (yyvsp[(2) - (2)].n)); ;}
    break;

  case 103:
#line 232 "c2java.y"
    { (yyval.n) = prefix_new('!', (yyvsp[(2) - (2)].n)); ;}
    break;

  case 104:
#line 233 "c2java.y"
    { (yyval.n) = prefix_new('~', (yyvsp[(2) - (2)].n)); ;}
    break;

  case 105:
#line 237 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 106:
#line 238 "c2java.y"
    { (yyval.n) = postfix_new(INC_OP, (yyvsp[(1) - (2)].n)); ;}
    break;

  case 107:
#line 239 "c2java.y"
    { (yyval.n) = postfix_new(DEC_OP, (yyvsp[(1) - (2)].n)); ;}
    break;

  case 108:
#line 240 "c2java.y"
    { (yyval.n) = indexing_new((yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); ;}
    break;

  case 109:
#line 241 "c2java.y"
    { (yyval.n) = func_call_new((yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); ;}
    break;

  case 110:
#line 242 "c2java.y"
    { (yyval.n) = func_call_new((yyvsp[(1) - (3)].n), NULL); ;}
    break;

  case 111:
#line 243 "c2java.y"
    { (yyval.n) = member_new((yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].i)); ;}
    break;

  case 112:
#line 247 "c2java.y"
    { (yyval.n) = id_new((yyvsp[(1) - (1)].i)); ;}
    break;

  case 113:
#line 248 "c2java.y"
    { (yyval.n) = const_new((yyvsp[(1) - (1)].i)); ;}
    break;

  case 114:
#line 249 "c2java.y"
    { (yyval.n) = (yyvsp[(2) - (3)].n); ;}
    break;

  case 115:
#line 253 "c2java.y"
    { (yyval.n) = list_new(ARGS, (yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 116:
#line 254 "c2java.y"
    { list_append((yyval.n) = (yyvsp[(1) - (3)].n), list_new(ARGS, (yyvsp[(3) - (3)].n), NULL)); ;}
    break;

  case 117:
#line 258 "c2java.y"
    { (yyval.n) = list_new(INIT_ARGS, (yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 118:
#line 259 "c2java.y"
    { list_append((yyval.n) = (yyvsp[(1) - (3)].n), list_new(INIT_ARGS, (yyvsp[(3) - (3)].n), NULL)); ;}
    break;

  case 119:
#line 263 "c2java.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2249 "c2java.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



