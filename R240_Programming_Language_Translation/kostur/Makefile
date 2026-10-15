imefajla: lex.yy.o parser.tab.o
	g++ -Wall -o imefajla lex.yy.o parser.tab.o
#$@ skup pravila, ono sa leve strane; ovde je to izraz
#$^ kompiliraj sve iz liste zavisnosti (ovde su to lex.yy.o i parser.tab.o
lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -Wall -c -o lex.yy.o lex.yy.c
#$< kompiliraj prvi u listi zavisnosti, parser.tab.hpp se ne kompilira
#-c napravi objektni fajl
lex.yy.c: lexer.lex
	flex lexer.lex
parser.tab.o: parser.tab.cpp
	g++ -Wall -c -o parser.tab.o parser.tab.cpp
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp
	
.PHONY: clean

clean:
	rm -f *~ *.o *.tab.* imefajla lex.yy.c parser.output
