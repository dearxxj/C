#include <stdio.h>
#include <stdlib.h>
int heads()
{
	return rand() < RAND_MAX/6;//正面概率为1/6或者其他 
}
int main(void)
{
	int i, j, cnt;
	int N, M;
	
	scanf("%d%d", &N, &M);
	int *f = malloc((N+1)*sizeof(int));
	for (j = 0; j <= N; j++) f[j] = 0;
	for (i = 0; i < M; i++, f[cnt]++)
		for (cnt = 0, j = 1; j <= N; j++)
			if (heads())
				cnt++;
	for (j = 0; j <= N; j++)
	{
		printf("%2d", j);
		for (i = 0; i < f[j]; i += 10)
			printf("*");
		printf("\n");
	}
	
	return 0;
}

