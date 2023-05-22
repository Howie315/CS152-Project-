// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 2 "parser.y" // lalr1.cc:404

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


#line 154 "parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.hh"

// User implementation prologue.

#line 168 "parser.tab.cc" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 235 "parser.tab.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 149 "parser.y" // lalr1.cc:859
    {
            CodeNode *code_node = (yystack_[0].value.code_node);
            //printf("%s\n", code_node->code.c_str());
      }
#line 701 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 153 "parser.y" // lalr1.cc:859
    { printf("No Content In File!"); }
#line 707 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 158 "parser.y" // lalr1.cc:859
    {
            CodeNode *node = (yystack_[0].value.code_node);
            (yylhs.value.code_node) = node;
      }
#line 716 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 163 "parser.y" // lalr1.cc:859
    {
            CodeNode *node1 = (yystack_[1].value.code_node);
            CodeNode *node2 = (yystack_[0].value.code_node);
            CodeNode *combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            (yylhs.value.code_node) = combined_node;
      }
#line 728 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 174 "parser.y" // lalr1.cc:859
    {
            count_params = 0;
            //  create start of function
            CodeNode *node = new CodeNode;
            CodeNode *arg_node = (yystack_[4].value.code_node);
            CodeNode *state_node = (yystack_[1].value.code_node);
            node->code = "func ";
            node->code += (yystack_[6].value.op_val);

            node->code += "\n";
            node->code += arg_node->code;
            printf(&node->code[0]);

            //  add to function table
            std::string id = (yystack_[6].value.op_val);
            add_function_to_symbol_table(id); 
            
            //  Add statement code
            //node->code += state_node->code;

            node->code += "endfunc\n";

            //  Return code
            (yylhs.value.code_node) = node;

            
            
      }
#line 761 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 206 "parser.y" // lalr1.cc:859
    {  
            CodeNode* node1 = (yystack_[1].value.code_node);
            CodeNode* node2 = (yystack_[0].value.code_node);
            CodeNode* combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            
            (yylhs.value.code_node) = combined_node;
      }
#line 774 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 215 "parser.y" // lalr1.cc:859
    {  
            CodeNode* node = new CodeNode;
            (yylhs.value.code_node) = node;
      }
#line 783 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 223 "parser.y" // lalr1.cc:859
    { 
            CodeNode* node1 = (yystack_[1].value.code_node);
            CodeNode* node2 = (yystack_[0].value.code_node);
            CodeNode* combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            
            (yylhs.value.code_node) = combined_node;
      }
#line 796 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 232 "parser.y" // lalr1.cc:859
    {  
            CodeNode* node = new CodeNode;
            (yylhs.value.code_node) = node;
      }
#line 805 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 240 "parser.y" // lalr1.cc:859
    { 
            CodeNode* node = new CodeNode;
            std::string var_name((yystack_[0].value.op_val));
            node->code = ". " + var_name + "\n";
            node->code += "= " + var_name + ", $" + to_string(count_params) + "\n"; count_params++;

            (yylhs.value.code_node) = node;
      }
#line 818 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 249 "parser.y" // lalr1.cc:859
    {  
            CodeNode* node = new CodeNode;
            //CodeNode* arr_node = $2;
            //node->code = ".[] " + var_name + "\n";
            //node->code += "= " + var_name + ", $" + to_string(count_params) + "\n"; count_params++;

            (yylhs.value.code_node) = node;
      }
#line 831 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 260 "parser.y" // lalr1.cc:859
    {  }
#line 837 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 261 "parser.y" // lalr1.cc:859
    {  }
#line 843 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 262 "parser.y" // lalr1.cc:859
    {  }
#line 849 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 263 "parser.y" // lalr1.cc:859
    {  }
#line 855 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 264 "parser.y" // lalr1.cc:859
    {  }
#line 861 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 269 "parser.y" // lalr1.cc:859
    {  
            
      }
#line 869 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 272 "parser.y" // lalr1.cc:859
    {  }
#line 875 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 273 "parser.y" // lalr1.cc:859
    {  }
#line 881 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 277 "parser.y" // lalr1.cc:859
    {  }
#line 887 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 278 "parser.y" // lalr1.cc:859
    {  }
#line 893 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 282 "parser.y" // lalr1.cc:859
    {  }
#line 899 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 283 "parser.y" // lalr1.cc:859
    {  }
#line 905 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 284 "parser.y" // lalr1.cc:859
    {  }
#line 911 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 285 "parser.y" // lalr1.cc:859
    {  }
#line 917 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 286 "parser.y" // lalr1.cc:859
    {  }
#line 923 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 287 "parser.y" // lalr1.cc:859
    {  }
#line 929 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 288 "parser.y" // lalr1.cc:859
    {  }
#line 935 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 289 "parser.y" // lalr1.cc:859
    {  }
#line 941 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 293 "parser.y" // lalr1.cc:859
    {  }
#line 947 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 297 "parser.y" // lalr1.cc:859
    {  }
#line 953 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 301 "parser.y" // lalr1.cc:859
    {  }
#line 959 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 305 "parser.y" // lalr1.cc:859
    {  }
#line 965 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 309 "parser.y" // lalr1.cc:859
    {  }
#line 971 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 310 "parser.y" // lalr1.cc:859
    {  }
#line 977 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 314 "parser.y" // lalr1.cc:859
    {  }
#line 983 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 315 "parser.y" // lalr1.cc:859
    {  }
#line 989 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 316 "parser.y" // lalr1.cc:859
    {  }
