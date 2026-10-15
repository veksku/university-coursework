%option noyywrap

%{

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

#include "vektori.hpp"
#include "parser.tab.hpp"

%}

%%

def { return DEF_T; }
print { return PRINT_T; }
":=" { return DODELA; }
refX { return REFX_T; }
refY { return REFY_T; }
sim { return SIM_T; }
angle { return ANGLE_T; }
rot { return ROT_T; }
list { return LIST_T; }
[a-zA-Z][a-zA-Z0-9]* {
	yylval.ime = new string(yytext);
	return ID;
}
-?[0-9]+(\.[0-9]+)? {
	yylval.v = atoi(yytext);
	return BROJ;
}
[<>(),.;|*+_\[\]\n-] { return *yytext; }
[ \t]
. {
	cerr<<"Leksicka greska"<<yytext<<endl;
	exit(EXIT_FAILURE);
}

%%
