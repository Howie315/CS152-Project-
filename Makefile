all:
		flex compiler2.lex
		bison -v -d --file-prefix=y compiler2.y
		gcc -o parser lex.yy.c y.tab.c -lfl
clean:
	rm -f lexer parser lex.yy.c y.tab.c y.tab.h y.out