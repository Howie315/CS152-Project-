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

%}

%union {
      char* op_val;
      struct CodeNode* code_node;
      struct ExpNode* exp_node;
      int int_val;
}

%define parse.error verbose

%start prog_start

%token DOUBLE BOOLEAN CHAR
%token ASSIGN ADD SUB DIV MUL MOD EQ LT LTE GT GTE NE
%token FUNCTION BEGINSCOPE ENDSCOPE BEGINPARAM ENDPARAM BEGINBRACKET ENDBRACKET IF ELSE FOR WHILE CONTINUE BREAK TRUE FALSE RETURN VOID NOT AND OR SEMICOLON COMMA
%token OUTPUT INPUT
%token <op_val> NUMBER DECIMAL

%token <op_val> INTEGER
%token <op_val> IDENTIFIER

%type <code_node> expression assignment functioncall
%type <code_node> functions function array_declaration 
%type <code_node> arguement arguements repeat_arguements
%type <code_node> statement statements
%type <code_node> output input
%type <code_node> returnstmt declaration 
%type <code_node> func_ident
%type <code_node> passingargs repeat_passingargs
%type <code_node> logicop eqop relop addop multop multexp term assignexp logicexp relationexp addexp equalityexp
%type <int_val> type
%type <exp_node> ident_extend
%%

