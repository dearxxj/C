#include <stdio.h>
int step(int);
int main(void)
{
	int n;
	
	scanf("%d", &n);
	if (n >= 4 && n <= 20)
		printf("%d", step(n));
	else 
		printf("%d", 0);
	return 0;
}
int step(int n)
{
	if (1 == n)
		return 1;
	else if (2 == n)
		return 2;
	else if (3 == n)
		return 4;
	else
		return step(n-1) + step(n-2) + step(n-3);
}
