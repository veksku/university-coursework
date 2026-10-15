2: lex.yy.o parser.tab.o
	g++ -Wall -o 2 lex.yy.o parser.tab.o

lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -Wall -c -o lex.yy.o lex.yy.c

lex.yy.c: lexer.lex
	flex lexer.lex

parser.tab.o: parser.tab.cpp
	g++ -Wall -c -o parser.tab.o parser.tab.cpp

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp

.PHONY: clean

clean:
	rm -rf *.yy.* *.o 2 *.tab.* *.output
