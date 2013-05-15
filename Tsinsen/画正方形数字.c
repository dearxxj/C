#include <stdio.h>
#include <string.h> 
int main(void)
{
	int a[31][31];memset(a, 0, sizeof(a));
	int count = 1;
	int i, j, n;
			
	scanf("%d", &n);
	i = j = 1;
	a[i][j] = 1;	
	while (count < n*n)
	{
		while (j < n && a[i][j+1] == 0) a[i][++j] = ++count;
		while (i < n && a[i+1][j] == 0) a[++i][j] = ++count;
		while (j > 1 && a[i][j-1] == 0) a[i][--j] = ++count;
		while (i > 1 && a[i-1][j] == 0) a[--i][j] = ++count;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%-3d ", a[i][j]);
		putchar('\n');
	}
	return 0;
}

