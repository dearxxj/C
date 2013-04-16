#include <stdio.h>
#include <stdlib.h>
#define MAX 40
int main(void)
{
	char fn[MAX];
	FILE *fp;
	int loc;
	char ch;
	
	puts("Enter one filname:");
	scanf("%s", fn);
	while ((fp = fopen(fn, "r")) == NULL)
	{
		fprintf(stderr, "Can't open file %s.Please enter again:\n", fn);
		scanf("%s", fn);
	}
	printf("enter a location in file(q to quit) %s: ", fn);
	while (scanf("%d", &loc) == 1)
	{
		fseek(fp, (long)loc, SEEK_SET);
		while((ch = getc(fp)) != '\n' && ch != EOF)
			putc(ch, stdout);
		printf("\nenter next location in file(q to quit) %s: ", fn);
		rewind(fp);
	}
	return 0;
}

