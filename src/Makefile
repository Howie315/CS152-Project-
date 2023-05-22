all:
		flex lexer.lex
		bison -d -t -v parser.y
		g++ -o compiler lex.yy.c parser.tab.c -lfl
		
clean:
	rm compiler parser.tab.c lex.yy.c parser.tab.h parser.output
