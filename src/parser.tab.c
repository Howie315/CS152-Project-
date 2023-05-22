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

extern int yylex();
void yyerror(const char *s);
extern int lineCount;

char *identToken;
int numberToken;
int  count_names = 0;
int count_params = 0;

enum Type { Integer, Array, Boolean, Double, Character};

struct Symbol {
  std::string name;
  Type type;
};

struct Function {
  std::string name;
  std::vector<Symbol> declarations;
};

std::vector <Function> symbol_table;

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
bool find(std::string &value, Type t) {
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
void add_variable_to_symbol_table(std::string &value, Type t) {
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


#line 184 "parser.tab.c" /* yacc.c:339  */

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
#line 119 "parser.y" /* yacc.c:355  */

      char* op_val;
      struct CodeNode* code_node;
      int int_val;

#line 276 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 293 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

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
       0,   147,   147,   152,   156,   161,   172,   207,   216,   224,
     233,   241,   250,   261,   262,   263,   264,   265,   269,   273,
     274,   278,   279,   283,   284,   285,   286,   287,   288,   289,
     290,   294,   298,   302,   306,   310,   311,   315,   316,   317,
     318,   322,   326,   327,   330,   331,   334,   335,   336,   340,
     341,   345,   346,   350,   354,   358,   359,   363,   364,   368,
     369,   373,   374,   378,   379,   383,   384,   385,   386,   390,
     391,   395,   396,   400,   401,   405,   406,   407,   410,   411,
     415,   416,   417
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
  "IDENTIFIER", "$accept", "prog_start", "functions", "function",
  "arguements", "repeat_arguements", "arguement", "type", "statements",
  "controlstmt", "statement", "whilestmt", "continuestmt", "breakstmt",
  "returnstmt", "ifstmt", "assignment", "functioncall", "passingargs",
  "repeat_passingargs", "declaration", "io", "ref", "array", "expression",
  "assignexp", "logicop", "logicexp", "eqop", "equalityexp", "relop",
  "relationexp", "addop", "addexp", "multop", "multexp", "term", YY_NULLPTR
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

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,   -38,   -38,   -38,   -38,   -38,    14,   -38,     8,   -10,
     -38,   -38,   -15,    25,     8,    44,    34,    35,    62,     8,
     -38,    59,   -38,    30,    34,   -14,   -14,    64,    67,   -38,
     -38,   -14,    -6,    68,    69,   -38,    17,    38,    71,    30,
      54,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,    78,   -38,   -38,    32,    20,    63,    46,     7,   -38,
     -38,    59,   -38,    70,    74,   -14,   -14,   -38,   -38,    52,
      76,   -16,   -14,     4,   -38,    78,   -38,   -38,    30,   -14,
     -38,   -38,   -14,   -38,   -38,   -14,   -38,   -38,   -38,   -38,
     -14,   -38,   -38,   -14,   -38,   -38,   -38,   -14,   -38,   -38,
      79,    81,    82,   -38,    24,   -38,   -38,   -38,    83,    61,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,    89,    90,   -38,
     -38,   -14,   -38,    30,    30,    34,    73,    91,   -38,    84,
     -38,    93,    30,    94,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    16,    15,    17,    13,    14,     0,     2,     4,     0,
       1,     5,     0,     0,     8,     0,    10,     0,     0,     0,
       7,    11,    12,    20,    10,     0,     0,     0,     0,    32,
      33,     0,     0,     0,     0,    81,    51,     0,     0,    20,
       0,    21,    28,    29,    23,    22,    24,    25,    26,    27,
      82,    52,    30,    54,    56,    60,    64,    70,    74,    79,
       9,    51,    52,     0,     0,     0,     0,    34,    78,     0,
       0,     0,    43,    46,    47,    48,     6,    19,    20,     0,
      57,    58,     0,    61,    62,     0,    65,    66,    67,    68,
       0,    71,    72,     0,    76,    75,    77,     0,    53,    80,
       0,     0,     0,    49,    51,    39,    40,    37,     0,    45,
      18,    38,    55,    59,    63,    69,    73,     0,     0,    50,
      41,     0,    42,    20,    20,    10,     0,     0,    44,    35,
      31,     0,    20,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   105,   -38,   -38,   -23,    97,    48,   -37,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,    80,    47,   -38,   -38,
     -38,    49,    50,   -17,   -22,    39,   -38,    37,   -38,    33,
     -38,    31,   -38,    28,   -38,   -38,    95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,    15,    20,    16,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,   108,   122,
      48,    49,    50,    62,    52,    53,    82,    54,    85,    55,
      90,    56,    93,    57,    97,    58,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      22,    60,    77,    63,    64,    26,    51,    26,    12,    67,
      71,     1,     2,     3,    10,    26,    94,    95,    96,    32,
      75,    32,    51,    71,    33,    34,    35,    25,    35,   104,
      13,    61,    83,     1,     2,     3,    35,    84,    72,    61,
      25,   110,     4,   100,   101,    72,    14,    25,     9,   107,
     109,    26,     5,    91,    92,    27,     9,   111,    28,    29,
      30,    51,    17,    31,     4,    32,    18,    17,    80,    81,
      33,    34,    35,    19,     5,    36,    86,    87,    88,    89,
      21,    23,    25,    73,    79,    65,   126,   127,    66,    69,
      70,    76,    78,   129,    98,   133,    99,    61,   103,   125,
     121,   117,   128,   118,   119,   120,    51,    51,   123,   124,
     131,   130,   132,    11,   134,    51,    24,    74,   105,   102,
     106,   112,   113,   114,   115,   116,     0,    68
};

static const yytype_int16 yycheck[] =
{
      17,    24,    39,    25,    26,    21,    23,    21,    18,    31,
       6,     3,     4,     5,     0,    21,     9,    10,    11,    35,
      37,    35,    39,     6,    40,    41,    42,    23,    42,    45,
      45,    45,    12,     3,     4,     5,    42,    17,    21,    45,
      23,    78,    34,    65,    66,    21,    21,    23,     0,    71,
      72,    21,    44,     7,     8,    25,     8,    79,    28,    29,
      30,    78,    14,    33,    34,    35,    22,    19,    36,    37,
      40,    41,    42,    39,    44,    45,    13,    14,    15,    16,
      45,    19,    23,    45,     6,    21,   123,   124,    21,    21,
      21,    20,    38,    20,    24,   132,    22,    45,    22,   121,
      39,    22,   125,    22,    22,    22,   123,   124,    19,    19,
      26,    20,    19,     8,    20,   132,    19,    37,    71,    69,
      71,    82,    85,    90,    93,    97,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    34,    44,    47,    48,    49,    53,
       0,    48,    18,    45,    21,    50,    52,    53,    22,    39,
      51,    45,    69,    19,    52,    23,    21,    25,    28,    29,
      30,    33,    35,    40,    41,    42,    45,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    66,    67,
      68,    69,    70,    71,    73,    75,    77,    79,    81,    82,
      51,    45,    69,    70,    70,    21,    21,    70,    82,    21,
      21,     6,    21,    45,    62,    69,    20,    54,    38,     6,
      36,    37,    72,    12,    17,    74,    13,    14,    15,    16,
      76,     7,     8,    78,     9,    10,    11,    80,    24,    22,
      70,    70,    68,    22,    45,    63,    67,    70,    64,    70,
      54,    70,    71,    73,    75,    77,    79,    22,    22,    22,
      22,    39,    65,    19,    19,    70,    54,    54,    51,    20,
      20,    26,    19,    54,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    54,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    58,    59,    60,    61,    61,    62,    62,    62,
      62,    63,    64,    64,    65,    65,    66,    66,    66,    67,
      67,    68,    68,    69,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    76,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    80,    81,    81,
      82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     9,     2,     0,     3,
       0,     2,     2,     1,     1,     1,     1,     1,     3,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     1,     1,     2,     7,    11,     3,     3,     3,
       3,     4,     2,     0,     3,     0,     2,     2,     2,     3,
       4,     1,     1,     4,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1
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
#line 148 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *code_node = (yyvsp[0].code_node);
            //printf("%s\n", code_node->code.c_str());
      }
#line 1474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 152 "parser.y" /* yacc.c:1646  */
    { printf("No Content In File!"); }
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 157 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = (yyvsp[0].code_node);
            (yyval.code_node) = node;
      }
