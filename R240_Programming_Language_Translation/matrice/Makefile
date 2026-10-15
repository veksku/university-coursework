matlab: lex.yy.o parser.tab.o matrica.o
	g++ -Wall -o matlab lex.yy.o parser.tab.o matrica.o
lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -Wall -c -o lex.yy.o lex.yy.c
lex.yy.c: lexer.lex
	flex lexer.lex
parser.tab.o: parser.tab.cpp matrica.hpp
	g++ -Wall -c -o parser.tab.o parser.tab.cpp
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp
matrica.o: matrica.cpp matrica.hpp
	g++ -Wall -o $@ -c $<

.PHONY: clean

clean:
	rm -f *~ *.o *.tab.* matlab lex.yy.c parser.output
