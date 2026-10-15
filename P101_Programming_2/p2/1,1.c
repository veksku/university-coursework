#include <stdio.h>
#include <stdlib.h>
#define MAX 31

int main(){
	FILE *ulaz, *izlaz;
	char ul[MAX],iz[MAX],c;
	
	scanf("%s%s", ul, iz);
	
	ulaz= fopen(ul, "r");
	
	if(ulaz==NULL){
		fprintf(stderr, "-1\n");
		exit(EXIT_FAILURE);
	}

	izlaz= fopen(iz, "w");
	
	while((c=fgetc(ulaz))!= EOF){
		fputc(c, izlaz);
		fgetc(ulaz);
	}
	
	fclose(ulaz);
	fclose(izlaz);
	
return 0;
}
