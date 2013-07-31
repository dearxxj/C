#include <stdio.h>
//0-1 ���� 
#define MAXSIZE 2000
#define MINIMUM -1000000
#define max(A, B) (A >= B)? A: B
int size[MAXSIZE];//��Ʒ��ռ�ÿռ� 
int wealth[MAXSIZE];//��Ʒ�ļ�ֵ 
int f[200][MAXSIZE];
int f2[MAXSIZE];
int bag(int n, int v)//ǰn����Ʒǡ����һ������Ϊv�ı������Ի�õ�����ֵ
{
	int maxval = 0;
	if (v < 0) 
		return MINIMUM;
	if (n == 1 && v < size[1])
		return 0;
	if (n == 1 && v >= size[1])
		return wealth[1];
	maxval = max(bag(n-1, v-size[n]) + wealth[n], bag(n-1, v));
	return maxval;
}

int bag2(int n, int v)//DP O(n*v)
{
	int i, j;
	for (i = 0; i <= n; i++)//f[i][j] ǰi����Ʒ��������v������ֵ 
		for (j = 0; j <= v; j++)
			f[i][j] = 0;
	for (i = 1; i <= n; i++)
		for (j = 0; j <= v; j++)
		{
			if (j >= size[i])
				f[i][j] = max(f[i-1][j-size[i]] + wealth[i], f[i-1][j]);
			else
				f[i][j] = f[i-1][j];
		}
	return f[n][v];
}

int bag3(int n, int v)//O(n)
{
	int i, j;
	for (i = 0; i <= v; i++)
		f2[i] = 0;
	for (i = 1; i <= n; i++)
		for (j = v; j >= size[i]; j--)
			f2[j] = max(f2[j-size[i]] + wealth[i], f2[j]);
	return f2[v];
}

int bag4(int n, int v)//optimized bag3
{
	int i, j;
	int sum = 0, bound;
	for (i = 0; i <= v; i++)
		f2[i] = 0;
	wealth[0] = 0;
	for (i = 0; i <= n; i++)
		sum += wealth[i];
	for (i = 1; i <= n; i++)
	{
		sum -= wealth[i-1];
		bound = max(v-sum, size[i]);
		for (j = v; j >= bound; j--)
			f2[j] = max(f2[j-size[i]] + wealth[i], f2[j]);
	}
	return f2[v];
}



int main(void)
{
	int V, N;
	int i, res;
	freopen("01.txt", "r", stdin);
	while (scanf("%d%d", &V, &N) != EOF)
	{
		res = 0;
		for (i = 1; i <= N; i++)
			scanf("%d%d", &size[i], &wealth[i]);
		res = bag4(N, V);
		printf("%d\n", res);
	}
	return 0;
}

