%{
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

%}

%union {
      char* op_val;
      struct CodeNode* code_node;
      int int_val;
}

%define parse.error verbose

%start prog_start

%token DOUBLE BOOLEAN CHAR
%token ASSIGN ADD SUB DIV MUL MOD EQ LT LTE GT GTE NE
%token FUNCTION BEGINSCOPE ENDSCOPE BEGINPARAM ENDPARAM BEGINBRACKET ENDBRACKET IF ELSE FOR WHILE CONTINUE BREAK TRUE FALSE RETURN VOID NOT AND OR SEMICOLON COMMA
%token OUTPUT INPUT
%token NUMBER DECIMAL

%token <op_val> INTEGER
%token <op_val> IDENTIFIER

%type <code_node> symbol
%type <code_node> function_ident
%type <code_node> functions function
%type <code_node> arguement arguements repeat_arguements
%type <code_node> statement statements array

%%

prog_start:
      functions 
      {
            CodeNode *code_node = $1;
            //printf("%s\n", code_node->code.c_str());
      }
|     %empty    { printf("No Content In File!"); }
;

functions: 
      function            
      {
            CodeNode *node = $1;
            $$ = node;
      }
|     function functions  
      {
            CodeNode *node1 = $1;
            CodeNode *node2 = $2;
            CodeNode *combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            $$ = combined_node;
      }
;

function:
      type FUNCTION IDENTIFIER BEGINPARAM arguements ENDPARAM BEGINSCOPE statements ENDSCOPE      
      {
            count_params = 0;
            //  create start of function
            CodeNode *node = new CodeNode;
            CodeNode *arg_node = $5;
            CodeNode *state_node = $8;
            node->code = "func ";
            node->code += $3;

            node->code += "\n";
            node->code += arg_node->code;
            printf(&node->code[0]);







            //  add to function table
            std::string id = $3;
            add_function_to_symbol_table(id); 
            
            //  Add statement code
            //node->code += state_node->code;

            node->code += "endfunc\n";

            //  Return code
            $$ = node;
      }
;

arguements:
      arguement repeat_arguements         
      {  
            CodeNode* node1 = $1;
            CodeNode* node2 = $2;
            CodeNode* combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            
            $$ = combined_node;
      }
|     %empty                              
      {  
            CodeNode* node = new CodeNode;
            $$ = node;
      }
;

repeat_arguements:
      COMMA arguement repeat_arguements   
      { 
            CodeNode* node1 = $2;
            CodeNode* node2 = $3;
            CodeNode* combined_node = new CodeNode;
            combined_node->code = node1->code + node2->code;
            
            $$ = combined_node;
      }
|     %empty                              
      {  
            CodeNode* node = new CodeNode;
            $$ = node;
      }
;

arguement: 
      type IDENTIFIER                     
      { 
            CodeNode* node = new CodeNode;
            std::string var_name($2);
            node->code = ". " + var_name + "\n";
            node->code += "= " + var_name + ", $" + to_string(count_params) + "\n"; count_params++;

            $$ = node;
      }
|     type array                          
      {  
            CodeNode* node = new CodeNode;
            //CodeNode* arr_node = $2;
            //node->code = ".[] " + var_name + "\n";
            //node->code += "= " + var_name + ", $" + to_string(count_params) + "\n"; count_params++;
            $$ = node;
      }
;

type:
      VOID      {  }
|     INTEGER   {  }
|     BOOLEAN   {  }
|     DOUBLE    {  }
|     CHAR      {  }
;

statements:
      statement SEMICOLON statements  
      {  
            
      }
|      controlstmt statements         {  }
|     %empty                          {  }
;

controlstmt:
      whilestmt     {  }
|     ifstmt        {  }
;

statement: 
      returnstmt    {  }
|     assignment    {  }
|     functioncall  {  }
|     declaration   {  }
|     io            {  }
|     continuestmt  {  }
|     breakstmt     {  }
|     expression    {  }
;

whilestmt:
     WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE      {  }
;

continuestmt:
   CONTINUE                         {  }
;

breakstmt:
   BREAK                            {  }
;

returnstmt: 
      RETURN expression             {  }
;

ifstmt:
      IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE                                      {  }
|     IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE ELSE BEGINSCOPE statements ENDSCOPE  {  }
;

assignment: 
      IDENTIFIER ASSIGN expression                    {  }
|     array ASSIGN expression                         {  }
|     IDENTIFIER ASSIGN functioncall                  {  }
|     IDENTIFIER ASSIGN io                            {  }
;

functioncall:
      IDENTIFIER BEGINPARAM passingargs ENDPARAM      {  }
;

passingargs:
      expression repeat_passingargs             {  }
|     %empty                                    {  }

repeat_passingargs:
      COMMA expression repeat_arguements        {  }
|     %empty                                    {  }

declaration:
      type IDENTIFIER                           {  }
|     type assignment                           {  }
|     type array                                {  }
;

io:
      INPUT BEGINPARAM ENDPARAM                 {  }
|     OUTPUT BEGINPARAM ref ENDPARAM            {  }
;

ref:
      IDENTIFIER                                {  }
|     array                                     {  }
;

array:
      IDENTIFIER BEGINBRACKET expression ENDBRACKET {  }
;

expression:
      assignexp                           {  }
;

assignexp:
      logicexp logicop assignexp          {  }
|     logicexp                            {  }
;

logicop:
      AND                                 {  }
|     OR                                  {  }
;

logicexp:
      equalityexp eqop logicexp           {  }
|     equalityexp                         {  }
;

eqop:
      EQ                                  {  }
|     NE                                  {  }
;

equalityexp:
      relationexp relop equalityexp       {  }
|     relationexp                         {  }
;

relop:
      LT                                  {  }
|     LTE                                 {  }
|     GT                                  {  }
|     GTE                                 {  }
;

relationexp:
      addexp addop relationexp            {  }
|     addexp                              {  }
;

addop:
      ADD                                 {  }
|     SUB                                 {  }
;

addexp:
      multexp multop addexp               {  }
|     multexp                             {  }
;

multop:
      MUL                                 {  }
|     DIV                                 {  }
|     MOD                                 {  }
;
multexp: 
      NOT term                            {  }
|     term                                {  }
;

term:
      BEGINPARAM expression ENDPARAM      {  }
|     NUMBER                              {  }
|     ref                                 {  }
; 
%%

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