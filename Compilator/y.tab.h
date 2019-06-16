/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 15 "rule.y" /* yacc.c:1909  */

	int nb;
	char* str;

#line 131 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
