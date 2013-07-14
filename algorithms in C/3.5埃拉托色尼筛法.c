#include <stdio.h>
#define N 100000
int main(void)
{
	int i, j, a[N], cnt = 0;
	
	for (i = 2; i < N; i++) a[i] = 1;
	for (i = 2; i*i < N; i++)
		if (a[i])
			for (j = i; i*j < N; j++)
				a[i*j] = 0;
	for (i = 2; i< N; i++)
		if (a[i])
		{
			printf("%d ", i);
			cnt++;
		}
	printf("*******%d", cnt);
	return 0;
}

