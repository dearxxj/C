#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*snpredict version 2.0*/
/*Copyright@dearxxj*/
//first pick the biggest R2
//group other candidate snp by the delta2 value(> 0.1) with it which means they are in the same family
//recurse the up two steps
//so we may have several groups like:
//			snp1 R2 P
//				snp3 delta2 (>0.1) R2 P
//				snp6 ..................	
//			snp2 R2 P
//				.......................
//			...........................
struct SnpCandidate {
	char name[20];
	float R2;
	float P;
} snpcand[50];//i

int snpstore[50];//j
static int i, j;
char **myargv;

void set_snpstore(char *);
int insnpstore(char *);
void recurse(int );
int get_id(char *);

int main(int argc, char *argv[])
{
	char TmpItem[20];
	char TmpName[20];
	FILE *out;
	float TmpP;
	float TmpR;
	int times = 0;
	if (argc != 4)
	{
		fprintf(stderr, "Invalid number %d of arguments. 4 is accepted", argc);
		exit(1);
	}
	myargv = argv;
	if (freopen(argv[1], "r", stdin) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'", argv[1]);
		exit(2);
	}
	while (getchar() != '\n');//skip line 1
	while (getchar() != EOF)
	{
		times = 0;
		while (times < 9 && i < 50)
		{
			scanf("%s", TmpItem);
			times++;
			if (times == 1) { scanf("%s", TmpName); times++; }
			if (times == 6) { scanf("%f", &TmpR); times++; }
			if (times == 8)
			{
				scanf("%f", &TmpP);
				if (TmpP < 0.05)
				{
					strcpy(snpcand[i].name, TmpName);
					snpcand[i].R2 = TmpR;
					snpstore[j++] = i;
					snpcand[i++].P = TmpP;
				}
				times++;
				memset(TmpName, 0, 20*sizeof(char));
			}
		}
		while (getchar() != '\n');
	}
	fclose(stdin);
	strcat(myargv[3], "_predict.txt");
	if ((out = fopen(myargv[3], "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file '%s'", myargv[3]);
		exit(6);
	}
	fclose(out);
	if (j) 
		recurse(j);	
	printf("**********************************************\n");
	printf("*                   Done !                   *\n");
	printf("*            SnpPredict Version 2.0          *\n");
	printf("*              Copyright@dearxxj             *\n");
	printf("*                                            *\n");
	printf("**********************************************\n");
	return 0;
}

void recurse(int cnt)
{
	FILE *out;
	float maxR = 0.0;
	int t, maxT = 0, tmpcnt, id;
	char TmpSnp1[20];
	char TmpSnp2[20];
	char TmpItem[20];
	float delta2;
	int c = 0;//exactly equal to j-1 if no mistake

	if (cnt == 0) return;
	for (t = 0; t < j ; t++)
		if (snpstore[t] >= 0 && snpcand[snpstore[t]].R2 > maxR)
		{
			maxR = snpcand[snpstore[t]].R2;
			maxT = snpstore[t];
		}
	set_snpstore(snpcand[maxT].name);//set maxR snp snpstore value as -1
	cnt--;//exclude maxT itself
	tmpcnt = cnt;
	if ((out = fopen(myargv[3], "a")) == NULL)
	{
		fprintf(stderr, "Can't create output file '%s'", myargv[3]);
		exit(3);
	}
	fprintf(out, "\n%s R(%f) P(%f)\n", snpcand[maxT].name, snpcand[maxT].R2, snpcand[maxT].P);
	fclose(out);
	if (freopen(myargv[2], "r", stdin) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'", myargv[2]);
		exit(4);
	}
	while (getchar() != '\n');//skip line 1
	while (c != tmpcnt)
	{
		scanf("%s", TmpSnp1);
		scanf("%s", TmpSnp2);
		if ((!strcmp(TmpSnp1, snpcand[maxT].name) && insnpstore(TmpSnp2)) || (!strcmp(TmpSnp2, snpcand[maxT].name) && insnpstore(TmpSnp1)))
		{
			c++;
			scanf("%s", TmpItem);
			scanf("%s", TmpItem);
			scanf("%f", &delta2);
			if (delta2 > 0.100001)//to exclude the case that delta2 exactly equal to 0.100000
				if (!strcmp(TmpSnp1, snpcand[maxT].name))
				{ 
					out = fopen(myargv[3], "a");
					id = get_id(TmpSnp2);
					fprintf(out, "%s\t%f\tR(%f)\tP(%f)\n", TmpSnp2, delta2, snpcand[id].R2, snpcand[id].R2); set_snpstore(TmpSnp2); cnt--; 
					fclose(out);
				}
				else
				{ 
					out = fopen(myargv[3], "a");
					id = get_id(TmpSnp1);
					fprintf(out, "%s\t%f\tR(%f)\tP(%f)\n", TmpSnp1, delta2, snpcand[id].R2, snpcand[id].R2); set_snpstore(TmpSnp1); cnt--; 
					fclose(out);
				}
		}
		//printf("%d %d\n", c, cnt);
		while (getchar() != '\n');
	}
	fclose(stdin);
	recurse(cnt);
}

//from snp name to get snp id
//this may be easier in Python which has "dict" type
int get_id(char *snp)
{
	int y;
	for (y = 0; y < i; y++)
		if (!strcmp(snp, snpcand[y].name))
			return y;
}
//set already picked snp as -1
void set_snpstore(char *snp)
{
	int y;
	for (y = 0; y < j; y++)
		if (snpstore[y] >= 0 && !strcmp(snp, snpcand[snpstore[y]].name))
		{
			snpstore[y] = -1;
			break;
		}
}

//judge if snp was in snpcand && not picked(snpstore value != -1)
int insnpstore(char *snp)
{
	int y;
	for (y = 0; y < j; y++)
		if (snpstore[y] >= 0 && !strcmp(snp, snpcand[snpstore[y]].name))
			return 1;
	return 0;
}