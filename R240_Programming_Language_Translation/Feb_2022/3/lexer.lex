%option noyywrap
%option noinput
%option nounput

%{
#include "tokeni.h"

%}

%%

razlomak {return RAZLOMAK;}
stampaj {return STAMPAJ;}
[a-zA-Z_][a-zA-Z0-9_]* {return VAR;}
"[" {return OZ;}
"]" {return ZZ;}
, {return ZAREZ;}
= {return DODELA;}
; {return TZ;}
(-)?[0-9]+ {return NUM;}
[ \n\t] {}
. {
	fprintf(stderr, "Leksicka greska: %s\n", yytext);
	exit(EXIT_FAILURE);
}
%%
