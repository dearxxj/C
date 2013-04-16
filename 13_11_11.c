#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(int argc, char *argv[])
{
	char line[MAX];
	FILE *fp;
	int status = 0;
	if (argc != 3)
	{
		puts("ERROR! improper arguments!");
		exit(1);
	}
	
	fp = fopen(argv[2], "r");
	printf("%s is included in the following sentenses:\n", argv[1]);
	while (fgets(line, MAX, fp) != NULL)
	{
		if (strstr(line, argv[1]))
		{			
			status = 1;
			fputs(line, stdout);
		}
	}
	if (status == 0)
		printf("Can't find %s in %s\n", argv[1], argv[2]);
	return 0;
}

