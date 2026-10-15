%option noyywrap
%option noinput
%option nounput

%{
#include "tokeni.h"

%}

%%
broj {
	return BROJ;
 }
stampaj {
	return STAMPAJ;
 }
[a-zA-Z_][a-zA-Z0-9]* {
	return VAR;
 }
(-)?[0-9]+(\.[0-9]*)? {
	return NUM;
 }
= {
	return JEDNAKO;
 }
; {
	return TZ;
 }
[ \n\t] { }
. {
	fprintf(stderr, "Leksicka greska");
	exit(EXIT_FAILURE);
 }
%%
