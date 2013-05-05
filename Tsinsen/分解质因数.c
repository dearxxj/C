#include <stdio.h>
int isprime(int);
void pmfactor(int);
int main(void)
{
	int a, b;
	int i;	
	
	scanf("%d%d", &a, &b);
	for (i = a; i <= b; i++)
		pmfactor(i);
	return 0;
}
void pmfactor(int n)
{
	int prime = 2;
	
	printf("%d=", n);
	while(!isprime(n))
	{
		while (prime * prime <= n)
		{
			if (isprime(prime) && (0 == n % prime))
			{
				printf("%d*", prime);
				n /= prime;
				break;
			}
			prime++;
		}
	}
	printf("%d\n", n);
}
int isprime(int n)
{
	int i;
	
	for(i = 2; i * i < n + 2; i++)
		if (0 == n % i)
			return 0;
	return 1;
}
