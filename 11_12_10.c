#include <stdio.h>
char *pr(char *);
int main(void)
{	
	char string[40];
	
	while (1) {
		printf("enter a string.\n");
		gets(string);
		printf("in \"%s\" the first space's address is :%p\n", string, pr(string));
	}
	return 0;
} 

char *pr(char *pc)
{
	while(*pc != ' ' && *pc) {
		pc++;
	}
	if (*pc == '\0')
		return NULL;
	else return pc;
}
