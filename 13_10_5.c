#include <stdio.h>
#include <stdlib.h>
int in_line(char ch, char *line);
int main(int argc, char *argv[])
{
	FILE *fp;
	char line[256];
	
	if (argc == 3)
	{
		if((fp = fopen(argv[2], "r")) == NULL)
		{
			printf("Can't open %s", argv[2]);
			exit(1);
		}
		while (fgets(line, 256, fp) != NULL) 
		{
			if (in_line(*argv[1], line))
				fputs(line, stdout);
		}
	}
	else if (argc == 1)
	{
		printf("ERROR ! Try it in command line!");
		exit(1);
	}
	else 
	{
		printf("ERROR ! inproper number of arguement!");
		exit(2);
	}
	return 0;
}

int in_line(char ch, char *line)
{
	for (; *line != '\0'; line++)
		if (*line == ch)
			return 1;
	return 0;
}

