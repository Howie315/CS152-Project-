%{
#include "codenode.h"
extern int yylex(void);
void yyerror(const char *msg);
extern int lineCount;

char *identToken;
int numberToken;
int  count_names = 0;

enum Type { Integer, Array };

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


%}

%union {
  char *op_val;
  struct CodeNode *code_node;
  int int_val;
  Type type_node;
}

%token INTEGER DOUBLE BOOLEAN CHAR
%token ASSIGN ADD SUB DIV MUL MOD 
%token FUNCTION BEGINSCOPE ENDSCOPE BEGINPARAM ENDPARAM BEGINBRACKET ENDBRACKET IF ELSE FOR WHILE CONTINUE BREAK TRUE FALSE RETURN VOID NOT AND OR SEMICOLON COMMA
%token OUTPUT INPUT
%token NUMBER DECIMAL

%token <op_val> EQ LT LTE GT GTE NE IDENTIFIER

%type <code_node> relop ref expression
%type <type_node> type


%start prog_start



%error-verbose


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
              CodeNode *code_node = $1;
              $$ = code_node
      }
|     function functions
      {
            //  Concatenate 2 generated ocde nodes together
            CodeNode *code_node1 = $1;
            CodeNode *code_node2 = $2;
            CodeNode *node = new CodeNode;
            node->code = code_node1->code + code_node2->code;
            $$ = node;
      };
;

function:
      type FUNCTION IDENTIFIER BEGINPARAM arguements ENDPARAM BEGINSCOPE statements ENDSCOPE      
      { 
            //  Track type of return
            Type func_type = type;

            //  construct code here
            CodeNode *function_node = new CodeNode;
            function_node->code = "";
            function_node->code += "\nfunc ";
            function_node->code += std::string($3);
            function_node->code += "\n";
            function_node->code += $5->code;  //  Add Args
            function_node->code += $8->code;  //  Add Function END_BODY
            function_node->code += "\nendfunc\n\n";

            //  Add function to symbol table here
            add_function_to_symbol_table(std::string($3));

            //return code 
            $$ = function_node


      }
|     type FUNCTION IDENTIFIER BEGINPARAM arguements ENDPARAM SEMICOLON                           
      {
            // This is the code to CALL an already-made function
            Type func_type = $1;

            find()

            CodeNode *func_call = new CodeNode;
            func_call->code = "";
            func_call->code += "call "


      } 
;

arguements:
      arguement repeat_arguements         
      {
            //    Set arguement node to first
            CodeNode *arg_node = $1;
            CodeNode *args = $2;

      }
|     %empty                              
      {
            CodeNode node* = new CodeNode;
            $$ = node;
      }
;

repeat_arguements:
      COMMA arguement repeat_arguements   { printf("repeat_arguements -> COMMA arguement repeat_arguements\n"); }
|     %empty                              { printf("repeat_arguements -> epsilon\n"); }
;

arguement: 
      type IDENTIFIER                     { printf("arguement -> type IDENTIFIER\n"); }
|     type array                          { printf("arguement -> array\n");}
;

type:
      VOID      
      {
      }
|     INTEGER 
      {
            $$ = Type::Integer;
      }
|     BOOLEAN
      {
            $$ = Type::Boolean;
      }
|     DOUBLE
      {
            $$ = Type::Double;
      }
|     CHAR
      {
            $$ = Type::Character;
      }
;

statements:
      statement SEMICOLON statements  { printf("statements -> statement SEMICOLON statements\n"); }
|      controlstmt statements          { printf("statements -> controlstmt statements\n"); }
|     %empty                          { printf("statements -> epsilon\n"); }
;

controlstmt:
      whilestmt     { printf("controlstmt -> whilestmt\n"); }
|     ifstmt        { printf("controlstmt -> ifstmt\n"); }
;

statement: 
      returnstmt    { printf("statement -> returnstmt\n"); }
|     assignment    { printf("statement -> assignment\n"); }
|     functioncall  { printf("statement -> functioncall\n"); }
|     declaration   { printf("statement -> declaration\n"); }
|     io            { printf("statement -> io\n"); }
|     continuestmt  { printf("statement -> continuestmt\n"); }
|     breakstmt     { printf("statement -> breakstmt\n"); }
|     expression    { printf("statement -> expression\n"); }
;

whilestmt:
     WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE      { printf("whilestmt -> WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE\n"); }
;

continuestmt:
   CONTINUE                         { printf("continuestmt -> CONTINUE\n"); }
;

breakstmt:
   BREAK                            { printf("breakstmt -> BREAK\n"); }
;

returnstmt: 
      RETURN expression             { printf("returnstmt -> expression\n"); }
;

ifstmt:
      IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE                                      { printf("ifstmt -> IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE\n"); }
|     IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE ELSE BEGINSCOPE statements ENDSCOPE  { printf("ifstmt -> IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE ELSE BEGINSCOPE statements ENDSCOPE\n"); }
;

assignment: 
      IDENTIFIER ASSIGN expression                    { printf("assignment -> IDENTIFIER ASSIGN expression\n"); }
