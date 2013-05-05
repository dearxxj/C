#include <stdio.h>
int primesum(int);
int isprime(int);
int main(void)
{
	int sum = 0;
	int i = 0;
	int i;
	int num[100];
	
	scanf("%d", &num[0]);
	while(num[i] && i < 100)
		scanf("%d", &num[++i]);
	for (i = 0; i < i; i++)
		printf("%d\n", primesum(num[i]));
	return 0;
}
int primesum(int n)
{
	int sum = 0;
	int i;
	for (i = 1; i <= n; i++)
		if (isprime(i))
			sum += i;
	return sum;
} 
int isprime(int n)
{
	int i;
	if (1 == n)
		return 0;
	for (i = 2; i * i < n + 2; i++)
		if (0 == n % i)
			return 0;
	return 1;
}
