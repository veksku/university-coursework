%option noyywrap

%{

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

#include "niske.hpp"
#include "parser.tab.hpp"

%}

%%

print { return PRINT_T; }
lower { return LOWER_T; }
upper { return UPPER_T; }
reverse { return REVERSE_T; }
index { return INDEX_T; }
[a-z][A-Z0-9]* { 
	yylval.ime = new string(yytext);
	return VAR_T;
}
":=" { return DODELA_T; }
[0-9]+ { 
	yylval.v = stoi(yytext);
	return BROJ; 
}
\"[a-zA-Z0-9 \\t\\n]+\" { return STRING_T; }
[:,+()\[\]|*\n] { return *yytext; }
[ \t] { }
. {
	cerr << "Leksicka greska" << yytext << endl;
	exit(EXIT_FAILURE);
}

%%
