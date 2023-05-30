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
#line 1 "parser.y" /* yacc.c:339  */

#include "codenode.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <set>

extern int yylex();
void yyerror(const char *s);
extern int lineCount;

char *identToken;
int numberToken;
int  count_names = 0;
int count_params = 0;

bool main_exists = false;
bool insideLoop = false;
bool insideIfElse = false;
enum Type { Integer, Array, Boolean, Double, Character};

/*

      Integer = 1
      Array = 5
      Boolean = 2
      Double = 3
      Character = 4

*/

struct Symbol {
  std::string name;
  int type;
};

struct Function {
  std::string name;
  std::vector<Symbol> declarations;
};

std::vector <Function> symbol_table;

bool FindFunction(std::vector<Function> vec, std::string name) {
      for (unsigned i = 0; i < vec.size(); i++) {
            if (name == vec[i].name) {
                  return true;
            }
      }
      return false;
}

std::vector<std::string> reservedKeywords;

bool CheckReservedKeywords(std::string name) {
      for (unsigned i = 0; i < reservedKeywords.size(); i++) {
            if (reservedKeywords[i] == name) {
                  return false;
            }
      }
      return true;
}

std::string generateLabel() {
    static int labelCount = 0;
    std::ostringstream oss;
    oss << ":label" << labelCount++;
    return oss.str();
}

std::vector<std::string> breakStack;
std::vector<std::string> continueStack;

// remember that Bison is a bottom up parser: that it parses leaf nodes first before
// parsing the parent nodes. So control flow begins at the leaf grammar nodes
// and propagates up to the parents.
Function *get_function() {
  int last = symbol_table.size()-1;
  if (last < 0) {
    printf("***Error. Attempt to call get_function with an empty symbol table\n");
    printf("Create a 'Function' object using 'add_function_to_symbol_table' before\n");
    printf("calling 'find' or 'add_variable_to_symbol_table'");
  }
  return &symbol_table[last];
}

// find a particular variable using the symbol table.
// grab the most recent function, and linear search to
// find the symbol you are looking for.
// you may want to extend "find" to handle different types of "Integer" vs "Array"
bool find(std::string &value, int t) {
  Function *f = get_function();
  for(int i=0; i < f->declarations.size(); i++) {
    Symbol *s = &f->declarations[i];
    if (s->name == value && s->type == t) {
      return true;
    }
  }
  return false;
}

//  Same as above, but only checks for name
bool find_ambiguous(std::string &value)
{
Function *f = get_function();
  for(int i=0; i < f->declarations.size(); i++) {
    Symbol *s = &f->declarations[i];
    if (s->name == value) {
      return true;
    }
  }
  return false;
}

// when you see a function declaration inside the grammar, add
// the function name to the symbol table
void add_function_to_symbol_table(std::string &value) {
  Function f; 
  f.name = value; 
  symbol_table.push_back(f);
}

// when you see a symbol declaration inside the grammar, add
// the symbol name as well as some type information to the symbol table
void add_variable_to_symbol_table(std::string &value, int t) {
  Symbol s;
  s.name = value;
  s.type = t;
  Function *f = get_function();
  f->declarations.push_back(s);
}

