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
#include <string>
#include <vector>
extern int yylex(void);
void yyerror(const char *msg);
extern int lineCount;

char *identToken;
int numberToken;
int  count_names = 0;

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

std::string create_temp()
{
      static int num = 0;
      std::string value = "_temp" + std::to_string(num);
      num += 1;
      return value;
}

// a function to print out the symbol table to the screen
// largely for debugging purposes.
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



#line 176 "parser.tab.c" /* yacc.c:339  */

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
#line 111 "parser.y" /* yacc.c:355  */

  char *op_val;
  struct CodeNode *code_node;
  int int_val;
  Type *type_node;
  std::vector<std::string> *string_chain;

#line 270 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 287 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
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
       0,   141,   141,   146,   150,   155,   167,   213,   229,   240,
     257,   268,   278,   282,   285,   289,   293,   297,   304,   320,
     321,   331,   332,   336,   337,   338,   339,   340,   341,   342,
     343,   347,   351,   355,   359,   363,   364,   368,   397,   401,
     424,   440,   478,   494,   501,   518,   525,   543,   563,   567,
     576,   590,   604,   608,   613,   617,   618,   622,   623,   627,
     628,   632,   633,   637,   638,   642,   644,   646,   648,   653,
     654,   658,   659,   663,   664,   668,   669,   670,   673,   677,
     681,   685,   691
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "DOUBLE", "BOOLEAN", "CHAR",
  "ASSIGN", "ADD", "SUB", "DIV", "MUL", "MOD", "FUNCTION", "BEGINSCOPE",
  "ENDSCOPE", "BEGINPARAM", "ENDPARAM", "BEGINBRACKET", "ENDBRACKET", "IF",
  "ELSE", "FOR", "WHILE", "CONTINUE", "BREAK", "TRUE", "FALSE", "RETURN",
  "VOID", "NOT", "AND", "OR", "SEMICOLON", "COMMA", "OUTPUT", "INPUT",
  "EQ", "LT", "LTE", "GT", "GTE", "NE", "IDENTIFIER", "NUMBER", "DECIMAL",
  "$accept", "prog_start", "functions", "function", "arguements",
  "repeat_arguements", "arguement", "type", "statements", "controlstmt",
  "statement", "whilestmt", "continuestmt", "breakstmt", "returnstmt",
  "ifstmt", "assignment", "functioncall", "passingargs",
  "repeat_passingargs", "declaration", "input", "output", "ref", "array",
  "expression", "assignexp", "logicop", "logicexp", "eqop", "equalityexp",
  "relop", "relationexp", "addop", "addexp", "multop", "multexp", "term", YY_NULLPTR
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

