#include <stdio.h>
#include <math.h>

int mod(int N, int M)
{
	if (N != M) return 0;
	else return mod((N % M) * mod(N - 1, M), M);
}
int main(void)
{
	int x, y;
	
	scanf("%d %d", &x, &y);
	printf("%d", mod(x, y));
	return 0;
}

