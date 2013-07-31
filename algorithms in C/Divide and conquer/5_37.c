#include <stdio.h>
int knowF[1000] = {0};
int F(int i)
{
	if (knowF[i] != 0) return knowF[i];
	if (i == 0) return 0;
	if (i == 1) return 1;
	if (i > 1) return knowF[i] = F(i-1) + F(i-2);
}
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	N = F(N);
	printf("%d", N - N/M*M);
	return 0;
}

