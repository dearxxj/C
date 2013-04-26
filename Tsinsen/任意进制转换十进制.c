#include <stdio.h>

int main(void)
{
	char px[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
					'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
					'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
					'U', 'V', 'W', 'X', 'Y', 'Z'};					
	long n;
	int p;
	int num[31];
	int i = 0;

	scanf("%ld %d", &n, &p);
	while (n < 0 || n > 2147483647 || p < 2 || p > 36)
		scanf("%ld %d", &n, &p);
	if (!n)
	{
		num[i] = 0;
		i++;
	}
	while (n)
	{
		num[i] = n % p;
		n /= p;
		i++;
	}	
	while (i-- > 0)
		printf("%c", px[num[i]]);
	return 0;
}

