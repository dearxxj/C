#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000
//used in create plink order file [geno_extract.bat]
//original file is downloaded from web into a gene.txt file
//by dearxxj 2013.7.17
int main(int argc, char *argv[])
{
	FILE *in, *out;
	char fname_in[40], fname_out[40], exname[40], gename[20];
	char fname[17] = "geno_extract.bat";
	char txstart[40];
	char chrome[3];
	char line[LEN];
	char *start;
	int i = 0, blank;
	
	if (argc != 4)
	{
		fprintf(stderr, "Error:  Invalid number of Arguments\n");
		exit(1);
	}
	strcpy(exname, argv[1]);
	strcpy(fname_in, argv[2]);
	strcat(fname_in, ".txt");
	strcpy(fname_out, argv[3]);
	strcat(fname_out, "_");
	blank = strlen(argv[3]);
	if ((in = fopen(fname_in, "r")) == NULL)
	{
		fprintf(stderr, "Can't open the file '%s'\n", fname_in);
		exit(2);
	}
	if ((out = fopen(fname, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(3);
	}
	fgets(line, LEN, in);
	while (fgets(line, LEN, in) != NULL)
	{	
		i = 0;
		start = strstr(line, "chr");
		start += 3;
		while ((*start >= '0') && (*start <= '9'))
		{
			chrome[i] = *start;
			i++;
			start++;
		}
		chrome[i] = '\0';
		while ((*start < '0') || (*start > '9'))			
			start++;
		i = 0;
		while ((*start >= '0') && (*start <= '9'))
		{
			txstart[i] = *start;
			i++;
			start++;
		}
		txstart[i] = '\0';
		while((*start > 'Z') || (*start < 'A'))
			start++;
		i = 0;
		while ((*start != '\n') && (*start != '\0'))
		{
			gename[i] = *start;
			i++;
			start++;
		}
		gename[i] = '\0';
		strcat(fname_out, gename);
		printf("%s\n", fname_out);
		fprintf(out, "plink --bfile %s --chr %s --from-bp %ld --to-bp %ld --maf 0.01 --geno 0.05 --mind 0.05 --hwe 0.0001 --recode --out %s --noweb\n", exname, chrome, atol(txstart)-250000, atol(txstart)+250000, fname_out);
		fname_out[blank + 1] = '\0';//cut fname_out to ( argv[3] + '_' )
	}
	printf("Done !  ******Gene_extract*****\n***************Copyright@dearxxj Version 1.0***************");
	fclose(in);
	fclose(out);
	return 0;
	}

