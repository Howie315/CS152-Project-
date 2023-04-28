%{
    #include <stdio.h>
    extern FILE* yyin
%}

% token INT DOUBLE ...
%start prog_start

%%
prog_start: %empty {printf("prog_start -> epsilon\n")}
            functions {printf("prog_start -> functions")}
          ;
functions: functions {printf("function -> function")}
           function functions {printf printf("functions -> function")}
        ;
function: INT IDENT LPR arguments RPR LBR statements RBR
    {printf("function -> INT IDENT LPR arguments RPR LBR statements RBR\n")}
    ;

arguments:  %empty
            arguement repeat_arguement
        ;
repeat_arguement: %empty
                  COMMA arguement repeat_arguement

arguement: INT IDENT {}
        ;

%%
