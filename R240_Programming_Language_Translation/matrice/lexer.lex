%option noyywrap
%option noinput
%option nounput

%{

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#include "matrica.hpp"
#include "parser.tab.hpp"

%}

%%
[0-9]+(\.[0-9]*)? {
	yylval.d = atof(yytext);
	return num_token;
 }
[a-zA-Z_][a-zA-Z_0-9]* {
	yylval.s = new string(yytext);
	return id_token;
 }
".*" {
	return pm_token;
 }
 
[\[\];=\n+*'-] {
	return *yytext;
 }
[ \t] {

 }
. {
	cerr << "Leksicka greska: neprepoznat karakter '" << *yytext << "'" << endl;
	exit(EXIT_FAILURE);
 }
%%
