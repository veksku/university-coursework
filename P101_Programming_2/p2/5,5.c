#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 63

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int broj_pojavljivanja(char* s1, char*s2)
{
	unsigned len = strlen(s1);
	
	if(strlen(s2)<len)
		return 0;
	
	if(strncmp(s1,s2,len)==0)
		return 1 + broj_pojavljivanja(s1, s2+1);
	else
		return broj_pojavljivanja(s1,s2+1);
		
	
}

int main()
{
	char s1[MAX],s2[MAX];
	
	scanf("%s %s", s1, s2);
	
	printf("%d\n", broj_pojavljivanja(s1,s2));
	
	return 0;
}
