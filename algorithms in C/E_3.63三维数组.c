#include <stdio.h>
#include <stdlib.h>
int ***malloc3d(int, int, int); 
int main(void)
{
	int r, c, h;
	int i, j, k;
	int ***matrix;
	
	scanf("%d%d%d", &r, &c, &h);
	matrix = malloc3d(r, c, h);
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			for (k = 0; k < h; k++)
				printf("%d ", matrix[i][j][k]);
			putchar('\n');
		}
		printf("\n\n");
	}
	for (i = 0; i < r; i++)// free
	{
		for (j = 0; j < c; j++)
			free(matrix[i][j]);
		free(matrix[i]);
	}
	free(matrix);//  if only this??????
	return 0;
}

int ***malloc3d(int r, int c, int h)
{
	int i, j, k;
	int ***t = (int ***)malloc(r * sizeof(int **));//第一层分配 
	for (i = 0; i < r; i++)
	{
		t[i] = (int **)malloc(c * sizeof(int *));// 第二层分配 
		for (j = 0; j < c; j++)
		{
			t[i][j] = (int *)malloc(h * sizeof(int));//第三层分配 
			for (k = 0; k < h; k++)
				t[i][j][k] = i + j + k;
		}
	}	
	return t;
}