prog_start:
      functions 
      {
            CodeNode *code_node = $1;
            printf("%s\n", code_node->code.c_str());
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

func_ident:
      FUNCTION IDENTIFIER 
      {
            CodeNode *node = new CodeNode;
            node->name = $2;

            node->code = "func ";
            node->code += node->name;

            //  add to function table
            std::string id = $2;

            if (symbol_table.size() == 0){
                  add_function_to_symbol_table(id);
            } else {
                  add_function_to_symbol_table(id);
            }

            $$ = node;
      }
;
function:
      type func_ident BEGINPARAM arguements ENDPARAM BEGINSCOPE statements ENDSCOPE      
      {
            count_params = 0;
            //  create start of function
            CodeNode *node = new CodeNode;
            CodeNode *ident_node = $2;
            node->code += ident_node->code + "\n";
            CodeNode *arg_node = $4;
            CodeNode *state_node = $7;
            node->code += arg_node->code;
            
            //  Add statement code
            node->code += state_node->code;

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

            // Check if symbol already exists
            if (find(var_name, $1)) {
                  yyerror("Error: Name already exists.");
            } else {
                  // If it doesn't exist, add to symbol table
                  add_variable_to_symbol_table(var_name, $1);
            }

            node->code = ". " + var_name + "\n";
            node->code += "= " + var_name + ", $" + to_string(count_params) + "\n"; count_params++;

            $$ = node;
            //  Type array below, but not sure if we are gonna use it
      }
;

type:
      VOID        
      { 
            $$ = 0;
      }
|     INTEGER     
      {
            $$ = 1;
      }
|     BOOLEAN     
      { 
            $$ = 2;
      }
|     DOUBLE    
      { 
            $$ = 3;
      }
|     CHAR      
      { 
            $$ = 4; 
      }
;

statements:
      statement SEMICOLON statements  
      {  
            //  SEGFAULT HERE from uninit
            CodeNode *node1 = $1;
            CodeNode *node2 = $3;
            CodeNode *node = new CodeNode;
            node->code = node1->code + node2->code;

            $$ = node;
      }
|     controlstmt statements         
      { 
            // TODO: Implement later  
      }
|     %empty                          
      {
            CodeNode *node = new CodeNode;
            $$ = node;
      }
;

controlstmt:
      whilestmt     
      { 
            // TODO: Implement later  
      }
|     ifstmt        
      { 
            // TODO: Implement later  
      }
;

statement: 
      returnstmt    
      {
            CodeNode* node = $1; $$ = node;
      }
|     assignment    
      { 
            CodeNode *node = $1; $$ = node;  
      }
|     functioncall
      { 
            CodeNode *node = $1; $$ = node;  
      }
|     declaration
      { 
            CodeNode *node = $1; $$ = node;  
      }
|     output
      { 
            CodeNode *node = $1; $$ = node;  
      }
|     continuestmt  
      { 
            // TODO: Implement later 
      }
|     breakstmt     
      { 
            // TODO: Implement later 
      }
|     expression
      { 
            //CodeNode *node = $1; $$ = node;  
      }
;

whilestmt:
     WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE      
      {
            // TODO: Implement later 
      }
;

continuestmt:
   CONTINUE                         
      { 
            // TODO: Implement later 
      }
;

breakstmt:
   BREAK                            
   { 
      // TODO: Implement later 
   }
;

returnstmt: 
      RETURN expression             
      {  
            CodeNode *node = new CodeNode;
            CodeNode *exp_node = $2;

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
            $$ = node;
      }
;

ifstmt:
      IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE                                      
      { 
            // TODO: Implement later 
      }
|     IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE ELSE BEGINSCOPE statements ENDSCOPE  
      { 
            // TODO: Implement later 
      }
;

assignment:
      IDENTIFIER BEGINBRACKET expression ENDBRACKET ASSIGN expression 
      {
            // dst[index] = src
            // []= dst, index, src

            CodeNode *node = new CodeNode;
            CodeNode *expIndex_node = $3;
            CodeNode *expSrc_node = $6;

            node->code = "";
            node->code += expIndex_node->code + expSrc_node->code;
            node->code += "[]= " + std::string($1) + ", ";
            node->code += expIndex_node->name + ", ";
            node->code += expSrc_node->name + "\n";

            $$ = node;
      }
|     IDENTIFIER ASSIGN IDENTIFIER BEGINBRACKET expression ENDBRACKET
      {
            // dst = src[index]
            // =[] dst, src, index

            CodeNode *node = new CodeNode;
            CodeNode *expIndex_node = $5;

            node->code = expIndex_node->code;
            node->code += "=[] " + std::string($1) + ", ";
            node->code += std::string($3) + ", ";
            node->code += expIndex_node->name + "\n";

            $$ = node;
      }
|     IDENTIFIER ASSIGN expression                     
      {
            //  Check if ID is in table first 
            std::string id = $1;
            if(!find_ambiguous(id))
            {
                  yyerror("Symbol not found in symbol table!");
            }

            CodeNode *node = new CodeNode;
            CodeNode *exp_node = $3;

            //  Outcome of expression will be stored in ->name
            //  First, add code that creates the expression
            node->code = "";
            node->code += exp_node->code;
            // Then add the assignment;
            node->code += "= ";
            node->code += id;
            node->code += ", ";
            node->code += exp_node->name;
            node->code += "\n";

            node->name = id;

            //  Return
            $$ = node;
      }
|     IDENTIFIER ASSIGN functioncall                  
      {  
            //  Check if ID is in table first 
            std::string id = $1;
            if(!find_ambiguous(id))
            {
                  yyerror("Symbol not found in symbol table!");
            }

            //  Add functioncall code
            CodeNode *node = new CodeNode;
            CodeNode *call_node = $3;

            node->code = "";
            node->code += call_node->code;
            node->code += id;
            node->code += "\n";

            node->name = id;

            $$ = node;


      }
|     IDENTIFIER ASSIGN input                         
      {  
            CodeNode *node = new CodeNode;
            CodeNode *input_node = $3;

            //  Get identifier
            std::string id = $1;

            //  Check if exists
            if(!find_ambiguous(id))
            {
                  yyerror("Symbol not found in symbol table!");
            }

            //  Add identifier to code
            node->code = input_node->code;
            node->code += id;
            node->code += "\n";

            node->name = id;
            
            //  Return
            $$ = node;
      }
;

functioncall:
      IDENTIFIER BEGINPARAM passingargs ENDPARAM      
      {
            CodeNode *node = new CodeNode;
            CodeNode *args_node = $3;
            std::string id = $1;

            node->code = "";
            node->code += args_node->code;
            node->code += "call ";
            node->code += id;
            node->code +=", ";

            node->name = id;

            $$ = node;

      }
;

passingargs:
      expression repeat_passingargs             
      {
            CodeNode *node = new CodeNode;
            CodeNode *exp_node = $1;
            CodeNode *rep_node = $2;

            node->code = "";
            node->code += exp_node->code;
            node->code += rep_node->code;
            node->code += "param ";
            node->code += exp_node->name;
            node->code += "\n";

            node->name += rep_node->name;
            

            $$ = node;
      }
|     %empty                                    
      {  
            CodeNode *node = new CodeNode;
            $$ = node;
      }

repeat_passingargs:
      COMMA expression repeat_arguements        
      {  
            CodeNode *node = new CodeNode;
            CodeNode *exp_node = $2;
            CodeNode *rep_node = $3;

            node->code = "";
            node->code += exp_node->code;
            node->code += rep_node->code;
            node->code += "param ";
            node->code += exp_node->name;
            node->code += "\n";

            node->name += rep_node->name;
            

            $$ = node;
      }
|     %empty                                    
      {  
            CodeNode *node = new CodeNode;
            $$ = node;
      }

declaration:
      type IDENTIFIER                           
      {
            CodeNode *node = new CodeNode;

            // Get Identifier
            std::string id = $2;

            // Add to symbol table
            add_variable_to_symbol_table(id, 0);

            //    Create Declaration 
            node->code = ". ";
            node->code += id;
            node->code += "\n";

            //  Return
            $$ = node;
      }
|     type assignment
      {
            CodeNode *node = new CodeNode;

            // Get Identifier
            CodeNode *node2 = $2;

            // Add to symbol table
            add_variable_to_symbol_table(node2->name, 1);

            //    Add expression code
            node->code = "";
            node->code += node2->code;

            //    Create Declaration 
            node->code += ". ";
            node->code += node2->code;
            node->code += "\n";

            
      }
|     type array_declaration                             
      {     
            // DECLARATION
            // .[] name, n

            CodeNode* node = new CodeNode;
            node = $2;

            if (find(node->name, 5)) {
                  yyerror("Error: Symbol already used.");
            } else {
                  add_variable_to_symbol_table(node->name, 5);
            }

            $$ = node;

      }
;

input:
      INPUT BEGINPARAM ENDPARAM               
      {
            CodeNode *node = new CodeNode;

            //  Construct code here
            node->code = "";
            node->code += ".< ";

            //  Return
            $$ = node;
            

      }
;

output:
     OUTPUT BEGINPARAM expression ENDPARAM            
     {
            CodeNode *node = new CodeNode;
            CodeNode *exp_node = $3;

            node->code = "";
            node->code += exp_node->code;
            node->code += ".> ";
            node->code += exp_node->name;
            node->code += "\n";

            $$ = node;
     }
;

array_declaration:
      IDENTIFIER BEGINBRACKET expression ENDBRACKET 
      {    
            // creates array


            CodeNode *node = new CodeNode;
            CodeNode *exp_node = $3;
            std::string id = $1;

            //  Add identifier string to code in node
            node->code += exp_node->code;
            node->code += ".[] ";
            node->code += id;
            node->code += ", ";
            node->code += exp_node->name;
            node->code += "\n";

            node->name = id;

            // Return
            $$ = node;
      }
;

expression:
      assignexp                           
      {   
            CodeNode *node = new CodeNode;
            node = $1;
            $$ = node;
      }
;

assignexp:
      logicexp logicop assignexp          
      {  
            std::string temp = create_temp();
            CodeNode *node = new CodeNode;
            CodeNode *node1 = $1;
            CodeNode *node2 = $3;
            CodeNode *op = $2;

            node->code = node1->code + node2->code + decl_temp_code(temp);
            node->code += op->code + std::string(" ") + temp + std::string(", ");
            node->code += node1->name + std::string(", ") + node2->name + std::string("\n");
            node->name = temp;
            $$ = node;

            //temp 1 = node1.code
            //temp_2 = node2.code 
            //node.code = node1.code + node2.code + declare(temp_0)
            //node.code = + temp_0, temp_1, temp_2

      }
|     logicexp                            
      { 
            CodeNode* node = $1;
            $$ = node;
      }
;

logicop:
      AND                                 
      {  
            CodeNode* node = new CodeNode;
            node->code = "&& ";

            $$ = node;
      }
|     OR                                  
      {  
            CodeNode* node = new CodeNode;
            node->code = "|| ";

            $$ = node;
      }
;

logicexp:
      equalityexp eqop logicexp           
      {  
            std::string temp = create_temp();
            CodeNode *node = new CodeNode;
            CodeNode *node1 = $1;
            CodeNode *node2 = $3;
            CodeNode *op = $2;

            node->code = node1->code + node2->code + decl_temp_code(temp);
            node->code += op->code + std::string(" ") + temp + std::string(", ");
            node->code += node1->name + std::string(", ") + node2->name + std::string("\n");
            node->name = temp;
            $$ = node;
      }
|     equalityexp                         
      {  
            CodeNode* node = $1;
            $$ = node;
      }
;

eqop:
      EQ                                  
      { 
            CodeNode* node = new CodeNode;
            node->code = "== ";

            $$ = node;
            
      }
|     NE                                  
      { 
            CodeNode* node = new CodeNode;
            node->code = "!= ";
      }
;

equalityexp:
      relationexp relop equalityexp       
      {  
            std::string temp = create_temp();
            CodeNode *node = new CodeNode;
            CodeNode *node1 = $1;
            CodeNode *node2 = $3;
            CodeNode *op = $2;

            node->code = node1->code + node2->code + decl_temp_code(temp);
            node->code += op->code + std::string(" ") + temp + std::string(", ");
            node->code += node1->name + std::string(", ") + node2->name + std::string("\n");
            node->name = temp;
            $$ = node;
      }
|     relationexp                         
      {  
            CodeNode* node = $1;
            $$ = node;
      }
;

relop:
      LT                                  
      {  
            CodeNode* node = new CodeNode;
            node->code = "< ";

            $$ = node;
      }
|     LTE                                 
      {  
            CodeNode* node = new CodeNode;
            node->code = "<= ";

            $$ = node;
      }
|     GT                                  
      {  
            CodeNode* node = new CodeNode;
            node->code = "> ";

            $$ = node;
      }
|     GTE                                 
      {  
            CodeNode* node = new CodeNode;
            node->code = ">= ";

            $$ = node;
      }
;

relationexp:
      addexp addop relationexp            
      {
            std::string temp = create_temp();
            CodeNode *node = new CodeNode;
            CodeNode *node1 = $1;
            CodeNode *node2 = $3;
            CodeNode *op = $2;

            node->code = node1->code + node2->code + decl_temp_code(temp);
            node->code += op->code + std::string(" ") + temp + std::string(", ");
            node->code += node1->name + std::string(", ") + node2->name + std::string("\n");
            node->name = temp;
            $$ = node;
      }
|     addexp                              
      {
            CodeNode* node = $1;
            $$ = node;
      }
;

addop:
      ADD
      {
            CodeNode* node = new CodeNode;
            node->code = "+ ";

            $$ = node;
      }
|     SUB                                 
      {
            CodeNode* node = new CodeNode;
            node->code = "- ";

            $$ = node;
      }
;

addexp:
      multexp multop addexp               
      {  
            std::string temp = create_temp();
            CodeNode *node = new CodeNode;
            CodeNode *node1 = $1;
            CodeNode *node2 = $3;
            CodeNode *op = $2;

            node->code = node1->code + node2->code + decl_temp_code(temp);
            node->code += op->code + std::string(" ") + temp + std::string(", ");
            node->code += node1->name + std::string(", ") + node2->name + std::string("\n");
            node->name = temp;
            $$ = node;
      }
|     multexp                             
      { 
            CodeNode* node = $1;

            $$ = node;
      }
;

multop:
      MUL                                 
      { 
            CodeNode* node = new CodeNode;
            node->code = "* ";

            $$ = node;
      }
|     DIV                                 
      { 
            CodeNode* node = new CodeNode;
            node->code = "/ ";

            $$ = node;
      }
|     MOD                                 
      { 
            CodeNode* node = new CodeNode;
            node->code = "% ";

            $$ = node;
      }
;
multexp: 
      NOT term
      { 
            CodeNode* node = new CodeNode;
            CodeNode* term_node = $2;

            node->code += term_node->code;
            node->code += "! ";
            node->code += term_node->name;
            node->code += ", ";
            node->code += term_node->name;
            node->code += "\n";

            node->name = term_node->name;

            $$ = node;
      }
|     term                                
      {  
            CodeNode* node = new CodeNode;
            CodeNode* term_node = $1;

            node->code += term_node->code;
            node->name = term_node->name;


            $$ = node;
      }
;

term:
      BEGINPARAM expression ENDPARAM      
      { 
            CodeNode* node = new CodeNode;
            CodeNode* exp_node = $2;
            node->code = exp_node->code;

            $$ = exp_node;
      }
|     NUMBER                              
      { 
            CodeNode* node = new CodeNode;
            node->code = "";
            node->name = $1;

            $$ = node;
      }
|     IDENTIFIER             
      { 
            CodeNode* node = new CodeNode;
            ExpNode *exp = new ExpNode;
            std::string id = $1;
            node->name = id;
            node->name = id;

            $$ = node;
      }
|      functioncall
{
      
}
; 

%%

int main()
{
  yyparse();
  print_symbol_table();
  return 0;
}

void yyerror(const char* s)
{
  printf("ERROR on line %d: %s\n", lineCount + 1, s);

  exit(1);
}