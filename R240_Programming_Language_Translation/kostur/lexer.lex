%option noyywrap
%option noinput
%option nounput

%{
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include "parser.tab.hpp"

%}

%%
[ \t\n] {

}
. {
	cerr << "Leksicka greska: neprepoznat karakter '" << *yytext << "'" << endl;
	exit(EXIT_FAILURE);
}
%%
