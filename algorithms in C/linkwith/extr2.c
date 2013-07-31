#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 200
/*used in linkage : extract r2 from haploview files
snplist : store SNPs name
*/
/* Copyright@dearxxj */
/*Version 1.0*/
void get_r2(char *,FILE *, FILE *);
char line[LEN];
char snplist[500][20];
int main(int argc, char *argv[])
{
	FILE *in, *out;
	char InName[40], OutName[40];
	char FirSnp[40];
	char tmp[40];
	char SnpNum = 0;
	char *ptr;
	int i, j;
	if (argc != 2)
	{
		fprintf(stderr, "Invalid number %d of arguments. 2 is accepted", argc);
		exit(1);
	}
	strcpy(InName, argv[1]);
	strcat(InName, ".txt");
	strcpy(OutName, argv[1]);
	strcat(OutName, "_r2.txt");
	if (freopen(InName, "r", stdin) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'", InName);
		exit(2);
	}
	while (getchar() != '\n');//skip line 1
	scanf("%s", FirSnp);
	strcpy(snplist[0], FirSnp);
	scanf("%s", snplist[1]);
	while (getchar() != '\n');
	i = 2;
	while (scanf("%s", tmp), !strcmp(tmp, FirSnp))
	{
		scanf("%s", snplist[i++]);
		while (getchar() != '\n');
		memset(tmp, 0, 40);
	}
	if ((out = fopen(OutName, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file '%s'", OutName);
		exit(3);
	}
	fprintf(out, "r2\t");
	for (j = 0; j < i; j++)
		fprintf(out, "%s\t", snplist[j]);
	fprintf(out, "\n");
	if ((in = fopen(InName, "r")) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'", InName);
		exit(4);
	}
	for (j = 0; j < i; j++)
		get_r2(snplist[j], in, out);
	printf("Done !\n");
	printf("**********************************************\n");
	printf("*                                            *\n");
	printf("*            Extr2 Version 1.0               *\n");
	printf("*            Copyright@dearxxj               *\n");
	printf("*                                            *\n");
	printf("**********************************************\n");
	fclose(stdin);
	fclose(in);
	fclose(out);
	return 0;
}

void get_r2(char *snp, FILE *in, FILE *out)
{
	int times = 0, space;
	char *ptr;
	char ch;
	char r2[10];
	int i;
	fprintf(out, "%s\t", snp);
	while (fgets(line, LEN, in) != NULL)
	{
		i = 0;
		space = 0;
		if (ptr = strstr(line, snp))
		{
			if ((ptr == line) && (times == 0))
			{
				fprintf(out, "%d\t", 1);
				times = 1;
			}
			ptr = line;
			while (space < 4)//用来定位r2 
			{
				if ((*ptr == ' ') || (*ptr == '\t'))
					space++;
				ptr++;
			}
			while ((*ptr != ' ') && (*ptr != '\t'))
			{
				r2[i++] = *ptr;
				ptr++;
			}
			r2[i] = '\0';
			fprintf(out, "%s\t", r2);
		}
		for (i = 0; i < 20; i++)
			r2[i] = '0';
	}
	if (times == 0)
		fprintf(out, "1");
	fprintf(out, "\n");
	rewind(in);
}
