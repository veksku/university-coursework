#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 63

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int unesiSkup(char **s, FILE* f)
{
	
}

void prebroj(char* s, int *br_slova,int *br_cifara)
{

}

int main(int argc, char* argv)
{
	FILE *f;
	char s[MAX];
	
	if(argc!=2)
		greska();
	
	strcpy(s, argv[1]);
	
	f=fopen(s, "r");
	
	unesiSkup(s,f);
	
	return 0;
}