template <typename T>
std::string to_string(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string create_temp()
{
      static int num = 0;
      std::string value = "_temp" + to_string(num);
      num += 1;
      return value;
}

bool check_side()
{
      static bool side = true;
      side != side;
      return side;
}

std::string decl_temp_code(std::string &temp)
{
      return std::string(". ") + temp + std::string("\n");
}

void print_symbol_table(void) {
  printf("symbol table:\n");
  printf("--------------------\n");
  for(int i=0; i<symbol_table.size(); i++) {
    printf("function: %s\n", symbol_table[i].name.c_str());
    for(int j=0; j<symbol_table[i].declarations.size(); j++) {
      printf("  locals: %s\n", symbol_table[i].declarations[j].name.c_str());
    }
  }
  printf("--------------------\n");
}


#line 240 "parser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
    DOUBLE = 258,
    BOOLEAN = 259,
    CHAR = 260,
    ASSIGN = 261,
    ADD = 262,
    SUB = 263,
    DIV = 264,
    MUL = 265,
    MOD = 266,
    EQ = 267,
    LT = 268,
    LTE = 269,
    GT = 270,
    GTE = 271,
    NE = 272,
    FUNCTION = 273,
    BEGINSCOPE = 274,
    ENDSCOPE = 275,
    BEGINPARAM = 276,
    ENDPARAM = 277,
    BEGINBRACKET = 278,
    ENDBRACKET = 279,
    IF = 280,
    ELSE = 281,
    FOR = 282,
    WHILE = 283,
    CONTINUE = 284,
    BREAK = 285,
    TRUE = 286,
    FALSE = 287,
    RETURN = 288,
    VOID = 289,
    NOT = 290,
    AND = 291,
    OR = 292,
    SEMICOLON = 293,
    COMMA = 294,
    OUTPUT = 295,
    INPUT = 296,
    NUMBER = 297,
    DECIMAL = 298,
    INTEGER = 299,
    IDENTIFIER = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 175 "parser.y" /* yacc.c:355  */

      char* op_val;
      struct CodeNode* code_node;
      struct ExpNode* exp_node;
      int int_val;

#line 333 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 350 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   213,   213,   223,   227,   232,   243,   268,   290,   299,
     307,   316,   324,   346,   350,   354,   358,   362,   369,   379,
     389,   397,   405,   413,   418,   428,   432,   436,   440,   445,
     450,   457,   504,   513,   523,   545,   576,   613,   637,   655,
     662,   680,   687,   718,   741,   760,   776,   804,   810,   826,
     850,   870,   878,   885,   895,   909,   917,   925,   933,   947,
     955,   962,   969,   976,   986,  1000,  1008,  1015,  1025,  1039,
    1048,  1055,  1062,  1071,  1087,  1101,  1109,  1117,  1130,  1156,
    1169
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOUBLE", "BOOLEAN", "CHAR", "ASSIGN",
  "ADD", "SUB", "DIV", "MUL", "MOD", "EQ", "LT", "LTE", "GT", "GTE", "NE",
  "FUNCTION", "BEGINSCOPE", "ENDSCOPE", "BEGINPARAM", "ENDPARAM",
  "BEGINBRACKET", "ENDBRACKET", "IF", "ELSE", "FOR", "WHILE", "CONTINUE",
  "BREAK", "TRUE", "FALSE", "RETURN", "VOID", "NOT", "AND", "OR",
  "SEMICOLON", "COMMA", "OUTPUT", "INPUT", "NUMBER", "DECIMAL", "INTEGER",
  "IDENTIFIER", "$accept", "prog_start", "functions", "func_ident",
  "function", "arguements", "repeat_arguements", "arguement", "type",
  "statements", "controlstmt", "statement", "whilestmt", "continuestmt",
  "breakstmt", "returnstmt", "ifstmt", "functioncall", "passingargs",
  "repeat_passingargs", "declaration", "input", "output",
  "array_declaration", "expression", "assignexp", "logicop", "logicexp",
  "eqop", "equalityexp", "relop", "relationexp", "addop", "addexp",
  "multop", "multexp", "term", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -38

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-38)))

#define YYTABLE_NINF -30

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,   -38,   -38,   -38,   -38,   -38,    13,   -38,     4,    12,
     -38,   -38,   -14,    18,   -38,     4,    25,     7,    10,    37,
       4,   -38,   -38,    24,     7,    41,    39,    40,    29,    32,
      41,    30,    42,    53,   -38,   -17,    36,    68,    24,    51,
     -38,    54,    57,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
      84,   -20,    -2,     6,    17,    69,   -38,   -38,    74,    41,
      41,   -38,   -38,   -38,    19,   -38,    41,    77,    41,    -9,
      79,   -38,   -38,   -38,    24,    41,   -38,   -38,    52,   -38,
     -38,    52,   -38,   -38,   -38,   -38,    52,   -38,   -38,    52,
     -38,   -38,   -38,    52,   -38,    81,    82,    83,    85,   -38,
      86,    66,    41,    87,    67,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,    91,    93,   -38,   -38,    41,   -38,    89,   108,
      92,    24,    24,     7,    94,    41,   -38,    95,    97,   -38,
     -38,   -38,    96,   -38,   100,    24,   101,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    16,    15,    17,    13,    14,     0,     2,     4,     0,
       1,     5,     0,     0,     6,     9,     0,    11,     0,     0,
       0,     8,    12,    20,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    77,     0,     0,    20,     0,
      21,    23,    24,    25,    22,    79,    26,    80,    27,    30,
      47,    51,    55,    59,    65,    69,    74,    10,     0,     0,
       0,    32,    33,    34,    77,    73,     0,     0,    39,     0,
      42,    43,     7,    19,    20,     0,    52,    53,     0,    56,
      57,     0,    60,    61,    62,    63,     0,    66,    67,     0,
      71,    70,    72,     0,    75,     0,     0,     0,     0,    44,
       0,    41,     0,     0,     0,    18,    48,    50,    54,    58,
      64,    68,     0,     0,    45,    37,     0,    38,     0,     0,
       0,    20,    20,    11,     0,     0,    46,     0,     0,    40,
      78,    49,    35,    31,     0,    20,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   112,   -38,   -38,   -38,   -22,   103,     3,   -37,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -25,    46,   -38,    44,   -38,    43,
     -38,    38,   -38,    33,   -38,   -38,    99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,    13,     8,    16,    21,    17,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,   100,   117,
      46,    47,    48,    71,    49,    50,    78,    51,    81,    52,
      86,    53,    89,    54,    93,    55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    73,    57,     9,    68,    63,    69,     1,     2,     3,
      79,     9,    25,    10,   102,    80,    76,    77,    18,    82,
      83,    84,    85,    18,    87,    88,    31,     1,     2,     3,
      12,    14,    33,    34,    95,    96,    35,   105,     4,    15,
      68,    98,    97,   101,   103,    25,    20,    19,     5,    26,
     106,    25,    27,    28,    29,    22,    23,    30,     4,    31,
      59,    60,    25,    66,    32,    33,    34,    61,     5,    35,
      62,    33,    34,    25,    67,    64,    31,   118,    90,    91,
      92,    70,    33,    34,   127,   128,    35,    31,    72,    74,
      75,   123,   -28,    33,    34,   -29,    94,    64,   136,    99,
     131,   129,   104,   112,   113,   116,   102,   114,   115,   120,
     121,   119,   122,   124,   125,   132,   126,   133,   130,   135,
      11,   137,   134,    24,   107,   108,   111,   110,     0,   109,
      65
};

