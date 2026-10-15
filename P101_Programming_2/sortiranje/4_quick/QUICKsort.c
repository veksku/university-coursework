#include <stdio.h>
#include <stdlib.h>

void razmeni(int *a, int i, int j)
{
	printf("Pre a:%d b:%d\n", a[i], a[j]);
	int pom = a[i];
	a[i] = a[j];
	a[j] = pom;
	printf("Posle a:%d b:%d\n", a[i], a[j]);
	return;
}

/*int particionisanje(int a[], int l, int d)
{
	int pIndex = l;
	int pivot = a[d];
	for (int i = l; i<d; i++)
		if (a[i] <= pivot){
			razmeni(&a[i], &a[pIndex]);
			pIndex++;
		}
	razmeni(&a[pIndex], &a[d]);
	
	return pIndex;
}*/



int particionisanje(int *a, int l, int d)
{
	int p = l, j;
	for (j = l+1; j <= d; j++){
		if (a[j] < a[l]){
			razmeni(a, ++p, j);
		}
	}
	razmeni(a, l, p);
	return p;
}

void quicksort(int *niz, int levi, int desni)
{
	if(levi<desni){
		int partIndeks = particionisanje(niz,levi,desni);
		quicksort(niz,levi,partIndeks-1);
		quicksort(niz,partIndeks+1,desni);
	}
}

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main ()
{
	int i, *niz, n;
	scanf("%d", &n);
	
	niz=malloc(n*sizeof(int));
	if(niz==NULL)
		greska();
		
	for(i=0; i<n; i++){
		scanf("%d", &niz[i]);
	}
	
	quicksort(niz, 0, n-1);
	
	for(i=0;i<n;i++)
		printf("%d ", niz[i]);
	printf("\n");
	
	free(niz);
	return 0;
}