#line 1489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 162 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node1 = (yyvsp[-1].code_node);
            CodeNode *node2 = (yyvsp[0].code_node);
            CodeNode *combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            (yyval.code_node) = combined_node;
      }
#line 1501 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 173 "parser.y" /* yacc.c:1646  */
    {
            count_params = 0;
            //  create start of function
            CodeNode *node = new CodeNode;
            CodeNode *arg_node = (yyvsp[-4].code_node);
            CodeNode *state_node = (yyvsp[-1].code_node);
            node->code = "func ";
            node->code += (yyvsp[-6].op_val);

            node->code += "\n";
            node->code += arg_node->code;
            printf(&node->code[0]);







            //  add to function table
            std::string id = (yyvsp[-6].op_val);
            add_function_to_symbol_table(id); 
            
            //  Add statement code
            //node->code += state_node->code;

            node->code += "endfunc\n";

            //  Return code
            (yyval.code_node) = node;
      }
#line 1537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 208 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node1 = (yyvsp[-1].code_node);
            CodeNode* node2 = (yyvsp[0].code_node);
            CodeNode* combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            
            (yyval.code_node) = combined_node;
      }
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 217 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            (yyval.code_node) = node;
      }
#line 1559 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 225 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node1 = (yyvsp[-1].code_node);
            CodeNode* node2 = (yyvsp[0].code_node);
            CodeNode* combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            
            (yyval.code_node) = combined_node;
      }
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 234 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            (yyval.code_node) = node;
      }
