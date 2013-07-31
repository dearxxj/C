#include <stdio.h>

int gcd(int n, int m)
{
	printf("gcd(%d, %d)\n", n, m);
	if (m == 0) return n;
	return gcd(m, n % m);
}

int main(void)
{
	int x, y;
	
	scanf("%d %d", &x, &y);
	gcd(x, y);
	return 0;
}

