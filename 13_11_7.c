#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
void diplay1(FILE *fp1, FILE *fp2);
void diplay2(FILE *fp1, FILE *fp2);

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;	
	char fn1[40], fn2[40];
	char *fpn1, *fpn2;//here to solve "can't assign array from pointer" I introduce new pointer fpn
	
	if (argc == 1) 
	{
		puts("Enter two filename separated by spaces:");
		while(scanf("%s%s", fn1, fn2) != 2) 
		{
			puts("Invalid filename Please enter again:");
			continue;
		}
		fpn1 = fn1;
		fpn2 = fn2;
	}
	else if (argc == 3) 
	{
		fpn1 = argv[1];//assign array from pointer
		fpn2 = argv[2];	
	}
	else
	{
		fprintf(stderr, "ERROR! Inproper number of arguments!");
		exit(1);
	}
	if ((fp1 = fopen(fpn1, "r")) == NULL)
	{
		printf("Cant't open %s", fn1);
		exit(2);
	}
	if ((fp2 = fopen(fpn2, "r")) == NULL)
	{
		printf("Cant't open %s", fn2);
		exit(3);
	}
	diplay1(fp1, fp2);
	puts("*********************************************");
	rewind(fp1);
	rewind(fp2);
	diplay2(fp1, fp2);
	return 0;
}

void diplay1(FILE *fp1, FILE *fp2)
{
	char line1[MAX];
	char line2[MAX];
	char *pt1, *pt2;
	
	while ((pt1 = fgets(line1, MAX, fp1)) || (pt2 = fgets(line2, MAX, fp2)))
	{
		if (pt1)
		{
			fputs(line1, stdout);
			if (fgets(line2, MAX, fp2))
				fputs(line2, stdout);
		}
		else if  (pt2)
			fputs(line2, stdout);
	}	
}

void diplay2(FILE *fp1, FILE *fp2)
{
	char line1[MAX];
	char line2[MAX];
	char *pt1, *pt2;
	char *find;
	
	while ((pt1 = fgets(line1, MAX, fp1)) || (pt2 = fgets(line2, MAX, fp2)))
	{
		if (pt1)
		{
			find = strchr(line1, '\n');//delete '\n' when using "fgets"
			if (find)
				*find = '\0';
			fputs(line1, stdout);
			if (fgets(line2, MAX, fp2))
				fputs(line2, stdout);
		}
		else if  (pt2)
			fputs(line2, stdout);
	}	
}
