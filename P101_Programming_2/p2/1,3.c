#include <stdio.h>
#include <stdlib.h>

#define MAX 21

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	int k,b=0,a,i=0,x,j;
	FILE *f;
	char s[MAX];
	scanf("%d %s", &k, s);
	
	if(k<1)
		greska();
	
	f=fopen(s, "r");
	
	if(f==NULL)
		greska();
		
	fscanf(f, "%d", &a);
	
	if(a<0)
		greska();
	
	for(i=0;i<a;i++){
		fscanf(f, "%d", &x);
		for(j=1;j<k;j++){
			x/=10;
		}
		if(x%10==x && x)
			b++;
	}
	
	printf("%d\n", b);
	
	fclose(f);
return 0;
}
