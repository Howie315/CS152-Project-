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
    FUNCTION = 268,
    BEGINSCOPE = 269,
    ENDSCOPE = 270,
    BEGINPARAM = 271,
    ENDPARAM = 272,
    BEGINBRACKET = 273,
    ENDBRACKET = 274,
    IF = 275,
    ELSE = 276,
    FOR = 277,
    WHILE = 278,
    CONTINUE = 279,
    BREAK = 280,
    TRUE = 281,
    FALSE = 282,
    RETURN = 283,
    VOID = 284,
    NOT = 285,
    AND = 286,
    OR = 287,
    SEMICOLON = 288,
    COMMA = 289,
    OUTPUT = 290,
    INPUT = 291,
    EQ = 292,
    LT = 293,
    LTE = 294,
    GT = 295,
    GTE = 296,
    NE = 297,
    IDENTIFIER = 298,
    NUMBER = 299,
    DECIMAL = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 111 "parser.y" /* yacc.c:1909  */

  char *op_val;
  struct CodeNode *code_node;
  int int_val;
  Type *type_node;
  std::vector<std::string> *string_chain;

#line 108 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
