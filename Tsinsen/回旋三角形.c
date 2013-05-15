#include <stdio.h>
#include <string.h>
int main(void)
{
	int a[31][31];memset(a, 0, sizeof(a));
	int i, j;
	int n, N, count;
	
	scanf("%d", &n);
	N = n*(n+1)/2;
	a[1][1] = 1;
	count = i = j = 1;
	while (count < N)
	{
		while (i < n && a[i+1][j] == 0) a[++i][j] = ++count;
		while (j < i && a[i][j+1] == 0) a[i][++j] = ++count;
		while (i > 1 && a[i-1][j-1] == 0) a[--i][--j] = ++count;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <=i ; j++)
			printf("%-3d ", a[i][j]);
		printf("\n");	
	}
	return 0;
}