#define YYPACT_NINF -37

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-37)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      61,   -37,   -37,   -37,   -37,   -37,     7,   -37,    61,    17,
     -37,   -37,    -7,     4,    61,    24,    20,    13,    43,    61,
     -37,    44,   -37,     9,    20,    42,    42,    47,    57,   -37,
     -37,    42,     2,    60,    10,   -37,    -8,    67,     9,    27,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
      80,   -37,   -37,   -21,   -11,    30,    15,    68,   -37,   -37,
      44,   -37,    72,    75,    42,    42,   -37,   -37,    50,    45,
      51,    10,   -37,    80,   -37,   -37,     9,    42,   -37,   -37,
      42,   -37,   -37,    42,   -37,   -37,   -37,   -37,    42,   -37,
     -37,    42,   -37,   -37,   -37,    42,   -37,   -37,    78,    81,
      83,    85,    84,   -37,   -37,   -37,    88,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,    92,    93,   -37,    91,    42,     9,
       9,   -37,    94,    76,    97,    98,    82,    42,   -37,    95,
     -37,   -37,    20,   100,   -37,     9,   102,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    14,    16,    15,    17,    13,     0,     2,     4,     0,
       1,     5,     0,     0,     8,     0,    10,     0,     0,     0,
       7,    11,    12,    20,    10,     0,     0,     0,     0,    32,
      33,     0,     0,     0,    51,    81,     0,     0,    20,     0,
      21,    28,    29,    23,    22,    24,    25,    26,    27,    82,
      52,    30,    54,    56,    60,    64,    70,    74,    79,     9,
      51,    52,     0,     0,     0,     0,    34,    78,     0,     0,
       0,    46,    47,    48,     6,    19,    20,     0,    57,    58,
       0,    61,    62,     0,    65,    66,    67,    68,     0,    71,
      72,     0,    76,    75,    77,     0,    53,    80,     0,     0,
       0,     0,     0,    39,    40,    37,     0,    18,    38,    55,
      59,    63,    69,    73,     0,     0,    50,     0,    43,    20,
      20,    49,     0,    45,     0,     0,     0,     0,    42,    35,
      31,    41,    10,     0,    44,    20,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   111,   -37,   -37,   -23,   101,     8,   -36,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,    86,    52,   -37,   -37,
     -37,   -37,   -37,    55,   -17,   -22,    46,   -37,    41,   -37,
      37,   -37,    36,   -37,    33,   -37,   -37,    99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    15,    20,    16,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   122,   128,
      47,   104,    48,    49,    61,    51,    52,    80,    53,    83,
      54,    88,    55,    91,    56,    95,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      22,    59,    75,    62,    63,    70,    50,    10,     9,    66,
      78,    79,     1,     2,     3,     4,     9,    69,    26,    73,
      14,    50,    17,    89,    90,    26,    81,    17,    25,    27,
      12,    82,    28,    29,    30,    71,    13,    31,     5,    32,
     107,    18,    98,    99,    33,    60,    35,   105,     1,     2,
       3,     4,    34,    35,    19,   108,    21,    23,    26,    50,
      76,    26,    25,    64,     1,     2,     3,     4,    84,    85,
      86,    87,    32,    65,     5,    32,    68,   102,    92,    93,
      94,   101,    74,   124,   125,    60,    35,    77,    60,    35,
       5,    96,    97,    60,   106,   114,   123,    70,   115,   136,
     116,   117,    50,    50,   118,   132,   119,   120,   121,   134,
     127,   126,   129,   130,   135,   131,   133,   137,    50,    11,
      24,   103,    72,   100,   110,   111,   109,   112,   113,     0,
       0,    67
};

static const yytype_int16 yycheck[] =
{
      17,    24,    38,    25,    26,    13,    23,     0,     0,    31,
      31,    32,     3,     4,     5,     6,     8,     7,    16,    36,
      16,    38,    14,     8,     9,    16,    37,    19,    18,    20,
      13,    42,    23,    24,    25,    43,    43,    28,    29,    30,
      76,    17,    64,    65,    35,    43,    44,    69,     3,     4,
       5,     6,    43,    44,    34,    77,    43,    14,    16,    76,
      33,    16,    18,    16,     3,     4,     5,     6,    38,    39,
      40,    41,    30,    16,    29,    30,    16,    69,    10,    11,
      12,    36,    15,   119,   120,    43,    44,     7,    43,    44,
      29,    19,    17,    43,    43,    17,   118,    13,    17,   135,
      17,    16,   119,   120,    16,   127,    14,    14,    17,   132,
      34,    17,    15,    15,    14,    33,    21,    15,   135,     8,
      19,    69,    36,    68,    83,    88,    80,    91,    95,    -1,
      -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    29,    47,    48,    49,    53,
       0,    48,    13,    43,    16,    50,    52,    53,    17,    34,
      51,    43,    70,    14,    52,    18,    16,    20,    23,    24,
      25,    28,    30,    35,    43,    44,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    66,    68,    69,
      70,    71,    72,    74,    76,    78,    80,    82,    83,    51,
      43,    70,    71,    71,    16,    16,    71,    83,    16,     7,
      13,    43,    62,    70,    15,    54,    33,     7,    31,    32,
      73,    37,    42,    75,    38,    39,    40,    41,    77,     8,
       9,    79,    10,    11,    12,    81,    19,    17,    71,    71,
      69,    36,    53,    63,    67,    71,    43,    54,    71,    72,
      74,    76,    78,    80,    17,    17,    17,    16,    16,    14,
      14,    17,    64,    71,    54,    54,    17,    34,    65,    15,
      15,    33,    71,    21,    51,    14,    54,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    54,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    58,    59,    60,    61,    61,    62,    62,    62,
      62,    63,    64,    64,    65,    65,    66,    66,    66,    67,
      68,    69,    69,    70,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    82,    82,
      83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     9,     2,     0,     3,
       0,     2,     2,     1,     1,     1,     1,     1,     3,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     1,     1,     2,     7,    11,     3,     3,     3,
       3,     7,     2,     0,     3,     0,     2,     2,     2,     3,
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
#line 142 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *code_node = (yyvsp[0].code_node);
            printf("%s\n", code_node->code.c_str());
      }
