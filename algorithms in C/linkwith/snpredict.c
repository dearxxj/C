#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*use (R2 - r2) ^ 2 to predict the most perfectly matched snp */
/*Copyrigh@dearxxj
  Version 1.3*/
/*1.3 add function of extract deltasq < 0.1*/
void get_r2(char *, char *);
void calcu_delta(int );
void get_delta(char *, char *);
int find(char *);
struct SnpCandidate {//j
	char name[20];
	float R2;
	float P;
	float delta;
} SnpCand[50], tmp;
static int i, j, k;
float AllR2[500];//i is permamnent
float Snpr2[500];//k is dynamic
float RMax;
int main(int argc, char *argv[])
{

	FILE *out;
	char TmpItem[20];
	char TmpName[20];
	float TmpP;
	int m;
	int m1, m2;
	int times = 0;
	if (argc != 4)
	{
		fprintf(stderr, "Invalid number %d of arguments. 4 is accepted", argc);
		exit(1);
	}
	//get candidate snp from file 1
	if (freopen(argv[1], "r", stdin) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'", argv[1]);
		exit(2);
	}
	while (getchar() != '\n');//skip line 1
	while (getchar() != EOF)
	{
		times = 0;
		while (times < 9)
		{
			scanf("%s", TmpItem);
			times++;
			if (times == 1) { scanf("%s", TmpName); times++; }
			if (times == 6) { scanf("%f", &AllR2[i]); times++; }
			if (times == 8)
			{
				scanf("%f", &TmpP);
				if (TmpP < 0.05)
				{
					strcpy(SnpCand[j].name, TmpName);
					SnpCand[j].R2 = AllR2[i];
					SnpCand[j++].P = TmpP;
				}
				times++;
				i++;
				memset(TmpName, 0, 20*sizeof(char));
			}
		}
		while (getchar() != '\n');
	}
	fclose(stdin);
	//RMax used in r2 algorithm
	for (m = 0; m < i; m++)
		if (AllR2[m] > RMax)
			RMax = AllR2[m];

	for (m = 0; m < j; m++)
	{
		get_r2(SnpCand[m].name, argv[2]);
		if (k != i)
		{
			fprintf(stderr, "ERROR snp number unmatched!");
			exit(4);
		}
		calcu_delta(m);
		k = 0;
		memset(Snpr2, 0, 500*sizeof(float));
	}
	//output delta2 < 0.1
	strcat(argv[3], "_predict.txt");
	get_delta(argv[2], argv[3]);
	// sort SnpCand
	for (m1 = 0; m1 < j-1; m1++)
		for (m2 = j-1; m2 > m1; m2--)
			if (SnpCand[m2].delta < SnpCand[m2-1].delta)
			{
				tmp = SnpCand[m2];
				SnpCand[m2] = SnpCand[m2-1];
				SnpCand[m2-1] = tmp;
			}
	//output my delta
	if ((out = fopen(argv[3], "a")) == NULL)// output after delta2 < 0.1
	{
		fprintf(stderr, "Can't create output file '%s'", argv[3]);
		exit(5);
	}
	fprintf(out, "\nsnp\tR2\tdelta\tP\n");
	for (m = 0; m < j; m++)
		fprintf(out, "%s\t%f\t%f\t%f\n", SnpCand[m].name, SnpCand[m].R2, SnpCand[m].delta, SnpCand[m].P);
	printf("**********************************************\n");
	printf("*                   Done !                   *\n");
	printf("*            SnpPredict Version 1.3          *\n");
	printf("*              Copyright@dearxxj             *\n");
	printf("*                                            *\n");
	printf("**********************************************\n");
	fclose(out);

	return 0;
}