#line 1581 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 242 "parser.y" /* yacc.c:1646  */
    { 
            CodeNode* node = new CodeNode;
            std::string var_name((yyvsp[0].op_val));
            node->code = ". " + var_name + "\n";
            node->code += "= " + var_name + ", $" + to_string(count_params) + "\n"; count_params++;

            (yyval.code_node) = node;
      }
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 251 "parser.y" /* yacc.c:1646  */
    {  
            CodeNode* node = new CodeNode;
            //CodeNode* arr_node = $2;
            //node->code = ".[] " + var_name + "\n";
            //node->code += "= " + var_name + ", $" + to_string(count_params) + "\n"; count_params++;
            (yyval.code_node) = node;
      }
#line 1606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 261 "parser.y" /* yacc.c:1646  */
    {  }
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 262 "parser.y" /* yacc.c:1646  */
    {  }
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 263 "parser.y" /* yacc.c:1646  */
    {  }
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 264 "parser.y" /* yacc.c:1646  */
    {  }
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 265 "parser.y" /* yacc.c:1646  */
    {  }
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 270 "parser.y" /* yacc.c:1646  */
    {  
            
      }
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 273 "parser.y" /* yacc.c:1646  */
    {  }
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 274 "parser.y" /* yacc.c:1646  */
    {  }
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 278 "parser.y" /* yacc.c:1646  */
    {  }
#line 1662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 279 "parser.y" /* yacc.c:1646  */
    {  }
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 283 "parser.y" /* yacc.c:1646  */
    {  }
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 284 "parser.y" /* yacc.c:1646  */
    {  }
#line 1680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 285 "parser.y" /* yacc.c:1646  */
    {  }
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 286 "parser.y" /* yacc.c:1646  */
    {  }
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 287 "parser.y" /* yacc.c:1646  */
    {  }
#line 1698 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 288 "parser.y" /* yacc.c:1646  */
    {  }
#line 1704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 289 "parser.y" /* yacc.c:1646  */
    {  }
#line 1710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 290 "parser.y" /* yacc.c:1646  */
    {  }
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 294 "parser.y" /* yacc.c:1646  */
    {  }
#line 1722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 298 "parser.y" /* yacc.c:1646  */
    {  }
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 302 "parser.y" /* yacc.c:1646  */
    {  }
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 306 "parser.y" /* yacc.c:1646  */
    {  }
#line 1740 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 310 "parser.y" /* yacc.c:1646  */
    {  }
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 311 "parser.y" /* yacc.c:1646  */
    {  }
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 315 "parser.y" /* yacc.c:1646  */
    {  }