static const yytype_int16 yycheck[] =
{
      25,    38,    24,     0,    21,    30,    23,     3,     4,     5,
      12,     8,    21,     0,    23,    17,    36,    37,    15,    13,
      14,    15,    16,    20,     7,     8,    35,     3,     4,     5,
      18,    45,    41,    42,    59,    60,    45,    74,    34,    21,
      21,    66,    23,    68,    69,    21,    39,    22,    44,    25,
      75,    21,    28,    29,    30,    45,    19,    33,    34,    35,
      21,    21,    21,    21,    40,    41,    42,    38,    44,    45,
      38,    41,    42,    21,    21,    45,    35,   102,     9,    10,
      11,    45,    41,    42,   121,   122,    45,    35,    20,    38,
       6,   116,    38,    41,    42,    38,    22,    45,   135,    22,
     125,   123,    23,    22,    22,    39,    23,    22,    22,    42,
      19,    24,    19,    24,     6,    20,    24,    20,    24,    19,
       8,    20,    26,    20,    78,    81,    93,    89,    -1,    86,
      31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    34,    44,    47,    48,    50,    54,
       0,    48,    18,    49,    45,    21,    51,    53,    54,    22,
      39,    52,    45,    19,    53,    21,    25,    28,    29,    30,
      33,    35,    40,    41,    42,    45,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    66,    67,    68,    70,
      71,    73,    75,    77,    79,    81,    82,    52,    70,    21,
      21,    38,    38,    70,    45,    82,    21,    21,    21,    23,
      45,    69,    20,    55,    38,     6,    36,    37,    72,    12,
      17,    74,    13,    14,    15,    16,    76,     7,     8,    78,
       9,    10,    11,    80,    22,    70,    70,    23,    70,    22,
      64,    70,    23,    70,    23,    55,    70,    71,    73,    75,
      77,    79,    22,    22,    22,    22,    39,    65,    70,    24,
      42,    19,    19,    70,    24,     6,    24,    55,    55,    52,
      24,    70,    20,    20,    26,    19,    55,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    50,    51,    51,
      52,    52,    53,    54,    54,    54,    54,    54,    55,    55,
      55,    56,    56,    56,    56,    57,    57,    57,    57,    57,
      57,    58,    59,    60,    61,    62,    62,    63,    64,    64,
      65,    65,    66,    66,    67,    68,    69,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     2,     8,     2,     0,
       3,     0,     2,     1,     1,     1,     1,     1,     3,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     2,     2,     2,     7,    11,     4,     2,     0,
       3,     0,     2,     2,     3,     4,     4,     1,     3,     6,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     6,     1,
       1
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
#line 214 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *code_node = (yyvsp[0].code_node);

            if (!main_exists) {
                  yyerror("Error: Did not define a main function.");
            }

            printf("%s\n", code_node->code.c_str());
      }
#line 1539 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 223 "parser.y" /* yacc.c:1646  */
    { printf("No Content In File!"); }
