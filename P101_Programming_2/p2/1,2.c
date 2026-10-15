#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 21

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int cifra(FILE *f){
	int a,i;
	char c;
	int b[10]={0,0,0,0,0,0,0,0,0,0},counter=0,max_b,max_i;
	
	while((c=fgetc(f))!=EOF){
		if(isdigit(c)){
			a=c-'0';
			b[a]++;
			counter++;
		}
	}
	
	if(!counter){
		return -1;
	}
	
	max_b=b[0];
	max_i=0;
	for(i=1;i<10;i++){
		if(max_b<b[i]){
			max_b=b[i];
			max_i=i;
		}
	}
	return max_i;
}

int main(){

	FILE *f;
	char ulaz[MAX];
	
	scanf("%s", ulaz);
	
	f=fopen(ulaz, "r");
	
	if(f==NULL)
		greska();
	
	fprintf(stdout, "%d", cifra(f));
	
	fclose(f);
return 0;
}
