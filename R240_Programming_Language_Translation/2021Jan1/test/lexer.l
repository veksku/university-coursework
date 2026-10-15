%option noyywrap

%{

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

#include "uglovi.hpp"
#include "parser.tab.hpp"

%}

%%

print {return PRINT_T;}
kom {return KOM_T;}
sup {return SUP_T;}
[a-z][a-z0-9]* {
	yylval.ime = new string(yytext);
	return PROMENLJIVA;
}
[A-Z]+ {
	yylval.ime = new string(yytext);
	return LISTA;
}
[0-9]+ {
	yylval.v = stoi(yytext);
	return BROJ;
}
[\[\]().:;,=+*\/%><-] {return *yytext; /*JEBEM TI REGULARNE IZRAZE POTROSIO SAM DVA SATA JER SAM OVAJ STAVIO PRE [0-9]+ I ONDA MI JE JEO JEDNOCIFRENE BROJEVE ZBOG -< AL JE GLUPO KO KURAC*/}
[ \t\n] { }
. {
	cerr<<"Leksicka greska"<<endl;
	exit(EXIT_FAILURE);
}

%%