#line 1545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 228 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = (yyvsp[0].code_node);
            (yyval.code_node) = node;
      }
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 233 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node1 = (yyvsp[-1].code_node);
            CodeNode *node2 = (yyvsp[0].code_node);
            CodeNode *combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            (yyval.code_node) = combined_node;
      }
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 244 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            node->name = (yyvsp[0].op_val);

            node->code = "func ";
            node->code += node->name;

            //  add to function table
            std::string id = (yyvsp[0].op_val);

            if (id == "main") {
                  main_exists = true;
            }

            if (symbol_table.size() == 0){
                  add_function_to_symbol_table(id);
            } else {
                  add_function_to_symbol_table(id);
            }

            (yyval.code_node) = node;
      }
#line 1593 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 269 "parser.y" /* yacc.c:1646  */
    {
            count_params = 0;
            //  create start of function
            CodeNode *node = new CodeNode;
            CodeNode *ident_node = (yyvsp[-6].code_node);
            node->code += ident_node->code + "\n";
            CodeNode *arg_node = (yyvsp[-4].code_node);
            CodeNode *state_node = (yyvsp[-1].code_node);
            node->code += arg_node->code;
            
            //  Add statement code
            node->code += state_node->code;

            node->code += "endfunc\n";

            //  Return code
            (yyval.code_node) = node;
      }
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 291 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node1 = (yyvsp[-1].code_node);
            CodeNode* node2 = (yyvsp[0].code_node);
            CodeNode* combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            
            (yyval.code_node) = combined_node;
      }
#line 1629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 300 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            (yyval.code_node) = node;
      }
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 308 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node1 = (yyvsp[-1].code_node);
            CodeNode* node2 = (yyvsp[0].code_node);
            CodeNode* combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            
            (yyval.code_node) = combined_node;
      }
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 317 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            (yyval.code_node) = node;
      }
#line 1660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 325 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            std::string var_name((yyvsp[0].op_val));

            // Check if symbol already exists
            if (find(var_name, (yyvsp[-1].int_val))) {
                  yyerror("Error: Name already exists.");
            } else {
                  // If it doesn't exist, add to symbol table
                  add_variable_to_symbol_table(var_name, (yyvsp[-1].int_val));
            }

            node->code = ". " + var_name + "\n";
            node->code += "= " + var_name + ", $" + to_string(count_params) + "\n"; count_params++;

            (yyval.code_node) = node;
            //  Type array below, but not sure if we are gonna use it
      }
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 347 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.int_val) = 0;
      }
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 351 "parser.y" /* yacc.c:1646  */
    {
            (yyval.int_val) = 1;
      }
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 355 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.int_val) = 2;
      }
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 359 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.int_val) = 3;
      }
#line 1715 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 363 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.int_val) = 4; 
      }
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 370 "parser.y" /* yacc.c:1646  */
    {  
           
            CodeNode *node1 = (yyvsp[-2].code_node);
            CodeNode *node2 = (yyvsp[0].code_node);
            CodeNode *node = new CodeNode;
            node->code = node1->code + node2->code;

            (yyval.code_node) = node;
      }
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 380 "parser.y" /* yacc.c:1646  */
    { 
           
            CodeNode* node1 = (yyvsp[-1].code_node);
            CodeNode* node2 = (yyvsp[0].code_node);
            CodeNode* combinedNode = new CodeNode;
            combinedNode->code = node1->code + node2->code;

            (yyval.code_node) = combinedNode; 
      }
#line 1751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 390 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            (yyval.code_node) = node;
      }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 398 "parser.y" /* yacc.c:1646  */
    { 
            // TODO: Implement later  
            CodeNode* whileNode = (yyvsp[0].code_node);
           
            (yyval.code_node) = whileNode;
            
      }
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 406 "parser.y" /* yacc.c:1646  */
    { 
            // TODO: Implement later
            CodeNode* ifNode = (yyvsp[0].code_node);
            
            (yyval.code_node) = ifNode;
            
      }
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 414 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* continueNode = (yyvsp[0].code_node);
            (yyval.code_node) = continueNode;
      }
#line 1793 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 419 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* breakNode = (yyvsp[0].code_node);
          
            (yyval.code_node) = breakNode;
      }
#line 1803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 429 "parser.y" /* yacc.c:1646  */
    {
            CodeNode* node = (yyvsp[0].code_node); (yyval.code_node) = node;
      }
#line 1811 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 433 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode *node = (yyvsp[0].code_node); (yyval.code_node) = node;  
      }
#line 1819 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 437 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode *node = (yyvsp[0].code_node); (yyval.code_node) = node;  
      }
