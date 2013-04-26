#include <stdio.h>

int main(void)
{
	int n;
	int i, j;
	
	scanf("%d", &n);
	while (n < 1 || n > 34)
		scanf("%d", &n);
	int a[n+1][n+1];
	
	for (i = 1; i < n + 1; i++)
	{
		a[i][1] = a[i][i] = 1;
		for (j = 2; j < i; j++)
			a[i][j] = a[i-1][j] + a[i-1][j-1];
		for (j = 1; j < i; j++)
			printf("%d ", a[i][j]);
		printf("%d\n", a[i][i]);		
	} 
	return 0;
}

