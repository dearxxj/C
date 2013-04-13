#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{	
	if (argc < 2)
	{
		printf("ERROR! not enough arguments");
		exit(2);
	}
	FILE *fp;
	int ch, i;
	
	for(i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			printf("Can't open %s\n", argv[i + 1]);
			continue;
		}
		while ((ch = getc(fp)) != EOF)// display new file
			putc(ch, stdout);	
	}	
	return 0;
}