#line 1827 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 441 "parser.y" /* yacc.c:1646  */
    { 
            // TODO: Implement later 
            CodeNode *node = (yyvsp[0].code_node); (yyval.code_node) = node;  
      }
#line 1836 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 446 "parser.y" /* yacc.c:1646  */
    { 
            // TODO: Implement later 
            CodeNode *node = (yyvsp[0].code_node); (yyval.code_node) = node;  
      }
#line 1845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 451 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode *node = (yyvsp[0].code_node); (yyval.code_node) = node;  
      }
#line 1853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 458 "parser.y" /* yacc.c:1646  */
    {
             CodeNode* conditionNode = (yyvsp[-4].code_node);
      CodeNode* statementsNode = (yyvsp[-1].code_node);

      CodeNode* whileNode = new CodeNode;

      // Generate code for the condition
      whileNode->code += conditionNode->code;

      // Create labels for the loop
      std::string loopLabel = generateLabel();
      std::string endLabel = generateLabel();
      std::string continueLabel = generateLabel();
      std::string breakLabel = generateLabel();

      // Add the loop start label
      whileNode->code += loopLabel + ":\n";

      // Add the code for the statements
      whileNode->code += statementsNode->code;

      // Generate code for the condition check
      whileNode->code += conditionNode->name + " :=label " + loopLabel + ", " + endLabel + "\n";


             if (insideLoop) 
             {
                 whileNode->code += ":=label " + breakLabel + "\n";
                  insideLoop = false; // Reset the flag
             }

          
            if(insideIfElse){
                  whileNode->code += ":=label " + breakLabel + "\n";
                  insideIfElse = false; // Reset the flag
            }

              // Add the loop end label
            whileNode->code += endLabel + ":\n";

       (yyval.code_node) = whileNode;
      }
#line 1900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 505 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            node->code = "continue " + generateLabel() + "\n";
            (yyval.code_node) = node;
      }
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 514 "parser.y" /* yacc.c:1646  */
    { 
      
     CodeNode* node = new CodeNode;
      node->code = "break " + generateLabel() + "\n";
      (yyval.code_node) = node;
   }
#line 1921 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 524 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode *node = new CodeNode;
            CodeNode *exp_node = (yyvsp[0].code_node);

            //  Outcome of expression will be stored in "->name"
            //  Code for expression stored in "->code"
            //  First, add code that creates the expression
            node->code = "";
            node->code += exp_node->code;

            // Then add return code
            node->code += "ret ";
            node->code += exp_node->name;
            node->code += "\n";

            //  Return
            (yyval.code_node) = node;
      }
#line 1944 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 546 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* conditionNode = (yyvsp[-4].code_node);
            CodeNode* statementsNode = (yyvsp[-1].code_node);
            
            CodeNode* ifNode = new CodeNode;
            
            // Generate code for the condition
            ifNode->code += conditionNode->code;
            
            // Create labels for the branches
            std::string trueLabel = generateLabel();
            std::string falseLabel = generateLabel();
            std::string endLabel = generateLabel();
            
            // Add the code for the condition check and branching
            ifNode->code += conditionNode->name + " :=label " + trueLabel + ", " + falseLabel + "\n";
            
            // Add the true branch label and code
            ifNode->code += trueLabel + ":\n";
            ifNode->code += statementsNode->code;
            ifNode->code += "?:=label,predicate" + endLabel + "\n";
            
            // Add the false branch label and code
            ifNode->code += falseLabel + ":\n";
            
            // Add the end label
            ifNode->code += endLabel + ":\n";
            
            (yyval.code_node) = ifNode;
      }
#line 1979 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 577 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* conditionNode = (yyvsp[-8].code_node);
            CodeNode* trueStatementsNode = (yyvsp[-5].code_node);
            CodeNode* falseStatementsNode = (yyvsp[-1].code_node);
            
            CodeNode* ifNode = new CodeNode;
            
            // Generate code for the condition
            ifNode->code += conditionNode->code;
            
            // Create labels for the branches
            std::string trueLabel = generateLabel();
            std::string falseLabel = generateLabel();
            std::string endLabel = generateLabel();
            
            // Add the code for the condition check and branching
            ifNode->code += conditionNode->name + " :=label " + trueLabel + ", " + falseLabel + "\n";
            
            // Add the true branch label and code
            ifNode->code += trueLabel + ":\n";
            ifNode->code += trueStatementsNode->code;
            ifNode->code += "?:=label,predicate" + endLabel + "\n";
            
            // Add the false branch label and code
            ifNode->code += falseLabel + ":\n";
            ifNode->code += falseStatementsNode->code;
            ifNode->code += ":=label " + endLabel + "\n";
            
            // Add the end label
            ifNode->code += endLabel + ":\n";
            
            (yyval.code_node) = ifNode;
      }