void get_r2(char *snp, char *file)
{
	char TmpSnp1[20];
	char TmpSnp2[20];
	char TmpItem[20];
	int times = 0;
	int cnt = 0;

	// get r2 value from file 2
	if (freopen(file, "r", stdin) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'", file);
		exit(3);
	}
	while (getchar() != '\n');//skip line 1
	//calculate snp number and store in cnt
	scanf("%s", TmpSnp1);
	cnt++;
	while (getchar() != '\n');
	while (scanf("%s", TmpSnp2), !strcmp(TmpSnp2, TmpSnp1))
	{
		while (getchar() != '\n');
		cnt++;
	}
	cnt++;
	rewind(stdin);
	//get r2
	while (k < cnt)
	{
		scanf("%s%s", TmpSnp1, TmpSnp2);
		if (!strcmp(TmpSnp1, snp) || !strcmp(TmpSnp2, snp))
		{
			if (!strcmp(TmpSnp1, snp) && times == 0)// in case the snp is at the beginning of the file
			{
				Snpr2[k++] = 1.0;
				times = 1;
			}
		scanf("%s", TmpItem);
		scanf("%s", TmpItem);//r2 value is in position5 so skip 2 items
		scanf("%f", &Snpr2[k++]);
		while (getchar() != '\n');
		if (k == (cnt - 1) && times == 0) // in case the snp is at the bottom of the file /*revised in version 1.1*/
				Snpr2[k++] = 1.0;
		}
		else
			while (getchar() != '\n');
		memset(TmpSnp1, 0, 20*sizeof(char));
		memset(TmpSnp2, 0, 20*sizeof(char));
	}
	fclose(stdin);
}

void get_delta(char *file, char *fileout)
{
	char TmpSnp1[20];
	char TmpSnp11[20] = {'0'};
	char TmpSnp2[20];
	char TmpItem[20];
	FILE *out1;
	int c, cnt;
	int c1;
	int times = 0;
	float delta01;
	if (freopen(file, "r", stdin) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'", file);
		exit(6);
	}
	if ((out1 = fopen(fileout, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file '%s'", fileout);
		exit(7);
	}
	for (c = 0; c < j; c++)
	{
		if (c == 0) fprintf(out1, "%10s\t", "NA");
		fprintf(out1, "%-10s\t", SnpCand[c].name);
	}
	c = 0;
	while (getchar() != '\n');
	while (c != j-1 && j)
	{
		scanf("%s", TmpSnp1);		
		if (find(TmpSnp1))
		{
			scanf("%s", TmpSnp2);
			if (strcmp(TmpSnp1, TmpSnp11))
			{
				fprintf(out1, "\n");
				times = 0;// to see if snp is the first time to appear
				cnt = 0;// to judge when to count c
			}
			strcpy(TmpSnp11, TmpSnp1);
			if (times == 0)
			{
				fprintf(out1, "%s ", TmpSnp1);
				for (c1 = 0; c1 < c; c1++)
					fprintf(out1, "%10c\t", ' ');
				fprintf(out1, "%10d\t", 1);
				times = 1;
			}
			if (find(TmpSnp2))
			{
				if (cnt == 0) 
				{
					c++;
					cnt = 1;
				}
				scanf("%s", TmpItem);
				scanf("%s", TmpItem);
				scanf("%f", &delta01);
				if (delta01 < 0.1)
					fprintf(out1, "%10.3f*\t", delta01);
				else
					fprintf(out1, "%10.3f\t", delta01);
			}
		}
		while (getchar() != '\n');
	}
	fclose(stdin);
	fclose(out1);
}

int snpcount(char *file)//calculate snp number in delta2 file
{
	int cnt = 0;
	char TmpSnp1[20];
	char TmpSnp2[20];
	
	if (freopen(file, "r", stdin) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'", file);
		exit(4);
	}
	while (getchar() != '\n');
	scanf("%s", TmpSnp1);
	cnt++;
	while (getchar() != '\n');
	while (scanf("%s", TmpSnp2), !strcmp(TmpSnp2, TmpSnp1))
	{
		while (getchar() != '\n');
		cnt++;
	}
	cnt++;
	fclose(stdin);
	return cnt;
}

int find(char *snp)
{
	int y;
	for (y = 0; y < j; y++)
		if (!strcmp(snp, SnpCand[y].name))
			return 1;
	return 0;
}

void calcu_delta(int n)
{
	int t;
	float sum = 0.0;
	float Rsq = SnpCand[n].R2;
	for (t = 0; t < i; t++)
		sum += (Snpr2[t]*Rsq/RMax - AllR2[t]/RMax) * (Snpr2[t]*Rsq/RMax - AllR2[t]/RMax);// use a optimized algorithm : divide the sum by
																	     //number of snps to evaluate the divergence /*revised in version 1.2*/
	SnpCand[n].delta = sum / (float)i;
}

