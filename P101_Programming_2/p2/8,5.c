#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void swap(float* a, float *b)
{
	float tmp=*a;
	
	*a=*b;
	*b=tmp;
	
	return;
}

int main ()
{
	FILE *f;
	
	int n,i;
	float *x1, *x2, *y1, *y2, *d;
	
	f=fopen("duzi.txt", "r");
	if(f==NULL)
		greska();
		
	fscanf(f, "%d", &n);
	
	if(n<0)
		greska();
		
	x1=malloc(n*sizeof(float));
	if(x1==NULL)
		greska();		
	x2=malloc(n*sizeof(float));
	if(x2==NULL)
		greska();				
	y1=malloc(n*sizeof(float));
	if(y1==NULL)
		greska();		
	y2=malloc(n*sizeof(float));
	if(y2==NULL)
		greska();	
		
	d=malloc(n*sizeof(float));
	if(d==NULL)
		greska();	
		
	for(i=0;i<n;i++){
		fscanf(f, "%f %f %f %f", &x1[i],&y1[i],&x2[i],&y2[i]);
		d[i]=sqrtf(pow(x1[i]-x2[i],2)+pow(y1[i]-y2[i],2));
	}
	xxx
	/*bubble
	int razmena;
	do{
		razmena=0;
		for(i=0;i<n-1;i++){
			if(d[i]<d[i+1]){
			swap(d+i,d+i+1);
			swap(x1+i,x1+i+1);
			swap(x2+i,x2+i+1);
			swap(y1+i,y1+i+1);
			swap(y2+i,y2+i+1);
			razmena=1;
			}
		}
	}while (razmena);
	*/
	xxx
	for(i=0;i<n;i++){
		printf("%0.2f %0.2f %0.2f %0.2f %0.2f\n",
		x1[i],y1[i],x2[i],y2[i], d[i]);
	}
	
	free(f);
	free(x1);
	free(y1);
	free(x2);
	free(y2);
	free(d);
	return 0;
}