#line 1470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 146 "parser.y" /* yacc.c:1646  */
    { printf("No Content In File!"); }
#line 1476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 151 "parser.y" /* yacc.c:1646  */
    {
              CodeNode *code_node = (yyvsp[0].code_node);
              (yyval.code_node) = code_node;
      }
#line 1485 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 156 "parser.y" /* yacc.c:1646  */
    {
            //  Concatenate 2 generated ocde nodes together
            CodeNode *code_node1 = (yyvsp[-1].code_node);
            CodeNode *code_node2 = (yyvsp[0].code_node);
            CodeNode *node = new CodeNode;
            node->code = code_node1->code + code_node2->code;
            (yyval.code_node) = node;
      }
#line 1498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 168 "parser.y" /* yacc.c:1646  */
    { 
            //  Track type of return
            Type *func_type = (yyvsp[-8].type_node);

            //  Add function to symbol table here
            std::string id_name = (yyvsp[-6].op_val);
            add_function_to_symbol_table(id_name);

            CodeNode *func_node = new CodeNode;
            func_node->code = "";

            std::vector<std::string> args;

            //    Arguements will return a vector or arguements, pass them
            //    To the function here
            int i;
            for(i = 0; i < args.size(); i++)
            {
                  func_node->code += std::string(". ");
                  func_node->code += std::string(args.at(i));
                  func_node->code += std::string("\n");
            }
            for(i = 0; i < args.size(); i++)
            {
                  func_node->code += std::string("= ");
                  func_node->code += args.at(i);
                  func_node->code += std::string(i);  //    Figure out a to_string here
                  func_node->code += std::string("$\n");
            }

            //  construct code here
            func_node->code += "func ";
            func_node->code += std::string((yyvsp[-6].op_val));
            func_node->code += "\n";
            func_node->code += (yyvsp[-1].code_node)->code;  //  Add statements
            func_node->code += "endfunc\n\n";

            //return code 
            (yyval.code_node) = func_node;


      }
#line 1545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 214 "parser.y" /* yacc.c:1646  */
    {
            //  Init a vector of strings
            std::vector<std::string> *args;

            //  Push back first arguement
            args->push_back((yyvsp[-1].op_val));

            //  Get other args from repeat_arguements
            int i;
            for(i = 0; i < (yyvsp[0].string_chain)->size(); i++)
                  args->push_back((yyvsp[0].string_chain)->at(i));

            //  Return Vector
            (yyval.string_chain) = args;      
      }
#line 1565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 230 "parser.y" /* yacc.c:1646  */
    {
             //  Init a vector of strings
            std::vector<std::string> *args;

            //   Return empty vector
            (yyval.string_chain) = args;
      }
#line 1577 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 241 "parser.y" /* yacc.c:1646  */
    {
            //  Init a vector of strings
            std::vector<std::string> *args;

            //  Push back first arguement
            args->push_back((yyvsp[-1].op_val));

            // Add repeat args now
            int i;
            for(i = 0; i < (yyvsp[0].string_chain)->size(); i++)
                  args->push_back((yyvsp[0].string_chain)->at(i));

            //  Now return
            (yyval.string_chain) = args;

      }
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 258 "parser.y" /* yacc.c:1646  */
    {
            //  just init an empty vector and return
             //  Init a vector of strings
            std::vector<std::string> *args;

            (yyval.string_chain) = args;
      }
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 269 "parser.y" /* yacc.c:1646  */
    {
            //  This will just return a string, and add the vars to table
            std::string id = (yyvsp[0].op_val);
            Type *t = (yyvsp[-1].type_node);
            add_variable_to_symbol_table(id, *t);
            
            //  Return
            (yyval.op_val) = id;
      }
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 278 "parser.y" /* yacc.c:1646  */
    { printf("arguement -> array\n");}
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 283 "parser.y" /* yacc.c:1646  */
    {
      }
#line 1637 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 286 "parser.y" /* yacc.c:1646  */
    {
            (yyval.type_node) = Type::Integer;
      }
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 290 "parser.y" /* yacc.c:1646  */
    {
            (yyval.type_node) = Type::Boolean;
      }
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 294 "parser.y" /* yacc.c:1646  */
    {
            (yyval.type_node) = Type::Double;
      }
#line 1661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 298 "parser.y" /* yacc.c:1646  */
    {
            (yyval.type_node) = Type::Character;
      }
