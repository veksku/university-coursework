izraz: parser.o lex.yy.o
	gcc -Wall -o izraz parser.o lex.yy.o
parser.o: parser.c tokeni.h
	gcc -Wall -c -o parser.o parser.c
lex.yy.o: lex.yy.c tokeni.h
	gcc -Wall -c -o lex.yy.o lex.yy.c
lex.yy.c: lexer.lex
	flex lexer.lex
	
.PHONY: clean

clean:
	rm -rf *~ *.o izraz *.yy.*
	
# *~ su bekap fajlovi
