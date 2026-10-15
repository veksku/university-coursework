%option noyywrap

%{

#include "tokeni.h"
%}

%%

print 			{return PRINT_T;}
\"[a-zA-Z0-9 ]+\" 	{return STRING_T;}
[a-z] 			{return VAR_T;}
"(" 			{return OZ;}
")" 			{return ZZ;}
":=" 			{return DODELA;}
[ \t\n] 		{ }
. {
	fprintf(stderr, "Leksicka greska: %s\n", yytext);
	exit(EXIT_FAILURE);
}

%%
