#include <stdio.h>

int main(void)
{
	int i, j, N, M, cnt;
	
	scanf("%d", &M);
	int a[M], p[M];
	for (i = 0; i < M; i++) p[i] = 0;
	for (N = 100; N <= M; N += 100)//ÿ��100���С��N���������� 
	{
		cnt = 0;
		for (i = 2; i < N; i++) a[i] = 1;
		for (i = 2; i*i < N; i++)
			if (a[i])
				for (j = i; i*j < N; j++)
					a[i*j] = 0;
		for (i = 2; i< N; i++)
			if (a[i])
				cnt++;
		p[N] = cnt;
	}
	for (i = 100; i <= M; i += 100)//��ӡi-100��i֮��������ĸ��� 
		printf("%2d %d\n", i, p[i]-p[i-100]);		
	return 0;
}