#line 2017 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 614 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            CodeNode *args_node = (yyvsp[-1].code_node);
            std::string id = (yyvsp[-3].op_val);

            if (!FindFunction(symbol_table, id)) {
                  yyerror("Error: Yo dawg there ain't no function with that name!");
            }

            node->code = "";
            node->code += args_node->code;
            node->code += "call ";
            node->code += id;
            node->code +=", ";

            node->name = id;

            (yyval.code_node) = node;

      }
#line 2042 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 638 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            CodeNode *exp_node = (yyvsp[-1].code_node);
            CodeNode *rep_node = (yyvsp[0].code_node);

            node->code = "";
            node->code += exp_node->code;
            node->code += rep_node->code;
            node->code += "param ";
            node->code += exp_node->name;
            node->code += "\n";

            node->name += rep_node->name;
            

            (yyval.code_node) = node;
      }
#line 2064 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 656 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode *node = new CodeNode;
            (yyval.code_node) = node;
      }
#line 2073 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 663 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode *node = new CodeNode;
            CodeNode *exp_node = (yyvsp[-1].code_node);
            CodeNode *rep_node = (yyvsp[0].code_node);

            node->code = "";
            node->code += exp_node->code;
            node->code += rep_node->code;
            node->code += "param ";
            node->code += exp_node->name;
            node->code += "\n";

            node->name += rep_node->name;
            

            (yyval.code_node) = node;
      }
#line 2095 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 681 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode *node = new CodeNode;
            (yyval.code_node) = node;
      }
#line 2104 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 688 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;

            // Get Identifier
            std::string id = (yyvsp[0].op_val);

            // Check if symbol already exists
            if (find(id, (yyvsp[-1].int_val))) {
                  yyerror("Error: Name already exists.");
            } else {
                  // If it doesn't exist, add to symbol table

                  if (!CheckReservedKeywords(id)) {
                        printf("%s", &id[0]);
                        yyerror("Error: Name uses reserved keyword.");
                  }

                  add_variable_to_symbol_table(id, (yyvsp[-1].int_val));
            }

            print_symbol_table();

            //    Create Declaration 
            node->code = ". ";
            node->code += id;
            node->code += "\n";

            //  Return
            (yyval.code_node) = node;
      }
#line 2139 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 719 "parser.y" /* yacc.c:1646  */
    {     
            // DECLARATION
            // .[] name, n

            CodeNode* node = new CodeNode;
            node = (yyvsp[0].code_node);
            int type = (yyvsp[-1].int_val);

            if (find(node->name, 5)) {
                  yyerror("Error: Symbol already used.");
            } else {
                  add_variable_to_symbol_table(node->name, 5);
            }

            (yyval.code_node) = node;

      }
#line 2161 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 742 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            std::string temp = create_temp();

            //  Construct code here
            node->code = decl_temp_code(temp);
            node->code += ".< ";
            node->code += temp;
            node->code +="\n";

            node->name = temp;

            //  Return
            (yyval.code_node) = node;
      }
#line 2181 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 761 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            CodeNode *exp_node = (yyvsp[-1].code_node);

            node->code = "";
            node->code += exp_node->code;
            node->code += ".> ";
            node->code += exp_node->name;
            node->code += "\n";

            (yyval.code_node) = node;
     }
#line 2198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 777 "parser.y" /* yacc.c:1646  */
    {    
            // creates array


            CodeNode *node = new CodeNode;
            std::string value = (yyvsp[-1].op_val);
            std::string id = (yyvsp[-3].op_val);

            if (atoi(&value[0]) <= 0) {
                  yyerror("Error: Array of size <= 0");
            }

            //  Add identifier string to code in node
            node->code += ".[] ";
            node->code += id;
            node->code += ", ";
            node->code += value;
            node->code += "\n";

            node->name = id;

            // Return
            (yyval.code_node) = node;
      }
#line 2227 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 805 "parser.y" /* yacc.c:1646  */
    {   
            CodeNode *node = new CodeNode;
            node = (yyvsp[0].code_node);
            (yyval.code_node) = node;
      }
#line 2237 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 811 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            CodeNode *dest = (yyvsp[-2].code_node);
            CodeNode* src = (yyvsp[0].code_node);
            
            node->code = dest->code;
            node->code += src->code;
            node->code += "= ";
            node->code += dest->name;
            node->code += ", ";
            node->code += src->name;
            node->code += "\n";

            (yyval.code_node) = node;
      }
