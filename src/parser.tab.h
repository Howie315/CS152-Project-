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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    DOUBLE = 259,
    BOOLEAN = 260,
    CHAR = 261,
    ASSIGN = 262,
    ADD = 263,
    SUB = 264,
    DIV = 265,
    MUL = 266,
    MOD = 267,
    EQ = 268,
    LT = 269,
    LTE = 270,
    GT = 271,
    GTE = 272,
    NE = 273,
    FUNCTION = 274,
    BEGINSCOPE = 275,
    ENDSCOPE = 276,
    BEGINPARAM = 277,
    ENDPARAM = 278,
    BEGINBRACKET = 279,
    ENDBRACKET = 280,
    IF = 281,
    ELSE = 282,
    FOR = 283,
    WHILE = 284,
    CONTINUE = 285,
    BREAK = 286,
    TRUE = 287,
    FALSE = 288,
    RETURN = 289,
    VOID = 290,
    NOT = 291,
    AND = 292,
    OR = 293,
    SEMICOLON = 294,
    COMMA = 295,
    OUTPUT = 296,
    INPUT = 297,
    IDENTIFIER = 298,
    NUMBER = 299,
    DECIMAL = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
