#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300


void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
	char s[MAX],p[MAX];
	int i,n,j;
	
	if(argc!=2)
		greska();
	
	strcpy(s,argv[1]);
	
	n=strlen(s);
	
	p[0]=s[0];
	
	for(i=1;i<n+1;i++){
		for(j=0;j<i+1;j++){
			p[(i*(i+1))/2+j]=s[i];
		}	
	}
	p[(i*(i+1))/2+j]='\0';
	
	printf("%s\n", p);
	return 0;
}