#line 2257 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 827 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            CodeNode *index_node = (yyvsp[-3].code_node);
            CodeNode *src_node = (yyvsp[0].code_node);
            std::string id = (yyvsp[-5].op_val);

            if(!find(id, 5))
            {
                  yyerror("Array Symbol not found!!");
            }

            node->code = index_node->code;
            node->code += src_node->code;
            node->code += "[]= ";
            node->code += id + ", " + index_node->name + ", " + src_node->name + "\n";

            node->name = id;

            (yyval.code_node) = node;
      }
#line 2282 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 851 "parser.y" /* yacc.c:1646  */
    {  
            std::string temp = create_temp();
            CodeNode *node = new CodeNode;
            CodeNode *node1 = (yyvsp[-2].code_node);
            CodeNode *node2 = (yyvsp[0].code_node);
            CodeNode *op = (yyvsp[-1].code_node);

            node->code = node1->code + node2->code + decl_temp_code(temp);
            node->code += op->code + std::string(" ") + temp + std::string(", ");
            node->code += node1->name + std::string(", ") + node2->name + std::string("\n");
            node->name = temp;
            (yyval.code_node) = node;

            //temp 1 = node1.code
            //temp_2 = node2.code 
            //node.code = node1.code + node2.code + declare(temp_0)
            //node.code = + temp_0, temp_1, temp_2

      }
#line 2306 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 871 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = (yyvsp[0].code_node);
            (yyval.code_node) = node;
      }
#line 2315 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 879 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            node->code = "&& ";

            (yyval.code_node) = node;
      }
#line 2326 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 886 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            node->code = "|| ";

            (yyval.code_node) = node;
      }
#line 2337 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 896 "parser.y" /* yacc.c:1646  */
    {  
            std::string temp = create_temp();
            CodeNode *node = new CodeNode;
            CodeNode *node1 = (yyvsp[-2].code_node);
            CodeNode *node2 = (yyvsp[0].code_node);
            CodeNode *op = (yyvsp[-1].code_node);

            node->code = node1->code + node2->code + decl_temp_code(temp);
            node->code += op->code + std::string(" ") + temp + std::string(", ");
            node->code += node1->name + std::string(", ") + node2->name + std::string("\n");
            node->name = temp;
            (yyval.code_node) = node;
      }
#line 2355 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 910 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = (yyvsp[0].code_node);
            (yyval.code_node) = node;
      }
#line 2364 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 918 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            node->code = "== ";

            (yyval.code_node) = node;
            
      }
#line 2376 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 926 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            node->code = "!= ";
      }
#line 2385 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 934 "parser.y" /* yacc.c:1646  */
    {  
            std::string temp = create_temp();
            CodeNode *node = new CodeNode;
            CodeNode *node1 = (yyvsp[-2].code_node);
            CodeNode *node2 = (yyvsp[0].code_node);
            CodeNode *op = (yyvsp[-1].code_node);

            node->code = node1->code + node2->code + decl_temp_code(temp);
            node->code += op->code + std::string(" ") + temp + std::string(", ");
            node->code += node1->name + std::string(", ") + node2->name + std::string("\n");
            node->name = temp;
            (yyval.code_node) = node;
      }
#line 2403 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 948 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = (yyvsp[0].code_node);
            (yyval.code_node) = node;
      }
#line 2412 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 956 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            node->code = "< ";

            (yyval.code_node) = node;
      }
#line 2423 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 963 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            node->code = "<= ";

            (yyval.code_node) = node;
      }
#line 2434 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 970 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            node->code = "> ";

            (yyval.code_node) = node;
      }
#line 2445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 977 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            node->code = ">= ";

            (yyval.code_node) = node;
      }
#line 2456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 987 "parser.y" /* yacc.c:1646  */
    {
            std::string temp = create_temp();
            CodeNode *node = new CodeNode;
            CodeNode *node1 = (yyvsp[-2].code_node);
            CodeNode *node2 = (yyvsp[0].code_node);
            CodeNode *op = (yyvsp[-1].code_node);

            node->code = node1->code + node2->code + decl_temp_code(temp);
            node->code += op->code + std::string(" ") + temp + std::string(", ");
            node->code += node1->name + std::string(", ") + node2->name + std::string("\n");
            node->name = temp;
            (yyval.code_node) = node;
      }
#line 2474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1001 "parser.y" /* yacc.c:1646  */
    {
            CodeNode* node = (yyvsp[0].code_node);
            (yyval.code_node) = node;
      }
