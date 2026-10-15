#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 63

void greska()
{
	fprintf(stderr, "-1");
	exit(EXIT_FAILURE);
}

char* sadrzi(char* s, char c)
{
	if(*s=='\0')
		return s+1;
		
	char *minp = sadrzi(s+1, c);
	
	if(*s == c)
		return s<minp ? s : minp;
	else
		return minp;
}

int main()
{
	int len;
	char s[MAX],c,*p;
	
	scanf("%s %c", s,&c);
	
	len=strlen(s)+1;
	
	p=sadrzi(s,c);
	
	if(s+len==p)
		printf("-1\n");
	else
		printf("%d\n", p-s);
		
	return 0;
}
