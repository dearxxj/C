#include <stdio.h>
int isprime(int p);
int main()
{	
	int n, m, i, index;
	int prime[100];
	index = -1;
	
	while (1) {
		printf("enter a number( > 1) to find its prime factor:");
		scanf("%d", &n);
		while (n <= 1) {
			printf("invalid input number must > 1.");
			scanf("%d", &n);
		}
		m = n;
		for (i = 2; i <= n; i++)	{
			if (isprime(i) && n % i == 0) {				
				index++;
				prime[index] = i;				
				n /= i;
				i = 1;				
			}									
		}
		if (index == 0) printf("%d is a prime.\n", m);			
		else {
			for (i = 0; i <= index; i++) {
				if (i == 0) printf("%d = %d *", m, prime[i]);
				else if (i == index) printf(" %d\n", prime[i]);
				else printf(" %d *", prime[i]);	
			}
		}
		index = -1;
		prime[100] = 0;
	}
	return 0;
}

int isprime(int p)
{	
	int i;
	for (i = 2; i*i <= p + 2; i++)
		if (p % i == 0 && p != 2)
			return 0;
		else return p;
}
