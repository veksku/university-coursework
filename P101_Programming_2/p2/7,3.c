#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int veci_od_proseka()
{
	int x,suma=0,i=-1;

	do{
		scanf("%d", &x);
		suma+=x;
		i++;
	} while(x);
	
	return i;
}

int main()
{
	veci_od_proseka;
	
	printf("%d\n", veci_od_proseka());
	
	return 0;
}
