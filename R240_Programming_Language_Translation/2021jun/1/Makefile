parser: parser.o lexer.o niske.o
	g++ -std=c++11 parser.o lexer.o niske.o -o parser

niske.o: niske.cpp niske.hpp
	g++ -std=c++11 -c niske.cpp -o niske.o

parser.o: parser.tab.cpp parser.tab.hpp
	g++ -std=c++11 -c parser.tab.cpp -o parser.o

lexer.o: lex.yy.c
	g++ -std=c++11 -c lex.yy.c -o lexer.o

lex.yy.c: lexer.l parser.tab.hpp
	flex lexer.l

parser.tab.hpp parser.tab.cpp: parser.ypp
	bison -d -v parser.ypp

.PHONY: clean

clean:
	rm -rf parser *.output *.tab.* *.yy.* *.o
