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
broj {
	return BROJ;
 }
tekst {
	return TEKST;
 }
"ako je" {
	return IF;
 }
inace {
	return ELSE;
 }
blok {
	return BLOCK;
 }
kraj_bloka {
	return ENDBLOCK;
 }
stampaj {
	return STAMPAJ;
 }
[a-zA-Z_][a-zA-Z0-9]* {
	yylval.s = new string(yytext); 
	return ID;
 }
[0-9]+(\.[0-9]*)? {
	yylval.d = atof(yytext); 
	return NUM;
 }
\"[^"]*\" {
	yylval.s = new string(yytext);
	return STRING;
 }
"//" {
	return CBDELJENJE;
 }
"==" {
	return DVOJEDNAKO;
 }
"!=" {
	return RAZLICITO;
 }
"<" {
	return *yytext;
 }
">" {
	return *yytext;
 }
"<=" {
	return MANJEJEDNAKO;
 }
">=" {
	return VECEJEDNAKO;
 }
[+*":()%;^/.=-] {
	return *yytext;
 }
[ \n\t] {

 }
. {
	cerr << "Leksicka greska: Neprepoznat karakter '" << *yytext << "'" << endl;
	exit(EXIT_FAILURE);
 }
%%
