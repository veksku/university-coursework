#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr, "-1");
	exit(EXIT_FAILURE);
}

int main(){
	int n,i,j,b,*p;
	
	scanf("%d", &n);
	
	if(n<0)
		greska();
	
	for(i=0;i<n;i++){
		if(i==0){
			p=malloc(sizeof(int));
			if(p==NULL)
				greska();
			scanf("%d", &p[0]);
		}
		
		else{
			p=realloc(p,(i+1)*sizeof(int));
			if(p==NULL)
				greska();
			scanf("%d", &p[i]);
		}
	}
	
	for(i=0;i<n;i++,j=0,b=0){
		if(!i){
			printf("0 ");
		}
		else{
			for(j=0;j<i;j++){
				if(p[j]<p[i])
					b++;
			}
			printf("%d ", b);
		}
	}
	
	printf("\n");
	
	free(p);
	
return 0;
}