#line 1669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 305 "parser.y" /* yacc.c:1646  */
    {
            // Just Concatenate the two nodes here
            CodeNode *node = new CodeNode;
            CodeNode *node1 = (yyvsp[-2].code_node);
            CodeNode *node2 = (yyvsp[0].code_node);

            node->code = "";
            node->code += node1->code.c_str();
            node->code += std::string("\n");
            node->code += node2->code.c_str();

            //  Return
            (yyval.code_node) - node;

      }
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 320 "parser.y" /* yacc.c:1646  */
    {}
#line 1695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 322 "parser.y" /* yacc.c:1646  */
    {
            //  return an empty code node here
            CodeNode *empty = new CodeNode;
            empty->code = "";
            (yyval.code_node) = empty;
      }
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 331 "parser.y" /* yacc.c:1646  */
    {}
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 332 "parser.y" /* yacc.c:1646  */
    {}
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 336 "parser.y" /* yacc.c:1646  */
    { printf("statement -> returnstmt\n"); }
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 337 "parser.y" /* yacc.c:1646  */
    { printf("statement -> assignment\n"); }
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 338 "parser.y" /* yacc.c:1646  */
    { printf("statement -> functioncall\n"); }
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 339 "parser.y" /* yacc.c:1646  */
    { printf("statement -> declaration\n"); }
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 340 "parser.y" /* yacc.c:1646  */
    { printf("statement -> output\n"); }
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 341 "parser.y" /* yacc.c:1646  */
    { printf("statement -> continuestmt\n"); }
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 342 "parser.y" /* yacc.c:1646  */
    { printf("statement -> breakstmt\n"); }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 343 "parser.y" /* yacc.c:1646  */
    { printf("statement -> expression\n"); }
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 347 "parser.y" /* yacc.c:1646  */
    { printf("whilestmt -> WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE\n"); }
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 351 "parser.y" /* yacc.c:1646  */
    { printf("continuestmt -> CONTINUE\n"); }
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 355 "parser.y" /* yacc.c:1646  */
    { printf("breakstmt -> BREAK\n"); }
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 359 "parser.y" /* yacc.c:1646  */
    { printf("returnstmt -> expression\n"); }
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 363 "parser.y" /* yacc.c:1646  */
    { printf("ifstmt -> IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE\n"); }
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 364 "parser.y" /* yacc.c:1646  */
    { printf("ifstmt -> IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE ELSE BEGINSCOPE statements ENDSCOPE\n"); }
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 369 "parser.y" /* yacc.c:1646  */
    {
            //  assigns a value to a var
            CodeNode *node = new CodeNode;

            //  Get Identifier
            node->name = std::string((yyvsp[-2].op_val));

            //  Declare 
            node->code = "";
            node->code += ". ";
            node->code += std::string((yyvsp[-2].op_val));
            node->code += "\n";

            //  So we set up temporary value to be returned
            //  Code that sets the value of "temp" will be stored in the expression module
            CodeNode *exp_node = (yyvsp[0].code_node);
            node->code += exp_node->code.c_str();

            //  Now assign value
            node->code += std::string("= ");
            node->code += std::string((yyvsp[-2].op_val));
            node->code += std::string(", ");
            node->code += exp_node->name;
            node->code += std::string("\n");

            //  Return node
            (yyval.code_node) = node;
      }
#line 1835 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 398 "parser.y" /* yacc.c:1646  */
    { 
            printf("assignment -> array ASSIGN expression\n"); 
      }
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 402 "parser.y" /* yacc.c:1646  */
    {
            //  Luckily, mil makes this easier than expected
            CodeNode *node = new CodeNode;

            //  Get Identifier, init code
            node->name = std::string((yyvsp[-2].op_val));
            node->code = "";

            //  Get name of function being called
            std::string func_name = (yyvsp[0].code_node)->name;

            //  Add code
            node->code += (yyvsp[0].code_node)->code;
            node->code += "= ";
            node->code += std::string((yyvsp[-2].op_val));
            node->code += std::string(", ");
            node->code += std::string((yyvsp[0].code_node)->name);
            node->code += std::string("\n");

            //  Return
            (yyval.code_node) = node;
      }
#line 1870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 425 "parser.y" /* yacc.c:1646  */
    {
            //  COnstruct input string
            CodeNode *node = new CodeNode;
            node->code = "";
            node->code += (yyvsp[0].code_node)->code.c_str();
            node->code += std::string(" ");
            node->code += std::string((yyvsp[-2].op_val));
            node->code += std::string("\n");

            // return
            (yyval.code_node) = node;
      }
