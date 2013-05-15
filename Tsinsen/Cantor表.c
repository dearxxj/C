#include <stdio.h>

int main(void)
{
	int n;
	int sum = 0, k = 0;
	
	scanf("%d", &n);
	while (sum < n)
	{
		k += 1;
		sum += k;
	}
	if (k%2 == 0)
		printf("%d/%d", k+n-sum, sum-n+1);
	else
		printf("%d/%d", sum-n+1, k+n-sum);
	return 0;
}

