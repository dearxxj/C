#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ch;
	char filename[40];
	FILE *fp;
	int count = 0;
	
	printf("Enter filename: ");
	while (scanf("%s", filename) != 1)
	{
		printf("invalid filename.enter again: ");
	}
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Can't open %s\n", filename);
		exit(1);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("\nFile %s has %ld characters\n", filename, count);
	return 0;
}

