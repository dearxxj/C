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
//....version 2.1....
//extract snp r2 and display
//....version 2.2....
//add R2 in the first column
//....version 2.3....
//add snp number checker
//....version 2.4....
//add snp name is the first row
//....version 2.5....
//add snp P value in the last row
//....version 2.6....
//add a threshold argument 
//....version 2.7....
//enlarge snp volume(candidate 200, all snp 1500), this may cause some weired problems
//one idea-_- can I use malloc instead of global array to store snp value?

struct SnpCandidate {
	char name[20];
	double R2;
	double P;
} snpcand[200];//i

int snpstore[200];//j
char snp[50][20];//k store snp1, snp2 .......in it
char rSnp[1500][20];
float r2[50][1500];//n, l store r2 for each snpcandidate
//double ToR2[1500];//l
//double ToP[1500];//l

static int i, j, k, l;
static int r2_num;
char **myargv;
double threshold;

void set_snpstore(char *);
int insnpstore(char *);
void recurse(int );
int get_id(char *);
void extr2(int );
int r2_number(void);


int main(int argc, char *argv[])
{
	char TmpItem[20];
	char TmpName[20];
	FILE *out;
	double TmpP;
	int n, m;
	char fileout[50];	
	double *ToR2;
	double *ToP;

	if (argc != 5)
	{
		fprintf(stderr, "Invalid number %d of arguments. 4 is accepted\n", argc);
		exit(1);
	}
	myargv = argv;
	r2_num = r2_number();
	ToR2 = (double *)malloc(r2_num * sizeof(double));// malloc array  
	ToP = (double *)malloc(r2_num * sizeof(double));

	threshold = atof(argv[4]); //delta2 thresold 0.1, 0.2, or ....
	if (threshold > 0.999999)
	{
		fprintf(stderr, "Invalid threshold (< 1.0)");
		exit(-1);
	}

	strcpy(fileout, argv[3]);//second output file is like ..._predict_r2.txt
	if (freopen(argv[1], "r", stdin) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'\n", argv[1]);
		exit(2);
	}
	
	while (getchar() != '\n');//skip line 1
	while (getchar() != EOF)
	{
		scanf("%s", TmpItem);
		scanf("%s", TmpName);//snp name
		scanf("%s", TmpItem);scanf("%s", TmpItem);scanf("%s", TmpItem);scanf("%s", TmpItem);
		scanf("%lf", &ToR2[l]);//snp R2 double type
		scanf("%s", TmpItem);
		scanf("%lf", &TmpP);//snp P double type
		ToP[l] = TmpP;
		if (TmpP < 0.05)
		{
			strcpy(snpcand[i].name, TmpName);
			snpcand[i].R2 = ToR2[l];
			snpstore[j++] = i;
			snpcand[i++].P = TmpP;
		}
		l++;
		while (getchar() != '\n');
	}	
	fclose(stdin);

	//examine whether the snpnumber from two files are matched
	if (l != r2_num)
	{
		fprintf(stderr, "Error! snp number unmatched\n");
		exit(9);
	}
	
	strcat(myargv[3], "_predict.txt");
	if ((out = fopen(myargv[3], "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file '%s'\n", myargv[3]);
		exit(6);
	}
	fclose(out);
	
	//find all candidate snps and their linked snps(delta2 > 0.1)
	if (j) 
		recurse(j);	
	//output all candidate snps with their delta2
	for (n = 0; n < k; n++)
		extr2(n);
	//display r2	
	
	strcat(fileout, "_predict_r2.txt");
	if ((out = fopen(fileout, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file '%s'\n", fileout);
		exit(7);
	}

	fprintf(out, "SNP\tR2\t");
	for (n = 0; n < k; n++)
		fprintf(out, "%s\t", snp[n]);
	fprintf(out, "P\n");
	for (m = 0; m < l; m++)
	{
		fprintf(out, "%s\t%8g\t", rSnp[m], ToR2[m]);
		for (n = 0; n < k; n++)
			fprintf(out, "%g\t", r2[n][m]);
		fprintf(out, "%8g", ToP[m]);
		fprintf(out, "\n");
	}

	free(ToR2);
	free(ToP);
	fclose(out);
	
	printf("**********************************************\n");
	printf("*                   Done !                   *\n");
	printf("*            SnpPredict Version 2.7          *\n");
	printf("*              Copyright@dearxxj             *\n");
	printf("*                                            *\n");
	printf("**********************************************\n");
	return 0;
}

void recurse(int cnt)
{
	FILE *out;
	double maxR = 0.0;
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
	strcpy(snp[k++], snpcand[maxT].name);//store the first snpcand(biggest R2) in snp[50][20]
	set_snpstore(snpcand[maxT].name);//set maxR snp snpstore value as -1
	cnt--;//exclude maxT itself
	tmpcnt = cnt;

	if ((out = fopen(myargv[3], "a")) == NULL)
	{
		fprintf(stderr, "Can't create output file '%s'\n", myargv[3]);
		exit(3);
	}
	fprintf(out, "-----------------------------------------------------------------------------\n");
	fprintf(out, "%s R(%g) P(%g)\n", snpcand[maxT].name, snpcand[maxT].R2, snpcand[maxT].P);
	fclose(out);
	if (freopen(myargv[2], "r", stdin) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'\n", myargv[2]);
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
			if (delta2 > threshold + 0.000001)//to exclude the case that delta2 exactly equal to 0.100000
				if (!strcmp(TmpSnp1, snpcand[maxT].name))
				{ 
					out = fopen(myargv[3], "a");
					id = get_id(TmpSnp2);
					fprintf(out, "%s\t%g\tR(%8g)\tP(%8g)\n", TmpSnp2, delta2, snpcand[id].R2, snpcand[id].P); set_snpstore(TmpSnp2); cnt--; 
					fclose(out);
				}
				else
				{ 
					out = fopen(myargv[3], "a");
					id = get_id(TmpSnp1);
					fprintf(out, "%s\t%g\tR(%8g)\tP(%8g)\n", TmpSnp1, delta2, snpcand[id].R2, snpcand[id].P); set_snpstore(TmpSnp1); cnt--; 
					fclose(out);
				}
		}
		while (getchar() != '\n');
	}
	fclose(stdin);
	recurse(cnt);
}
void extr2(int n)
{
	char TmpSnp1[20];
	char TmpSnp2[20];
	char TmpItem[20];
	int times = 0;
	int cnt = r2_num;

	// get r2 value from file 2
	if (freopen(myargv[2], "r", stdin) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'\n", myargv[2]);
		exit(6);
	}
	//get r2
	l = 0;//for each snp initialize l = 0;
	while (l < cnt)
	{
		scanf("%s%s", TmpSnp1, TmpSnp2);
		if (!strcmp(TmpSnp1, snp[n]) || !strcmp(TmpSnp2, snp[n]))
		{
			if (!strcmp(TmpSnp1, snp[n]) && times == 0)// in case the snp is at the beginning of the file
			{
				r2[n][l++] = 1.0;
				times = 1;
			}
		scanf("%s", TmpItem);
		scanf("%s", TmpItem);//r2 value is in position5 so skip 2 items
		scanf("%f", &r2[n][l++]);
		while (getchar() != '\n');
		if (l == (cnt - 1) && times == 0) // in case the snp is at the bottom of the file /*revised in version 1.1*/
				r2[n][l++] = 1.0;
		}
		else
			while (getchar() != '\n');
		memset(TmpSnp1, 0, 20*sizeof(char));
		memset(TmpSnp2, 0, 20*sizeof(char));
	}
	fclose(stdin);
}
//calculate snp number in file 2
int r2_number(void)
{
	char TmpSnp1[20];
	char TmpSnp2[20];
	int cnt = 0;

	if (freopen(myargv[2], "r", stdin) == NULL)
	{
		fprintf(stderr, "Can't open file '%s'\n", myargv[2]);
		exit(6);
	}
	while (getchar() != '\n');//skip line 1
	//calculate snp number and store in cnt
	scanf("%s", TmpSnp1);
	strcpy(rSnp[cnt++], TmpSnp1);// store snpname in rSnp
	scanf("%s", rSnp[cnt++]);
	while (getchar() != '\n');
	while (scanf("%s", TmpSnp2), !strcmp(TmpSnp2, TmpSnp1))
	{
		scanf("%s", rSnp[cnt++]);
		while (getchar() != '\n');
	}
	fclose(stdin);
	return cnt;
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