%option noyywrap
%{

  #include "parser.tab.h"

  int lineCount = 0, lineCharacterCount = 0;
%}

INTEGER 	        int
DOUBLE  	        dbl
FLOAT   	        flt
BOOLEAN 	        bln
CHAR    	        chr

ASSIGN   	        =
ADD		            \+
SUB	              -
DIV		            \/
MUL		            \*
MOD		            mod|%
EQ       	        :=
LT		            <
LTE		            <=
GT		            >
GTE		            >=
NE		            ~= 

FUNCTION	        func
BEGINSCOPE 	      \{
ENDSCOPE 	        \}
BEGINPARAM 	      \(
ENDPARAM 	        \)
BEGINBRACKET	    \[
ENDBRACKET	      \]
IF      	        if
ELSE    	        else 
FOR     	        for
WHILE		          while
CONTINUE 	        continue
BREAK 		        break
TRUE		          true
FALSE		          false
RETURN		        return
VOID		          void
NOT		            ~
AND		            and
OR		            or
SEMICOLON	        ;
COMMA		          \,

OUTPUT		        defecate
INPUT		          intake

NUMBER		        [0-9]+
DECIMAL 	        [0-9]+"."[0-9]*

NEWLINE		        \n
WHITESPACE	      \t|" "

IDENTIFIER	      [a-zA-Z_][a-zA-Z_0-9]*
BAD_IDENTIFIER	  [0-9]+([_a-zA-Z]+[_a-zA-Z0-9]*)

COMMENT           \/\/[^\n]*\n?

%%
{INTEGER}         { lineCharacterCount += yyleng; return INTEGER; }
{DOUBLE}          { lineCharacterCount += yyleng; return DOUBLE; }
{BOOLEAN}         { lineCharacterCount += yyleng; return BOOLEAN; }
{CHAR}            { lineCharacterCount += yyleng; return CHAR; }

{ASSIGN}          { lineCharacterCount += yyleng; return ASSIGN; }
{ADD}			        { lineCharacterCount += yyleng; return ADD; }
{SUB}			        { lineCharacterCount += yyleng; return SUB; }
{DIV}			        { lineCharacterCount += yyleng; return DIV; }
{MUL}			        { lineCharacterCount += yyleng; return MUL; }
{MOD}			        { lineCharacterCount += yyleng; return MOD; }
{EQ}			        { lineCharacterCount += yyleng; return EQ; }
{LT}              { lineCharacterCount += yyleng; return LT; }
{LTE}             { lineCharacterCount += yyleng; return LTE; }
{GT}              { lineCharacterCount += yyleng; return GT; }
{GTE}     		    { lineCharacterCount += yyleng; return GTE; }
{NE}              { lineCharacterCount += yyleng; return NE; }

{FUNCTION}		    { lineCharacterCount += yyleng; return FUNCTION; }
{BEGINSCOPE}		  { lineCharacterCount += yyleng; return BEGINSCOPE; }
{ENDSCOPE}		    { lineCharacterCount += yyleng; return ENDSCOPE; }
{BEGINPARAM}		  { lineCharacterCount += yyleng; return BEGINPARAM; }
{ENDPARAM}		    { lineCharacterCount += yyleng; return ENDPARAM; }
{BEGINBRACKET}	  { lineCharacterCount += yyleng; return BEGINBRACKET; }
{ENDBRACKET}		  { lineCharacterCount += yyleng; return ENDBRACKET; }
{IF}          	  { lineCharacterCount += yyleng; return IF;}
{ELSE}        	  { lineCharacterCount += yyleng; return ELSE; }
{FOR}         	  { lineCharacterCount += yyleng; return FOR; }
{WHILE}       	  { lineCharacterCount += yyleng; return WHILE; }
{CONTINUE}    	  { lineCharacterCount += yyleng; return CONTINUE;}
{BREAK}       	  { lineCharacterCount += yyleng; return BREAK;}
{TRUE}			      { lineCharacterCount += yyleng; return TRUE; }
{FALSE}			      { lineCharacterCount += yyleng; return FALSE; }
{RETURN}		      { lineCharacterCount += yyleng; return RETURN; }
{VOID}			      { lineCharacterCount += yyleng; return VOID; }
{NOT}			        { lineCharacterCount += yyleng; return NOT; }
{AND}			        { lineCharacterCount += yyleng; return AND; }
{OR}			        { lineCharacterCount += yyleng; return OR; }
{SEMICOLON}		    { lineCharacterCount += yyleng; return SEMICOLON; }
{COMMA}			      { lineCharacterCount += yyleng; return COMMA; }

{OUTPUT}		      { lineCharacterCount += yyleng; return OUTPUT; }
{INPUT}			      { lineCharacterCount += yyleng; return INPUT; }

{IDENTIFIER}   	  { lineCharacterCount += yyleng; return IDENTIFIER; }
{BAD_IDENTIFIER}  { printf("Error: Invalid identifier %s on line %d, col %d\n", yytext, lineCount + 1, lineCharacterCount + 1); lineCharacterCount += yyleng; exit(1); }

{NUMBER}      	  { lineCharacterCount += yyleng; return NUMBER; }
{DECIMAL}    		  { lineCharacterCount += yyleng; return DECIMAL; }

{COMMENT}		      { lineCharacterCount += yyleng; }

{NEWLINE}         { lineCount++; lineCharacterCount = 0;}
{WHITESPACE}      { lineCharacterCount += yyleng;}
.                 { printf("Error: Unrecognized symbol \"%s\" on line %d, col %d\n", yytext, lineCount + 1, lineCharacterCount + 1); lineCharacterCount += yyleng; exit(1); }
%%