#line 1758 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 316 "parser.y" /* yacc.c:1646  */
    {  }
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 317 "parser.y" /* yacc.c:1646  */
    {  }
#line 1770 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 318 "parser.y" /* yacc.c:1646  */
    {  }
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 322 "parser.y" /* yacc.c:1646  */
    {  }
#line 1782 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 326 "parser.y" /* yacc.c:1646  */
    {  }
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 327 "parser.y" /* yacc.c:1646  */
    {  }
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 330 "parser.y" /* yacc.c:1646  */
    {  }
#line 1800 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 331 "parser.y" /* yacc.c:1646  */
    {  }
#line 1806 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 334 "parser.y" /* yacc.c:1646  */
    {  }
#line 1812 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 335 "parser.y" /* yacc.c:1646  */
    {  }
#line 1818 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 336 "parser.y" /* yacc.c:1646  */
    {  }
#line 1824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 340 "parser.y" /* yacc.c:1646  */
    {  }
#line 1830 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 341 "parser.y" /* yacc.c:1646  */
    {  }
#line 1836 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 345 "parser.y" /* yacc.c:1646  */
    {  }
#line 1842 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 346 "parser.y" /* yacc.c:1646  */
    {  }
#line 1848 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 350 "parser.y" /* yacc.c:1646  */
    {  }
#line 1854 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 354 "parser.y" /* yacc.c:1646  */
    {  }
#line 1860 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 358 "parser.y" /* yacc.c:1646  */
    {  }
#line 1866 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 359 "parser.y" /* yacc.c:1646  */
    {  }
#line 1872 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 363 "parser.y" /* yacc.c:1646  */
    {  }
#line 1878 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 364 "parser.y" /* yacc.c:1646  */
    {  }
#line 1884 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 368 "parser.y" /* yacc.c:1646  */
    {  }
#line 1890 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 369 "parser.y" /* yacc.c:1646  */
    {  }
#line 1896 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 373 "parser.y" /* yacc.c:1646  */
    {  }
#line 1902 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 374 "parser.y" /* yacc.c:1646  */
    {  }
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 378 "parser.y" /* yacc.c:1646  */
    {  }
#line 1914 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 379 "parser.y" /* yacc.c:1646  */
    {  }
#line 1920 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 383 "parser.y" /* yacc.c:1646  */
    {  }
#line 1926 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 384 "parser.y" /* yacc.c:1646  */
    {  }
#line 1932 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 385 "parser.y" /* yacc.c:1646  */
    {  }
#line 1938 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 386 "parser.y" /* yacc.c:1646  */
    {  }
#line 1944 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 390 "parser.y" /* yacc.c:1646  */
    {  }
#line 1950 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 391 "parser.y" /* yacc.c:1646  */
    {  }
#line 1956 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 395 "parser.y" /* yacc.c:1646  */
    {  }
#line 1962 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 396 "parser.y" /* yacc.c:1646  */
    {  }
#line 1968 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 400 "parser.y" /* yacc.c:1646  */
    {  }
#line 1974 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 401 "parser.y" /* yacc.c:1646  */
    {  }
#line 1980 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 405 "parser.y" /* yacc.c:1646  */
    {  }
#line 1986 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 406 "parser.y" /* yacc.c:1646  */
    {  }
#line 1992 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 407 "parser.y" /* yacc.c:1646  */
    {  }
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 410 "parser.y" /* yacc.c:1646  */
    {  }
#line 2004 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 411 "parser.y" /* yacc.c:1646  */
    {  }
#line 2010 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 415 "parser.y" /* yacc.c:1646  */
    {  }
#line 2016 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 416 "parser.y" /* yacc.c:1646  */
    {  }
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 417 "parser.y" /* yacc.c:1646  */
    {  }
#line 2028 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2032 "parser.tab.c" /* yacc.c:1646  */
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
#line 419 "parser.y" /* yacc.c:1906  */


int main()
{
  yyparse();
  return 0;
}

void yyerror(const char* s)
{
  printf("ERROR on line %d: %s\n", lineCount + 1, s);

  exit(1);
}
