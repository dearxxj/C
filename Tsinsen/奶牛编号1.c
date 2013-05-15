#include <stdio.h>
//next prime like 2,3,5,7,11,13......
int main(void)
{
	int n;
	int i, j = 0, find = 0;
	
	scanf("%d", &n);
	
	while (0 == find)
	{
		j++;
		find = 1;
		for (i = 2; i*i <= n+j; i++)
			if (0 == (n+j)%i)
			{
				find = 0;
				break;
			}		
	}
	printf("%d", n+j);
	return 0;
}

