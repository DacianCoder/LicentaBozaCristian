/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "rule.y" /* yacc.c:339  */

	#include <stdio.h>
	#include "table.c"
	#include "interpreteur.c"
	
	#define YYDEBUG 1
	#define YYLTYPE 1
	
	int yylex(void);
	void yyerror(char*);


char* type;

#line 81 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tINT = 258,
    tACO = 259,
    tACC = 260,
    tCONST = 261,
    tADD = 262,
    tSUBTRACT = 263,
    tDIVIDE = 264,
    tMULTIPLY = 265,
    tEQUAL = 266,
    tPLUSPLUS = 267,
    tMINUSMINUS = 268,
    tIF = 269,
    tELSE = 270,
    tCHECKEQ = 271,
    tPO = 272,
    tPC = 273,
    tTAB = 274,
    tVIRGULE = 275,
    tDOLLAR = 276,
    tFINSTR = 277,
    tINTNR = 278,
    tWHILE = 279,
    tPRINTF = 280,
    tMAIN = 281,
    tVAR = 282,
    tFOR = 283,
    tSTRING = 284,
    tCHECKHIGHER = 285,
    tLESS = 286,
    tLESSEQUAL = 287,
    tMOREEQUAL = 288,
    tMINUSEQUAL = 289,
    tPLUSEQUAL = 290,
    tRETURN = 291
  };
#endif
/* Tokens.  */
#define tINT 258
#define tACO 259
#define tACC 260
#define tCONST 261
#define tADD 262
#define tSUBTRACT 263
#define tDIVIDE 264
#define tMULTIPLY 265
#define tEQUAL 266
#define tPLUSPLUS 267
#define tMINUSMINUS 268
#define tIF 269
#define tELSE 270
#define tCHECKEQ 271
#define tPO 272
#define tPC 273
#define tTAB 274
#define tVIRGULE 275
#define tDOLLAR 276
#define tFINSTR 277
#define tINTNR 278
#define tWHILE 279
#define tPRINTF 280
#define tMAIN 281
#define tVAR 282
#define tFOR 283
#define tSTRING 284
#define tCHECKHIGHER 285
#define tLESS 286
#define tLESSEQUAL 287
#define tMOREEQUAL 288
#define tMINUSEQUAL 289
#define tPLUSEQUAL 290
#define tRETURN 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "rule.y" /* yacc.c:355  */

	int nb;
	char* str;