|     array ASSIGN expression                         { printf("assignment -> array ASSIGN expression\n"); }
|     IDENTIFIER ASSIGN functioncall                  { printf("assignment -> IDENTIFIER ASSIGN functioncall\n"); }
|     IDENTIFIER ASSIGN io                            { printf("assignment -> IDENTIFIER ASSIGn io\n"); }
;

functioncall:
      IDENTIFIER BEGINPARAM passingargs ENDPARAM      { printf("functioncall -> IDENTIFIER BEGINBRACKET passingargs ENDPARAM\n"); }
;

passingargs:
      expression repeat_passingargs             { printf("passingargs -> IDENTIFIER repeat_passingargs\n"); }
|     %empty                                    {printf("passingargs -> epsilon\n"); }

repeat_passingargs:
      COMMA expression repeat_arguements        { printf("repeat_passingargs -> COMMA IDENTIFIER repeat_passingargs\n"); }
|     %empty                                    { printf("repeat_passingargs -> epsilon\n"); }

declaration:
      type IDENTIFIER                           
      {
            // "type" now returns Type of variable
            CodeNode *node = new CodeNode;

            //    Retreieve Code
            node->code = $2;

            //    Add to symbol table
            add_variable_to_symbol_table(node->name, $1);

            //    return
            $$ = node;
      }
|     type assignment                           { printf("declaration -> type assignment\n"); }
|     type array                                { printf("declaration -> type array\n"); }
;

io:
      INPUT BEGINPARAM ENDPARAM                 { printf("io -> INPUT BEGINPARAM ref ENDPARAM\n"); }
|     OUTPUT BEGINPARAM ref ENDPARAM            
      {
            CodeNode *node = new CodeNode;
            CodeNode *ref_node = ref;

            node->code = "";
            node->code += ".> ";
            node->code += ref->code;
            $$ = node;

            // .> IDENTIFIER
            // .< IDENTIFIER   

      }
;

ref:
      IDENTIFIER                                
      {
            CodeNode *node = new CodeNode;
            node->name = $1;
            node->code = $1;
            $$ = node;
      }
|     array                                     { printf("ref -> array\n"); }
;

array:
      IDENTIFIER BEGINBRACKET expression ENDBRACKET { printf("array -> IDENTIFIER BEGINBRACKET NUMBER ENDBRACKET\n"); }

;

expression:
      assignexp                           { printf("expression -> assignexp\n"); }
;

assignexp:
      logicexp logicop assignexp          { printf("assignexp -> logicexp logicop assignexp\n"); }
|     logicexp                            { printf("assignexp -> logicexp\n"); }
;

logicop:
      AND                                 { printf("logicop -> AND\n"); }
|     OR                                  { printf("logicop -> OR\n"); }
;

logicexp:
      equalityexp eqop logicexp           { printf("logicexp -> equalityexp eqop logicexp\n"); }
|     equalityexp                         { printf("logicexp -> equalityexp\n"); }
;

eqop:
      EQ                                  { printf("eqop -> EQ\n"); }
|     NE                                  { printf("eqop -> NE\n"); }
;

equalityexp:
      relationexp relop equalityexp       { printf("equalityexp -> relationexp relop equalityexp\n"); }
|     relationexp                         { printf("equalityexp -> relationexp\n"); }
;

relop:
      LT                                  
      {
            CodeNode *node = new CodeNode;
            node->code = $1;
            $$ = node;
      }
|     LTE
      {
            CodeNode *node = new CodeNode;
            node->code = $1;
            $$ = node;
      }
|     GT                                  
      {
            CodeNode *node = new CodeNode;
            node->code = $1;
            $$ = node;
      }
|     GTE
      {
            CodeNode *node = new CodeNode;
            node->code = $1;
            $$ = node;
      }
;

relationexp:
      addexp addop relationexp            {printf("relationexp -> addexp addop relationexp\n");}
|     addexp                              {printf("relationexp -> addexp\n");}
;

addop:
      ADD                                 {printf("addop -> ADD\n");}
|     SUB                                 {printf("addop -> SUB\n");}
;

addexp:
      multexp multop addexp               {printf("addexp -> multexp multop addexp\n");}
|     multexp                             {printf("addexp -> multexp\n");}
;

multop:
      MUL                                 {printf("multop -> MUL\n");}
|     DIV                                 {printf("multop -> DIV\n");}
|     MOD                                 {printf("multop -> MOD\n");}
;
multexp: 
      NOT term                            
      {     
            printf("multexp -> NOT term\n");
      }
|     term                                {printf("multexp -> term\n");}
;

term:
      BEGINPARAM expression ENDPARAM      
      {
            //    NOT DONE
      }
|     NUMBER                              
      {
            CodeNode *node = new CodeNode;
            node->name = $1;
            node->code = $1;
            $$ = node;
      }
|     ref
      {
            //    NOT DONE
            CodeNode *node = new CodeNode;
            node->name = $1;
            node->code = $1;
            $$ = node;
      }
; 
%%

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
