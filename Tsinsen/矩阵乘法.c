#include <stdio.h>
void matrix(int n, int origin[n][n], int factor[n][n]);
int main(void)
{
	int n, m;	
	int i, j;
	
	scanf("%d%d", &n, &m);
	int origin[n][n];
	int factor[n][n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			scanf("%d", &origin[i][j]);
			factor[i][j] = origin[i][j];
		}
	if (0 == m)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				origin[i][j] = (i == j) ? 1 : 0;
	}
	for (i = 1; i < m; i++)
		matrix(n, origin, factor);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", origin[i][j]);
		putchar('\n');
	}
	return 0;
}
void matrix(int n, int origin[n][n], int factor[n][n])
{
	int i, j, k;
	int newmatrix[n][n];
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			newmatrix[i][j] = 0;
			for (k = 0; k < n; k++)
				newmatrix[i][j] += origin[i][k]*factor[k][j];
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			origin[i][j] = newmatrix[i][j];
}