#line 198 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 215 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    67,    70,    70,    87,    90,    91,    95,
      95,    97,    99,   115,   119,   119,   121,   122,   123,   127,
     143,   145,   146,   147,   150,   151,   152,   153,   154,   155,
     155,   157,   160,   161,   163,   164,   179,   180,   194,   195,
     198,   205,   205,   216,   205,   230,   232,   237,   257,   275,
     293,   310,   333,   336,   333,   359,   361,   364,   370,   359,
     393,   395,   397,   403,   393,   427,   427,   441,   456,   471,
     483,   494,   513,   535,   551,   567,   583,   598,   610,   618,
     625,   636,   642,   642
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tINT", "tACO", "tACC", "tCONST", "tADD",
  "tSUBTRACT", "tDIVIDE", "tMULTIPLY", "tEQUAL", "tPLUSPLUS",
  "tMINUSMINUS", "tIF", "tELSE", "tCHECKEQ", "tPO", "tPC", "tTAB",
  "tVIRGULE", "tDOLLAR", "tFINSTR", "tINTNR", "tWHILE", "tPRINTF", "tMAIN",
  "tVAR", "tFOR", "tSTRING", "tCHECKHIGHER", "tLESS", "tLESSEQUAL",
  "tMOREEQUAL", "tMINUSEQUAL", "tPLUSEQUAL", "tRETURN", "$accept", "Main",
  "$@1", "DeclFunction", "$@2", "Params", "NextParam", "Param", "FuncBody",
  "FuncInstrs", "FuncInstr", "RetVal", "Body", "Instruction",
  "Instructions", "Declaration", "Declarations", "Multideclaration",
  "Lastdeclaration", "vartype", "Print", "If", "$@3", "$@4", "$@5", "Else",
  "Condition", "While", "$@6", "$@7", "For", "$@8", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "$@15", "DeclCalc", "Calcul", "Expression",
  "Function", "$@16", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -119

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-119)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     105,  -119,  -119,    16,   -23,    -2,  -119,  -119,  -119,    21,
      23,    25,     5,    44,  -119,    61,    41,    62,     3,  -119,
      98,     5,  -119,  -119,  -119,  -119,    79,     7,    93,    89,
    -119,   107,     3,  -119,    97,  -119,  -119,  -119,  -119,  -119,
       3,   103,  -119,   101,   109,   100,    63,   106,   108,    92,
      92,  -119,   110,  -119,  -119,     4,   111,    97,  -119,     3,
     124,  -119,  -119,  -119,    92,    92,   113,    92,    64,  -119,
     117,    66,  -119,  -119,  -119,    75,    85,    31,    31,  -119,
     112,  -119,  -119,  -119,  -119,  -119,   118,    37,   119,   116,
      91,   120,    96,  -119,    92,    92,    92,    92,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,   121,  -119,    92,    92,    92,
      92,    92,  -119,  -119,  -119,   122,  -119,     5,    68,    68,
    -119,  -119,    92,    92,  -119,    44,    47,    47,    47,    47,
      47,    44,  -119,   126,   123,   125,  -119,  -119,  -119,  -119,
    -119,   127,   128,   129,    44,  -119,   134,   135,  -119,   131,
     132,  -119,  -119,    44,    44,  -119,  -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    38,    39,     0,     0,     0,     1,     2,     4,     0,
       0,     0,     8,     0,    12,     0,    10,     0,    23,     3,
       0,     0,     7,    11,    41,    52,     0,     0,     0,     0,
      30,     0,    22,    28,     0,    27,    29,    26,    25,    24,
      18,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    20,    21,    36,     0,     0,    33,    17,
       0,    15,    14,     5,     0,     0,     0,     0,     0,    78,
      77,     0,    79,    69,    70,     0,     0,     0,     0,    19,
       0,    34,    31,    32,    16,    13,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,    67,    71,
      72,    65,    56,    66,    61,    37,    42,     0,     0,     0,
       0,     0,    53,    40,    68,     0,    81,     8,    73,    74,
      75,    76,     0,     0,    35,     0,    47,    49,    48,    50,
      51,     0,    80,     0,     0,     0,    43,    54,    83,    57,
      62,    46,     0,     0,     0,    44,     0,     0,    45,     0,
       0,    58,    63,     0,     0,    59,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,  -119,  -119,    22,  -119,   130,  -119,  -119,
      94,   -30,  -118,   133,   -26,    43,    95,  -119,  -119,     0,
    -119,  -119,  -119,  -119,  -119,  -119,   -63,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    76,
      45,   -45,  -119,  -119
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     9,     4,    10,    15,    22,    16,    41,    59,
      60,    30,    19,    31,    32,    33,    56,    57,    58,    34,
      35,    36,    43,   125,   141,   145,    86,    37,    44,   131,
      38,    77,   122,   142,   153,    78,   123,   143,   154,   102,
      39,    87,    72,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       5,    71,    88,     7,    75,    76,     1,   136,     1,     2,
      61,     2,    17,   137,    62,    80,     6,    24,    46,    47,
      48,    17,    90,    92,    81,     8,   148,    25,    26,    61,
      27,    28,    14,    62,     1,   155,   156,     2,    11,    29,
      12,    49,    50,    13,    94,    95,    96,    97,    18,   118,
     119,   120,   121,   107,    94,    95,    96,    97,    27,   134,
     135,    21,   126,   127,   128,   129,   130,   108,   109,   110,
     111,    67,    91,    94,    95,    96,    97,    96,    97,    20,
      68,    68,    94,    95,    96,    97,    69,    69,    98,    23,
      70,    70,    94,    95,    96,    97,    45,    99,    94,    95,
      96,    97,    40,    94,    95,    96,    97,   100,     1,    68,
      51,     2,    53,   114,   116,    69,    52,    17,    64,    70,
     101,   101,   103,   103,    55,    63,    65,    66,    73,    85,
      74,    89,    79,    82,    93,   105,   106,   112,   113,   133,
     132,   124,   144,   115,   138,   139,   149,   140,   150,   151,
     152,    42,    83,    84,   104,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,    54
};

