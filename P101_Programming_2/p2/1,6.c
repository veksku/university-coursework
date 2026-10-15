#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 63
#define REC 127

void greska(){
	fprintf(stderr, "-1");
	exit(EXIT_FAILURE);
}

int main(){
	FILE* f,*g;
	int k,i,j,m;
	char ulaz[MAX],rec[REC],prviDeo[REC],drugiDeo[REC],c;
	
	scanf("%s %d", ulaz, &k);
	
	if(k<0)
		greska();
	
	f=fopen(ulaz, "r");
	
	if(f==NULL)
		greska();
	
	g=fopen("rotirano.txt", "w");
	
	while (1){
		c=fgetc(f);
		
		if(c==EOF){
			fclose(f);
			fclose(g);
			return 0;
		}
		
		i=0;
		rec[i]=c;
		i++;
		while((c=fgetc(f))!=EOF && !isspace(c)){
			rec[i]=c;
			i++;
		}
		
		rec[i]='\0';
		
		if(i<k){
			j=k%i;
			m=i;
			
			for(i=0;i<j;i++){
				drugiDeo[i]=rec[i];
			}
			drugiDeo[i]='\0';
			
			for(i=0;j<m;i++,j++){
				prviDeo[i]=rec[j];
			}
			prviDeo[i]='\0';
		}
		
		else{
				
			for(i=0;i<k && rec[i];i++){
				drugiDeo[i]=rec[i];
			}
			drugiDeo[i]='\0';
		
			for(j=0;rec[i];j++,i++){
				prviDeo[j]=rec[i];
			}
			prviDeo[j]='\0';
		
		}
		
		strcat(prviDeo, drugiDeo);
		fputs(prviDeo, g);
		
		if(c==EOF){
			fclose(f);
			fclose(g);
			return 0;
		}
		
		fputc(' ', g);
	}
}