#line 1887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 441 "parser.y" /* yacc.c:1646  */
    {
            // This is the code to CALL an already-made function
            Type *func_type = (yyvsp[-6].type_node);
            std::string name = (yyvsp[-4].op_val);

            if(!find(name, *func_type))
            {
                  yyerror("ERROR: Function not defined.");
            }

            CodeNode *func_call = new CodeNode;

            func_call->name = std::string((yyvsp[-4].op_val));
            func_call->code = "";
            // ARGUEMENTS HERE
            std::vector<std::string> *args = (yyvsp[-2].string_chain);

            //    Arguements will return a vector or arguements, pass them
            //    To the function here
            int i;
            for(i = 0; i < args->size(); i++)
            {
                  func_call->code += std::string("param ");
                  func_call->code += args->at(i);
                  func_call->code += std::string("\n");
            }
            func_call->code += "call ";
            func_call->code += name;
            func_call->code +=", ";

            //return code
            (yyval.code_node) = func_call;

      }
#line 1926 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 479 "parser.y" /* yacc.c:1646  */
    { 
            //  Init a vector of strings
            std::vector<std::string> *args;

            //  Push back first arguement
            args->push_back((yyvsp[-1].code_node)->name);

            //  Get other args from repeat_arguements
            int i;
            for(i = 0; i < (yyvsp[0].string_chain)->size(); i++)
                  args->push_back((yyvsp[0].string_chain)->at(i));

            //  Return Vector
            (yyval.string_chain) = args;
      }
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 495 "parser.y" /* yacc.c:1646  */
    {
          std::vector<std::string> *args;  
          (yyval.string_chain) = args;
      }
#line 1955 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 502 "parser.y" /* yacc.c:1646  */
    {
             //  Init a vector of strings
            std::vector<std::string> *args;

            //  Push back first arguement
            //  ****MAKE SURE WE SET UP A TEMP FOR OUR EXP NODES*******
            args->push_back((yyvsp[-1].code_node)->name);

            // Add repeat args now
            int i;
            for(i = 0; i < (yyvsp[0].string_chain)->size(); i++)
                  args->push_back((yyvsp[0].string_chain)->at(i));

            //  Now return
            (yyval.string_chain) = args;
      }
#line 1976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 519 "parser.y" /* yacc.c:1646  */
    {
          std::vector<std::string> *args;  
          (yyval.string_chain) = args;
      }
#line 1985 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 526 "parser.y" /* yacc.c:1646  */
    {
            // "type" now returns Type of variable
            CodeNode *node = new CodeNode;

            // Create node code here
            node->name = std::string((yyvsp[0].op_val));
            node->code = "";
            node->code += ". ";
            node->code += std::string((yyvsp[0].op_val));

            //    Add to symbol table
            add_variable_to_symbol_table(node->name, *(yyvsp[-1].type_node));


            //    return
            (yyval.code_node) = node;
      }
#line 2007 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 544 "parser.y" /* yacc.c:1646  */
    {
            //  these two nodes are basically made already so just concat them, 
            //  But also check if they exist
            CodeNode *node = new CodeNode;
            Type *f = (yyvsp[-1].type_node);
            CodeNode *node2 = (yyvsp[0].code_node);

            //  Add to table, since we are also declaring here
            add_variable_to_symbol_table(node2->name, *f);

            // Now write the code
            node->code = "";
            node->code += (yyvsp[0].code_node)->code.c_str();

            // Return
            (yyval.code_node) = node;


      }
#line 2031 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 563 "parser.y" /* yacc.c:1646  */
    { printf("declaration -> type array\n"); }
#line 2037 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 568 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            node->code = "";
            node->code += ".<";
            (yyval.code_node) = node;
      }
#line 2048 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 577 "parser.y" /* yacc.c:1646  */
    {
            //  Construct output
            CodeNode *node = new CodeNode;
            node->code = "";
            node->code += std::string(".> ");
            node->code += (yyvsp[-1].code_node)->code.c_str();

            // Return node
            (yyval.code_node) = node;
      }
