#include <stdio.h>
void copy(int n, int m, double (*copy)[m], double source[n][m]);
void display(int n, int m, double (*array)[m]);

int main(void)
{	
	double source[5][6] = {
	{1.1, 2.2, 3.3, 4.4, 5.5, 6.6},
	{1.2, 1.3, 5.4, 4.3, 3.2, 2.1},
	{3.4, 6.5, 7.8, 1.4, 23.3, 67.1},
	{1.4, 1.3, 5.8, 4.9, 3.2, 2.9},
	{1.1, 1.6, 5.4, 4.3, 3.4, 2.1}
	};
	double target[5][6];
	
	copy(5, 6, target, source);
	display(5, 6, target);
	return 0;
} 

void copy(int n, int m, double (*copy)[m], double source[n][m])
{
	int i, j;
	i = j = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			*(*(copy + i) + j) = source[i][j];
}

void display(int n, int m, double (*array)[m])
{
	int i, j;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) 
			printf("%.1f ", array[i][j]);
		putchar('\n');
	}		
}
