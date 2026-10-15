%option noinput
%option nounput
%option noyywrap

%{
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "parser.tab.hpp"

%}

%%
razlomak {
	return RAZLOMAK;
}
stampaj {
	return STAMPAJ;
}
proveri {
	return PROVERI;
}
"<=" { return MANJEJEDNAKO; }
">=" { return VECEJEDNAKO; }
"==" { return DVOJEDNAKO; }
"!=" { return RAZLICITO; }
[a-zA-Z_][a-zA-Z0-9]* {
	return ID;
}
(-)?[0-9]+ {
	return NUM;
}
[\[\];=,+()/*^~<>-] {
	return *yytext;
}
[ \t\n] { }
. {
	cerr << "Leksicka greska, detektovan karakter '" << *yytext << "'" << endl;
	exit(EXIT_FAILURE);
}
%%
