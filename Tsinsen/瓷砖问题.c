#include <stdio.h>

int f(int );
int F(int );
int main(void)
{
	int n;
	scanf("%d", &n);
	
	printf("%d", f(n));
	return 0;
}
int f(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else if(n == 3)
		return 3;
	else
		return f(n-3) + f(n-2) + f(n-1) - F(n-1);
}
int F(int n)
{
	if (n == 1 )
		return 1;
	else
		return f(n-1) - F(n-1);
}
