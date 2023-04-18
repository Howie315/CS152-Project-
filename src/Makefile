all:
		flex lexer.lex
		gison -v -d --file-prefix-y compiler.y
	    gcc -o parser lex.yy.c y.tab.c -lfl
		
clean:
	rm -f lexer parser lex.yy.c y.tab.c y.tab.h y.out