#line 995 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 317 "parser.y" // lalr1.cc:859
    {  }
#line 1001 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 321 "parser.y" // lalr1.cc:859
    {  }
#line 1007 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 325 "parser.y" // lalr1.cc:859
    {  }
#line 1013 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 326 "parser.y" // lalr1.cc:859
    {  }
#line 1019 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 329 "parser.y" // lalr1.cc:859
    {  }
#line 1025 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 330 "parser.y" // lalr1.cc:859
    {  }
#line 1031 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 333 "parser.y" // lalr1.cc:859
    {  }
#line 1037 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 334 "parser.y" // lalr1.cc:859
    {  }
#line 1043 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 335 "parser.y" // lalr1.cc:859
    {  }
#line 1049 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 339 "parser.y" // lalr1.cc:859
    {  }
#line 1055 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 340 "parser.y" // lalr1.cc:859
    {  }
#line 1061 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 344 "parser.y" // lalr1.cc:859
    {  }
#line 1067 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 345 "parser.y" // lalr1.cc:859
    {  }
#line 1073 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 349 "parser.y" // lalr1.cc:859
    {  }
#line 1079 "parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 353 "parser.y" // lalr1.cc:859
    {  }
#line 1085 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 357 "parser.y" // lalr1.cc:859
    {  }
#line 1091 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 358 "parser.y" // lalr1.cc:859
    {  }
#line 1097 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 362 "parser.y" // lalr1.cc:859
    {  }
#line 1103 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 363 "parser.y" // lalr1.cc:859
    {  }
#line 1109 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 367 "parser.y" // lalr1.cc:859
    {  }
#line 1115 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 368 "parser.y" // lalr1.cc:859
    {  }
#line 1121 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 372 "parser.y" // lalr1.cc:859
    {  }
#line 1127 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 373 "parser.y" // lalr1.cc:859
    {  }
#line 1133 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 377 "parser.y" // lalr1.cc:859
    {  }
#line 1139 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 378 "parser.y" // lalr1.cc:859
    {  }
#line 1145 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 382 "parser.y" // lalr1.cc:859
    {  }
#line 1151 "parser.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 383 "parser.y" // lalr1.cc:859
    {  }
#line 1157 "parser.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 384 "parser.y" // lalr1.cc:859
    {  }
#line 1163 "parser.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 385 "parser.y" // lalr1.cc:859
    {  }
#line 1169 "parser.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 389 "parser.y" // lalr1.cc:859
    {  }
#line 1175 "parser.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 390 "parser.y" // lalr1.cc:859
    {  }
#line 1181 "parser.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 394 "parser.y" // lalr1.cc:859
    {  }
#line 1187 "parser.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 395 "parser.y" // lalr1.cc:859
    {  }
#line 1193 "parser.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 399 "parser.y" // lalr1.cc:859
    {  }
#line 1199 "parser.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 400 "parser.y" // lalr1.cc:859
    {  }
#line 1205 "parser.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 404 "parser.y" // lalr1.cc:859
    {  }
#line 1211 "parser.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 405 "parser.y" // lalr1.cc:859
    {  }
#line 1217 "parser.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 406 "parser.y" // lalr1.cc:859
    {  }
#line 1223 "parser.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 409 "parser.y" // lalr1.cc:859
    {  }
#line 1229 "parser.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 410 "parser.y" // lalr1.cc:859
    {  }
#line 1235 "parser.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 414 "parser.y" // lalr1.cc:859
    {  }
#line 1241 "parser.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 415 "parser.y" // lalr1.cc:859
    {  }
#line 1247 "parser.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 416 "parser.y" // lalr1.cc:859
    {  }
#line 1253 "parser.tab.cc" // lalr1.cc:859
    break;


#line 1257 "parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -38;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
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

  const unsigned char
  parser::yydefact_[] =
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

  const signed char
  parser::yypgoto_[] =
  {
     -38,   -38,   105,   -38,   -38,   -23,    97,    48,   -37,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,    80,    47,   -38,   -38,
     -38,    49,    50,   -17,   -22,    39,   -38,    37,   -38,    33,
     -38,    31,   -38,    28,   -38,   -38,    95
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     6,     7,     8,    15,    20,    16,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,   108,   122,
      48,    49,    50,    62,    52,    53,    82,    54,    85,    55,
      90,    56,    93,    57,    97,    58,    59
  };

  const unsigned char
  parser::yytable_[] =
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

  const short int
  parser::yycheck_[] =
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

  const unsigned char
  parser::yystos_[] =
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

  const unsigned char
  parser::yyr1_[] =
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

  const unsigned char
  parser::yyr2_[] =
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



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
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

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   148,   148,   153,   157,   162,   173,   205,   214,   222,
     231,   239,   248,   260,   261,   262,   263,   264,   268,   272,
     273,   277,   278,   282,   283,   284,   285,   286,   287,   288,
     289,   293,   297,   301,   305,   309,   310,   314,   315,   316,
     317,   321,   325,   326,   329,   330,   333,   334,   335,   339,
     340,   344,   345,   349,   353,   357,   358,   362,   363,   367,
     368,   372,   373,   377,   378,   382,   383,   384,   385,   389,
     390,   394,   395,   399,   400,   404,   405,   406,   409,   410,
     414,   415,   416
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
    const unsigned int user_token_number_max_ = 300;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1770 "parser.tab.cc" // lalr1.cc:1167
#line 418 "parser.y" // lalr1.cc:1168


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