static const yytype_int16 yycheck[] =
{
       0,    46,    65,    26,    49,    50,     3,   125,     3,     6,
      40,     6,    12,   131,    40,    11,     0,    14,    11,    12,
      13,    21,    67,    68,    20,    27,   144,    24,    25,    59,
      27,    28,    27,    59,     3,   153,   154,     6,    17,    36,
      17,    34,    35,    18,     7,     8,     9,    10,     4,    94,
      95,    96,    97,    16,     7,     8,     9,    10,    27,   122,
     123,    20,   107,   108,   109,   110,   111,    30,    31,    32,
      33,     8,     8,     7,     8,     9,    10,     9,    10,    18,
      17,    17,     7,     8,     9,    10,    23,    23,    22,    27,
      27,    27,     7,     8,     9,    10,    17,    22,     7,     8,
       9,    10,     4,     7,     8,     9,    10,    22,     3,    17,
      17,     6,     5,    22,    18,    23,    27,   117,    17,    27,
      77,    78,    77,    78,    27,    22,    17,    27,    22,     5,
      22,    18,    22,    22,    17,    23,    18,    18,    22,   117,
      18,    20,    15,    23,    18,    22,    12,    22,    13,    18,
      18,    21,    57,    59,    78,    27,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,    38,    40,    56,     0,    26,    27,    39,
      41,    17,    17,    18,    27,    42,    44,    56,     4,    49,
      18,    20,    43,    27,    14,    24,    25,    27,    28,    36,
      48,    50,    51,    52,    56,    57,    58,    64,    67,    77,
       4,    45,    44,    59,    65,    17,    11,    12,    13,    34,
      35,    17,    27,     5,    50,    27,    53,    54,    55,    46,
      47,    48,    51,    22,    17,    17,    27,     8,    17,    23,
      27,    78,    79,    22,    22,    78,    78,    68,    72,    22,
      11,    20,    22,    53,    47,     5,    63,    78,    63,    18,
      78,     8,    78,    17,     7,     8,     9,    10,    22,    22,
      22,    52,    76,    77,    76,    23,    18,    16,    30,    31,
      32,    33,    18,    22,    22,    23,    18,    80,    78,    78,
      78,    78,    69,    73,    20,    60,    78,    78,    78,    78,
      78,    66,    18,    42,    63,    63,    49,    49,    18,    22,
      22,    61,    70,    74,    15,    62,    27,    27,    49,    12,
      13,    18,    18,    71,    75,    49,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    39,    38,    41,    40,    40,    42,    42,    43,
      43,    44,    44,    45,    46,    46,    47,    47,    47,    48,
      49,    50,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    59,    60,    61,    58,    62,    62,    63,    63,    63,
      63,    63,    65,    66,    64,    68,    69,    70,    71,    67,
      72,    73,    74,    75,    67,    76,    76,    77,    77,    77,
      77,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    80,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     0,     8,     0,     2,     0,     2,
       0,     2,     1,     3,     1,     1,     2,     1,     0,     3,
       3,     2,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     1,     2,     4,     1,     3,     1,     1,
       5,     0,     0,     0,     9,     2,     0,     3,     3,     3,
       3,     3,     0,     0,     7,     0,     0,     0,     0,    13,
       0,     0,     0,     0,    13,     1,     1,     4,     5,     3,
       3,     4,     4,     3,     3,     3,     3,     1,     1,     1,
       4,     3,     0,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 67 "rule.y" /* yacc.c:1646  */
    {prof_increment();}
#line 1407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "rule.y" /* yacc.c:1646  */
    {}
#line 1413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 70 "rule.y" /* yacc.c:1646  */
    { // hard coded 4 
			int b=4 + get_latest_inst(); // we don't execute everytime the first 4 instructions
			

			add_symbol((yyvsp[0].str), type, 0, get_curr_prof()); 
			int a= get_last_index(); 
			queue_instruction("AFC",1,b);

			queue_instruction("AFC",14,a);
			queue_instruction("ADD",14,15); 
			queue_instruction("STORE",14,1);// we store at @14 the val b 

			queue_instruction("TMPJMP",1,1); }
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 84 "rule.y" /* yacc.c:1646  */
    {
			edit_instruction(4,"JMP",get_latest_inst(),0);}
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 91 "rule.y" /* yacc.c:1646  */
    { // if there is no parameter we need to add a temp variable in wich we store the result 
		add_temporary_symbol();}
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 97 "rule.y" /* yacc.c:1646  */
    { 
			add_symbol((yyvsp[0].str), type, 0, get_curr_prof()); }
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 99 "rule.y" /* yacc.c:1646  */
    {	
			int a= find_symbol((yyvsp[0].str), get_curr_prof()); 
			add_symbol((yyvsp[0].str), type, 0, get_curr_prof());

			int b= get_last_index();

			queue_instruction("AFC",2,a);
	 		queue_instruction("LOAD", 1, 2);// we copy the value  in r1

			queue_instruction("AFC",14,b);

			queue_instruction("STORE", 14, 1); 
}
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 127 "rule.y" /* yacc.c:1646  */
    { 
					int a=find_func_symbol((yyvsp[-1].str), 0);// we know the delta now
				
					queue_instruction("AFC",14,a);//we add the delta
					queue_instruction("ADD",14,15); // we add the new ref

					queue_instruction("LOAD",1,14);//we load the data in the first register
					queue_instruction("AFC",14,1); //we set r14 to 1; so we have the first var from the function
					queue_instruction("ADD",14,15); // we add the new ref to where to store the result

					queue_instruction("STORE",14,1); // we store it at the correct @adr
					queue_instruction("RET",1,1);
}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 163 "rule.y" /* yacc.c:1646  */
    {add_symbol((yyvsp[-1].str), type, 0,get_curr_prof());}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 164 "rule.y" /* yacc.c:1646  */
    {
			int b=get_curr_prof();
		    add_symbol((yyvsp[-3].str), type, 0, b);
		// we could change add symbol to return the address
		    int a = find_symbol((yyvsp[-3].str), get_curr_prof());
		    queue_instruction("AFC", 1, (yyvsp[-1].nb));

		    queue_instruction("AFC",14,a);
		    queue_instruction("ADD",14,15); 

		    queue_instruction("STORE", 14, 1);
}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 179 "rule.y" /* yacc.c:1646  */
    {add_symbol((yyvsp[0].str), type, 0, get_curr_prof());}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 180 "rule.y" /* yacc.c:1646  */
    {

				 add_symbol((yyvsp[-2].str), type, 0, get_curr_prof()); 

				 int a = find_symbol((yyvsp[-2].str), get_curr_prof());
				 queue_instruction("AFC", 1, (yyvsp[0].nb));
		
				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15); 

				 queue_instruction("STORE", 14, 1);  
}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 194 "rule.y" /* yacc.c:1646  */
    { type = "int"; }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 195 "rule.y" /* yacc.c:1646  */
    { type = "const"; }
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 198 "rule.y" /* yacc.c:1646  */
    {
			printf("Print not supported\n"); 
 		/* queue_instruction("PRT",x,y); is printing value of r[x] and m[y]*/}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 205 "rule.y" /* yacc.c:1646  */
    {prof_increment();}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 205 "rule.y" /* yacc.c:1646  */
    {
		int a = get_last_index(); //condition-index

		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 10, 14);

		queue_instruction("TMP", 1, 1);
		(yyvsp[-4].nb) = get_latest_inst();
		delete_symbol();
		
	}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 216 "rule.y" /* yacc.c:1646  */
    {
		queue_instruction("TMP", 1, 1);
		edit_instruction((yyvsp[-6].nb), "JMPC" , get_latest_inst(), 10);
		(yyvsp[-6].nb) = get_latest_inst();
		
	}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 221 "rule.y" /* yacc.c:1646  */
    {	
		edit_instruction((yyvsp[-8].nb), "JMP" , get_latest_inst(), 10);
		delete_all_var(get_curr_prof());
		prof_decrement();
				
}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 237 "rule.y" /* yacc.c:1646  */
    {

		int a = get_last_index();
		int b = a-1;
		
		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 2, 14);

		queue_instruction("EQU", 2, 1);
	
		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 257 "rule.y" /* yacc.c:1646  */
    {
		int a = get_last_index();
		int b = a-1;

		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 2, 14);
		queue_instruction("INF", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 275 "rule.y" /* yacc.c:1646  */
    {
		int a = get_last_index();
		int b = a-1;

		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 2, 14);
		queue_instruction("SUP", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 293 "rule.y" /* yacc.c:1646  */
    {
		int a = get_last_index();
		int b = a-1;
		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 2, 14);
		queue_instruction("INFE", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 310 "rule.y" /* yacc.c:1646  */
    {
		int a = get_last_index(); // right arg
		int b = a-1;			// left arg
		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 2, 14);

		queue_instruction("SUPE", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 333 "rule.y" /* yacc.c:1646  */
    {
	prof_increment();
	(yyvsp[0].nb) = get_latest_inst(); /* Hop to here to retry condition */
	}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 336 "rule.y" /* yacc.c:1646  */
    {

	int a = get_last_index(); //condition-index after all conditions

	queue_instruction("AFC",14,a);
	queue_instruction("ADD",14,15);
	queue_instruction("LOAD", 10, 14); 

	queue_instruction("TMP", 1, 1); //we add the unedited JMPC
	(yyvsp[-2].nb) = get_latest_inst();         
	delete_symbol();

	}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 348 "rule.y" /* yacc.c:1646  */
    {
		queue_instruction("JMP", (yyvsp[-6].nb), 1);
		edit_instruction((yyvsp[-4].nb), "JMPC" , get_latest_inst(), 10);

		delete_all_var(get_curr_prof());
		prof_decrement();

	}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 359 "rule.y" /* yacc.c:1646  */
    {
			prof_increment();}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 361 "rule.y" /* yacc.c:1646  */
    {
		    	(yyvsp[-3].nb) = get_latest_inst();}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 364 "rule.y" /* yacc.c:1646  */
    {
	   		int a = get_last_index(); //condition-index after all conditions
			queue_instruction("AFC",14,a);
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 10, 14);}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 370 "rule.y" /* yacc.c:1646  */
    {
			(yyvsp[-9].nb)= find_symbol((yyvsp[-2].str), get_curr_prof());
			queue_instruction("TMP", 1, 1); //we add the unedited JMPC 
			(yyvsp[-4].nb) = get_latest_inst();         
			delete_symbol();}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 375 "rule.y" /* yacc.c:1646  */
    {	
			//we add here the code for incrementing but targeting the variable that has to be targeted
			queue_instruction("AFC",14,(yyvsp[-11].nb));
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 1, 14);

			queue_instruction("AFC", 2, 1);
			queue_instruction("ADD", 1, 2);
			queue_instruction("STORE", 14, 1); //$2
			//we updated the value of the value incremented and now we can jump to the condition
			queue_instruction("JMP", (yyvsp[-12].nb), 1);
			edit_instruction((yyvsp[-6].nb), "JMPC" , get_latest_inst(), 10);


			delete_all_var(get_curr_prof());
			prof_decrement();}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 393 "rule.y" /* yacc.c:1646  */
    {
			prof_increment();}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 395 "rule.y" /* yacc.c:1646  */
    {
		        (yyvsp[-3].nb) = get_latest_inst();}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 397 "rule.y" /* yacc.c:1646  */
    {
	   		int a = get_last_index(); //condition-index after all conditions

			queue_instruction("AFC",14,a);
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 10, 14);}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 403 "rule.y" /* yacc.c:1646  */
    {
			(yyvsp[-9].nb)= find_symbol((yyvsp[-2].str), get_curr_prof());
			queue_instruction("TMP", 1, 1); //we add the unedited JMPC 
			(yyvsp[-4].nb) = get_latest_inst();         
			delete_symbol();}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 408 "rule.y" /* yacc.c:1646  */
    {
	
			queue_instruction("AFC",14,(yyvsp[-11].nb)); // we store in r14 value of $2
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 1,14);

			queue_instruction("AFC", 2, 1);  // increment part
 			queue_instruction("SUB", 1, 2);

			queue_instruction("STORE", 14, 1); // $2

			queue_instruction("JMP", (yyvsp[-12].nb), 1);
			edit_instruction((yyvsp[-6].nb), "JMPC" , get_latest_inst(), 10);


			delete_all_var(get_curr_prof());
			prof_decrement(); }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 441 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-3].str), get_curr_prof());
				 int b = get_last_index();

				 queue_instruction("AFC",14,b);
				 queue_instruction("ADD",14,15);

				 queue_instruction("LOAD", 1, 14);
				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);

				 queue_instruction("STORE", 14, 1);

				 delete_symbol();}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 456 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-4].str), get_curr_prof());
				 int b = get_last_index();

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);
				 queue_instruction("AFC", 2, -1);
				 queue_instruction("MUL", 1, 2);

			 	 queue_instruction("AFC",14,a);
			 	 queue_instruction("ADD",14,15);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol();}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 471 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-2].str), get_curr_prof());

				 queue_instruction("AFC",14,a);
			 	 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				 queue_instruction("AFC", 2, 1);
				 queue_instruction("ADD", 1, 2);

				 queue_instruction("STORE", 14, 1);}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 483 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-2].str), get_curr_prof());
				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				 queue_instruction("AFC", 2, 1);
				 queue_instruction("SUB", 1, 2);

				 queue_instruction("STORE", 14, 1);}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 494 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-3].str), get_curr_prof());
				 int b = get_last_index();

				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				 queue_instruction("AFC",14,b);
				 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

				 queue_instruction("SUB", 1, 2);

				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol();}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 513 "rule.y" /* yacc.c:1646  */
    {
				 int a = find_symbol((yyvsp[-3].str), get_curr_prof());
				 int b = get_last_index();

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

			   	 queue_instruction("ADD", 1, 2);

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol();}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 535 "rule.y" /* yacc.c:1646  */
    {
				 int a = get_last_index();
				 int b = a-1;

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

				 queue_instruction("ADD", 1, 2);
			     queue_instruction("STORE", 14, 1);
				 delete_symbol(); }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 551 "rule.y" /* yacc.c:1646  */
    {
				 int a = get_last_index();
			 	 int b = a-1;

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
			 	 queue_instruction("LOAD", 2, 14);

				 queue_instruction("SUB", 1, 2);
				 queue_instruction("STORE", 14, 1);
			 	 delete_symbol(); }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 567 "rule.y" /* yacc.c:1646  */
    {
				 int a = get_last_index();
				 int b = a-1;

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
			 	 queue_instruction("LOAD", 2, 14);

				 queue_instruction("DIV", 1, 2);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol(); }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 583 "rule.y" /* yacc.c:1646  */
    {
		 		 int a = get_last_index();
				 int b = a-1;
				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

				 queue_instruction("MUL", 1, 2);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol(); }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 598 "rule.y" /* yacc.c:1646  */
    {
				add_temporary_symbol();
				int a=find_symbol((yyvsp[0].str), get_curr_prof());
				int b=get_last_index();
				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
	 			queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				queue_instruction("STORE", 14, 1); }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 610 "rule.y" /* yacc.c:1646  */
    {
				add_temporary_symbol();
				int a=get_last_index();
				queue_instruction("AFC", 1, (yyvsp[0].nb));

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				queue_instruction("STORE",14, 1); }
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 618 "rule.y" /* yacc.c:1646  */
    {
				
				queue_instruction("AFC",15,0);
				delete_symbol();
				prof_decrement();
			 }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 625 "rule.y" /* yacc.c:1646  */
    {
				add_temporary_symbol();
				int a= get_last_index();
				queue_instruction("AFC", 1, (yyvsp[-1].nb));
				queue_instruction("AFC", 2, -1);
				queue_instruction("MUL", 1, 2);

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				queue_instruction("STORE", 14, 1); }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 642 "rule.y" /* yacc.c:1646  */
    {
				int z = get_last_index();
				queue_instruction("AFC",15,z);
			
		prof_increment();
		}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 649 "rule.y" /* yacc.c:1646  */
    {
		int a= get_latest_inst() +1;
		int b=find_symbol((yyvsp[-4].str),0);// the var NameFUNC has stored the index needed for function CALL
		queue_instruction("CALL",b,a);}
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2140 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 654 "rule.y" /* yacc.c:1906  */



void yyerror(char *s) {
	//printf("da-te ba ca cade%d",yylloc.first_line);
	//printf("da-te ba ca cade%d",yylineno);
	fprintf(stderr, "error: %s\n", s);
	exit(1);
}

int main() {
	
	//#if YYDEBUG
	//	yydebug = 1;
	//#endif

	yyparse();

	printf("\n\n                 Setting up instructions          \n\n\n");
	printAllInst();
	printf("\n\n                   Instructions ready          \n\n\n");
	printf("\n\n----------------------------------------------------------  \n\n");
	printf("\n\n                   Starting execution           \n\n\n");
	execute_all_instructions();
	printHexInstr();

	print_table();

	for(int i=0; i<=get_last_index(); i++){

		printf("var: %s, value: %d\n", get_variable_name(i), get_memory_value(i));
	}
	
}



