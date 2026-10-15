#dodaj razlomci.o na kraju ispod
2: lex.yy.o parser.o 
	g++ -Wall -o 2 lex.yy.o parser.o
lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -Wall -c -o lex.yy.o lex.yy.c
lex.yy.c: lexer.lex
	flex lexer.lex
parser.o: parser.tab.cpp
	g++ -Wall -c -o parser.o parser.tab.cpp
parser.tab.hpp parser.tab.cpp: parser.ypp
	bison -d -v parser.ypp
#razlomci.o: razlomci.cpp razlomci.hpp
#	g++ -Wall -c -o razlomci.o razlomci.cpp

.PHONY: clean

clean:
	rm -rf *.o *.tab.* *.output *.yy.* 2
