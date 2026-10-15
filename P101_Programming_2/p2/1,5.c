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
	char c;
	
	f=fopen("plain.txt", "r");
	
	if(f==NULL)
		greska();
	
	g=fopen("sifra.txt", "w");
	
	while((c=fgetc(f))!=EOF){
		if(isalpha(c)){
			if(islower(c)){
				c=c-32;
				c=c-'B'+'A';
				if(c<'A')
					c='Z';
			}
			else{
				c=c+32;
				c=c-'b'+'a';
				if(c<'a')
					c='z';
			}
		}
		fprintf(g, "%c", c);
	}

	fclose(f);
	fclose(g);
return 0;
}
