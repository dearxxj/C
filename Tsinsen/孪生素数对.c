#include <stdio.h>

int main(void)
{
	int a, b, i;
	int status = 0;
	int find = 0; 
	
	scanf("%d%d", &a, &b);
	i = a;
	if (1 == i)
		i++;
	while (i <= b)
	{
		if (isprime(i) && 0 == status)
		{
			i += 2;
			status = 1;
		}
		else if (isprime(i) && 1 == status)
		{
			printf("%d %d\n", i - 2, i);
			status = 0;
			find = 1;
		}
		else
		{
			i++;
			status = 0;
		}
	}
	if (0 == find)
		printf("%d", -1);
	return 0;
}

int isprime(int n)
{
	int i;
	
	for (i = 2; i * i < n + 3; i++)
		if (0 == n % i)
			return 0;
	return 1;
}
