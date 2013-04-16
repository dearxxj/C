#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 40
//longest codes I have ever coded
void generate(int n, int m, int ar[n][m]);
void get_ar(FILE *fp, int ar[20][30]);
void trans_ar(int ar[20][30], char pic[20][31]);
void display_save(char pic[20][31]);
int main(void)
{
	FILE *fp;
	char fn[MAX];
	int ar[20][30];
	char pic[20][31];
	int cho;
	//set input
	printf("enter 1 to generate a random array, 2 to open a file: ");
	while(scanf("%d", &cho) != 1)
	{
		printf("invalid input, enter again(1 or 2): ");
		while (getchar() != '\n')
			continue;
	}
	if (cho == 1)
	{
		generate(20, 30, ar);
	}
	else 
	{
		puts("enter filename:");
		scanf("%s", fn);
		while ((fp = fopen(fn, "r")) == NULL)
		{
			fprintf(stderr, "Can't open %s Please enter again.\n", fn);
			scanf("%s", fn);
		}
		get_ar(fp, ar);
	}
	
	trans_ar(ar, pic);
	display_save(pic); 
	
	fclose(fp);

	return 0;
}

void generate(int n, int m, int ar[n][m])//generate and print array
{
	FILE *fp;
	int i, j;
		
	srand((unsigned int)time(0));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			ar[i][j] = rand() % 10;
			printf("%d ", ar[i][j]);
		}
		putchar('\n');
	}
		
	fp = fopen("13_11_12_array.txt", "w");//save as 13_11_12_array.txt
	for (i = 0; i < n; i++)
	{		
		for (j = 0; j < m; j++)
			fprintf(fp, "%d ", ar[i][j]);
		putc('\n', fp);
	}
	fclose(fp);
	
}

void get_ar(FILE *fp, int ar[20][30])//get array  from a file
{
	int i, j;
	
	for (i = 0; i < 20; i++)
		for (j = 0; j < 30; j++)
			fscanf(fp, "%d", &ar[i][j]);
}

void trans_ar(int ar[20][30], char pic[20][31])//transit array to picture
{
	int i, j;
	
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 30; j++)
			switch (ar[i][j])
			{
				case 0: pic[i][j] = ' ';break;
				case 1: pic[i][j] = '@';break;
				case 2: pic[i][j] = '#';break;
				case 3: pic[i][j] = '$';break;
				case 4: pic[i][j] = '%';break;
				case 5: pic[i][j] = '^';break;
				case 6: pic[i][j] = '&';break;
				case 7: pic[i][j] = '*';break;
				case 8: pic[i][j] = '+';break;
				case 9: pic[i][j] = '=';break;
			}
		pic[i][30] = '\0';
	}

}
void display_save(char pic[20][31])
{
	FILE *fp;
	int i, j;
	
	fp = fopen("13_11_12_picture.txt", "w");//save as 13_11_12_picture.txt	
	for (i = 0; i < 20; i++)
	{		
		fprintf(fp, "%s", pic[i]);
		putc('\n', fp);
		printf("%s\n", pic[i]);
	}
	fclose(fp);
}