#line 2483 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1009 "parser.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode;
            node->code = "+ ";

            (yyval.code_node) = node;
      }
#line 2494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1016 "parser.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode;
            node->code = "- ";

            (yyval.code_node) = node;
      }
#line 2505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1026 "parser.y" /* yacc.c:1646  */
    {  
            std::string temp = create_temp();
            CodeNode *node = new CodeNode;
            CodeNode *node1 = (yyvsp[-2].code_node);
            CodeNode *node2 = (yyvsp[0].code_node);
            CodeNode *op = (yyvsp[-1].code_node);

            node->code = node1->code + node2->code + decl_temp_code(temp);
            node->code += op->code + std::string(" ") + temp + std::string(", ");
            node->code += node1->name + std::string(", ") + node2->name + std::string("\n");
            node->name = temp;
            (yyval.code_node) = node;
      }
#line 2523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1040 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = (yyvsp[0].code_node);

            (yyval.code_node) = node;
      }
#line 2533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1049 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            node->code = "* ";

            (yyval.code_node) = node;
      }
#line 2544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1056 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            node->code = "/ ";

            (yyval.code_node) = node;
      }
#line 2555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1063 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            node->code = "% ";

            (yyval.code_node) = node;
      }
#line 2566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1072 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            CodeNode* term_node = (yyvsp[0].code_node);

            node->code += term_node->code;
            node->code += "! ";
            node->code += term_node->name;
            node->code += ", ";
            node->code += term_node->name;
            node->code += "\n";

            node->name = term_node->name;

            (yyval.code_node) = node;
      }
#line 2586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1088 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            CodeNode* term_node = (yyvsp[0].code_node);

            node->code += term_node->code;
            node->name = term_node->name;


            (yyval.code_node) = node;
      }
#line 2601 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1102 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            CodeNode* exp_node = (yyvsp[-1].code_node);
            node->code = exp_node->code;

            (yyval.code_node) = exp_node;
      }
#line 2613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1110 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            node->code = "";
            node->name = (yyvsp[0].op_val);

            (yyval.code_node) = node;
      }
#line 2625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1118 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            std::string id = (yyvsp[0].op_val);
            node->name = id;

            if(!find(id, 1))
            {
                  yyerror("Integer Symbol not found!!");
            }

            (yyval.code_node) = node;
      }
#line 2642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1131 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            std::string id = (yyvsp[-5].op_val);
            CodeNode *exp_node = (yyvsp[-2].code_node);
            std::string temp = create_temp();

            if(!find(id, 5))
            {
                  yyerror("Array Symbol not found!!");
            }

            //  code only for getting, not setting
            node->code = exp_node->code;
            node->code += decl_temp_code(temp);
            node->code += "=[] ";
            node->code += temp;
            node->code += ", " + id + ", " + exp_node->name;
            node->code += "\n";

            node->name = "";
            node->name += temp;

            (yyval.code_node) = node;

      }
#line 2672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1157 "parser.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode;
            CodeNode* func = (yyvsp[0].code_node);
            std::string temp = create_temp();

            node->code = decl_temp_code(temp);
            node->code += func->code;
            node->code += temp;
            node->code += "\n";
            node->name = temp;
            (yyval.code_node) = node;
      }
#line 2689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1170 "parser.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode;
            node = (yyvsp[0].code_node);

            (yyval.code_node) = node;
      }
#line 2700 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2704 "parser.tab.c" /* yacc.c:1646  */
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
#line 1178 "parser.y" /* yacc.c:1906  */


int main()
{

reservedKeywords.push_back("if");
reservedKeywords.push_back("else");
reservedKeywords.push_back("for");
reservedKeywords.push_back("while");
reservedKeywords.push_back("continue");
reservedKeywords.push_back("break");
reservedKeywords.push_back("true");
reservedKeywords.push_back("false");
reservedKeywords.push_back("return");
reservedKeywords.push_back("void");
reservedKeywords.push_back("and");
reservedKeywords.push_back("or");
reservedKeywords.push_back("mod");
reservedKeywords.push_back("dbl");
reservedKeywords.push_back("int");
reservedKeywords.push_back("flt");
reservedKeywords.push_back("bln");
reservedKeywords.push_back("chr");
reservedKeywords.push_back("intake");
reservedKeywords.push_back("defecate");
reservedKeywords.push_back("func");
reservedKeywords.push_back("main");



  yyparse();
  print_symbol_table();
  return 0;
}

void yyerror(const char* s)
{
  printf("ERROR on line %d: %s\n", lineCount + 1, s);

  exit(1);
}
