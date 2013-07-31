#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 200
/*used in linkage :
name : SNPs name
inname : input filename
outname: output filename
innames: input snpfile
*/
/* Copyright@dearxxj */
/*Version 1.3*/
/*1.0 basic function as extracting wanted snp from haploview files*/
/*1.1 add function of inserting r2 value "1" when snp itself*/
/*1.2 add function of inputing snplist.txt file*/
/*1.3 expand snplist from 20 to 500*/
void get_r2(char *,FILE *, FILE *);
char line[LEN];
char snplist[500][20];
int main(int argc, char *argv[]) 
{	
	FILE *in, *out;	
	char name[40], inname[40], innames[40];//
	char outname[80];	
	int snpnum = 0;
	char *ptr = NULL;
	int times = 0, i;
	if (argc != 3)
	{
		fprintf(stderr, "Invalid number %d of arguments. 3 is accepted", argc);
		exit(1);
	}
	strcpy(inname, argv[1]);
	strcat(inname, ".txt");
	if ((in = fopen(inname, "r")) == NULL)
	{
		fprintf(stderr, "Can't open the file '%s'\n", inname);
		exit(2);
	}
	strcpy(outname, argv[1]);
	strcat(outname, " with ");	
	if (strstr(argv[2], ".txt") == NULL)//输入为单个SNP 
	{		
		strcat(outname, argv[2]);
		strcat(outname, ".txt");
		if ((out = fopen(outname, "w")) == NULL)
		{
			fprintf(stderr, "Can't create output file.\n");
			exit(3);
		}
		strcpy(name, argv[2]);
		fgets(line, LEN, in);
		fputs(line, out);
		while (fgets(line, LEN, in) != NULL)
		{
			if (ptr = strstr(line, name))
			{
				if ((ptr == line) && (times == 0))
				{
					fprintf(out, "%s	%s	%d	%d	%d	%d	%d	%d\n", name, name, 1, 1, 1, 1, 1, 1);
					times = 1;
				}
				fputs(line, out);
			}
		}
	}
	else                                 //输入为snp list.txt 文件 
	{
		strcpy(innames, argv[2]);
		if (freopen(innames, "r", stdin) == NULL)
		{
			fprintf(stderr, "Can't open the file '%s'\n", innames);
			exit(4);
		}
		while (snpnum < 500 && scanf("%s", snplist[snpnum++]) != EOF);
		strcat(outname, snplist[0]);
		strcat(outname, " ect.txt");
		if ((out = fopen(outname, "w")) == NULL)
		{
			fprintf(stderr, "Can't create output file.\n");
			exit(5);
		}	
		for (i = 0; i < snpnum-1; i++)
			get_r2(snplist[i], in, out);
	}	
	printf("Done !************Copyright@dearxxj Version 1.3***************");
	fclose(in);
	fclose(out);
	return 0;
}
//找到每一个snp的r2值 
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
	fprintf(out, "\n");
	rewind(in);
}

