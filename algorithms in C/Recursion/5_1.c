#include <stdio.h>
#include <math.h>

double lg(int N)
{
	if (1 == N) return 0.0;
	else return log10(N)+lg(N-1);
}
int main(void)
{
	int x;
	
	scanf("%d", &x);
	printf("%.6f", lg(x));
	return 0;
}