#line 2063 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 591 "parser.y" /* yacc.c:1646  */
    {
            //  Get Identifier
            CodeNode *node = new CodeNode;
            node->name = std::string((yyvsp[0].op_val));
            node->code = std::string((yyvsp[0].op_val));

            //  Check if exists
            if(!find_ambiguous(node->name))
                yyerror("Symbol not found in SYmbol table (ref)");
            
            // If it does, return
            (yyval.code_node) = node;
      }
#line 2081 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 604 "parser.y" /* yacc.c:1646  */
    { printf("ref -> array\n"); }
#line 2087 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 608 "parser.y" /* yacc.c:1646  */
    { printf("array -> IDENTIFIER BEGINBRACKET NUMBER ENDBRACKET\n"); }
#line 2093 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 613 "parser.y" /* yacc.c:1646  */
    { printf("expression -> assignexp\n"); }
#line 2099 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 617 "parser.y" /* yacc.c:1646  */
    { printf("assignexp -> logicexp logicop assignexp\n"); }
#line 2105 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 618 "parser.y" /* yacc.c:1646  */
    { printf("assignexp -> logicexp\n"); }
#line 2111 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 622 "parser.y" /* yacc.c:1646  */
    { printf("logicop -> AND\n"); }
#line 2117 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 623 "parser.y" /* yacc.c:1646  */
    { printf("logicop -> OR\n"); }
#line 2123 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 627 "parser.y" /* yacc.c:1646  */
    { printf("logicexp -> equalityexp eqop logicexp\n"); }
#line 2129 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 628 "parser.y" /* yacc.c:1646  */
    { printf("logicexp -> equalityexp\n"); }
#line 2135 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 632 "parser.y" /* yacc.c:1646  */
    { printf("eqop -> EQ\n"); }
#line 2141 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 633 "parser.y" /* yacc.c:1646  */
    { printf("eqop -> NE\n"); }
#line 2147 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 637 "parser.y" /* yacc.c:1646  */
    { printf("equalityexp -> relationexp relop equalityexp\n"); }
#line 2153 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 638 "parser.y" /* yacc.c:1646  */
    { printf("equalityexp -> relationexp\n"); }
#line 2159 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 643 "parser.y" /* yacc.c:1646  */
    {}
#line 2165 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 645 "parser.y" /* yacc.c:1646  */
    {}
#line 2171 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 647 "parser.y" /* yacc.c:1646  */
    {}
#line 2177 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 649 "parser.y" /* yacc.c:1646  */
    {}
#line 2183 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 653 "parser.y" /* yacc.c:1646  */
    {printf("relationexp -> addexp addop relationexp\n");}
#line 2189 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 654 "parser.y" /* yacc.c:1646  */
    {printf("relationexp -> addexp\n");}
#line 2195 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 658 "parser.y" /* yacc.c:1646  */
    {printf("addop -> ADD\n");}
#line 2201 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 659 "parser.y" /* yacc.c:1646  */
    {printf("addop -> SUB\n");}
#line 2207 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 663 "parser.y" /* yacc.c:1646  */
    {printf("addexp -> multexp multop addexp\n");}
#line 2213 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 664 "parser.y" /* yacc.c:1646  */
    {printf("addexp -> multexp\n");}
#line 2219 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 668 "parser.y" /* yacc.c:1646  */
    {printf("multop -> MUL\n");}
#line 2225 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 669 "parser.y" /* yacc.c:1646  */
    {printf("multop -> DIV\n");}
#line 2231 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 670 "parser.y" /* yacc.c:1646  */
    {printf("multop -> MOD\n");}
#line 2237 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 674 "parser.y" /* yacc.c:1646  */
    {     
            printf("multexp -> NOT term\n");
      }
#line 2245 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 677 "parser.y" /* yacc.c:1646  */
    {printf("multexp -> term\n");}
#line 2251 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 682 "parser.y" /* yacc.c:1646  */
    {
            //  How tf do we handle this?
      }
#line 2259 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 686 "parser.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            node->code = (yyvsp[0].op_val);
            (yyval.code_node) = node;
      }
#line 2269 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 692 "parser.y" /* yacc.c:1646  */
    {
            //    NOT DONE
            (yyval.code_node) = (yyvsp[0].code_node);
      }
#line 2278 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2282 "parser.tab.c" /* yacc.c:1646  */
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
#line 697 "parser.y" /* yacc.c:1906  */


int main(int argc, char **argv)
{
   yyparse();
   print_symbol_table();
   return 0;
}

void yyerror(const char *msg)
{
   printf("** Line %d: %s\n", lineCount, msg);
   exit(1);
}
