#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 21

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	FILE *f,*g;
	char s[MAX],d[MAX],c;
	
	scanf("%s%s", s,d);
	
	f=fopen(s, "r");
	
	if(f==NULL)
		greska();
	
	g=fopen(d, "w");
	
	while((c=fgetc(f))!=EOF){
		if(isdigit(c))
			fprintf(g, "0");
		else if(isalpha(c))
			fprintf(g, "1");
		else
			fprintf(g, "2");
	}
	
	fclose(f);
	fclose(g);
return 0;
}
