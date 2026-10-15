#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

void greska(){
	fprintf(stderr, "-1");
	exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
	FILE *f;
	int brojac=0;
	char c,s[MAX];
	
	if(argc!=2)
		greska();
	strcpy(s, argv[1]);
	
	f=fopen(s,"r");
	
	if(f==NULL)
		greska();
	
	/*p=malloc(sizeof(char));
	if (p==NULL)
		greska(); */
	
	while((c=fgetc(f)) !=EOF) {
		if (c=='(') {
			brojac++;
		}
		else if (c==')'){
			brojac--;
		}
		if (brojac<0){
			printf("nisu\n");
		//	free(p);
			fclose(f);
			return 0;
		}
 	}
	if(brojac==0){
		printf("jesu\n");
		//free(p);
		fclose(f);
	}
	else{
		printf("nisu\n");
		//free(p);
		fclose(f);
	}
return 1;
}
