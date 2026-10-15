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
[\[\]().:;,=+*/%-><] {return *yytext;}
[0-9] {
	yylval.v = atoi(yytext);
	return BROJ;
}
[ \t\n] { }
. {
	cerr<<"Leksicka greska"<<endl;
	exit(EXIT_FAILURE);
}

%%
