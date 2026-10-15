#include <stdio.h>
#include <stdlib.h>

#define MAX 21

typedef struct{int x; int y; int z; } VEKTOR;

void greska()
{
	fprintf(stderr, "-1");
	exit(EXIT_FAILURE);
}

int main()
{
	VEKTOR *v;
	FILE* f;
	int n,i,d,dmax,imax=0;
	
	f=fopen("vektori.txt", "r");
	if(f==NULL)
		greska();
		
	fscanf(f,"%d", &n);
	
	if(n<1)
		greska();
		
	v=malloc(n*sizeof(VEKTOR));
	if(v==NULL)
		greska();
		
	for(i=0;i<n;i++){
		fscanf(f, "%d %d %d", &v[i].x, &v[i].y, &v[i].z);
	}
	
	dmax=v[0].x*v[0].x + v[0].y*v[0].y + v[0].z*v[0].z;
	
	for(i=1;i<n;i++){
		d=v[i].x*v[i].x + v[i].y*v[i].y + v[i].z*v[i].z;
		if (dmax<d){
			dmax=d;
			imax=i;
		}
	}
	
	printf("%d %d %d\n", v[imax].x, v[imax].y, v[imax].z);
	
	fclose(f);
	
	return 0;
}
