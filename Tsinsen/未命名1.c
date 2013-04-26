#include <stdio.h>
#include <string.h>
int power(int, int);
int main(void)
{
	char str[9];
	long long num;
	int i;
	int len;
	long long sum = 0;
	
	scanf("%s", str);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] > 64)
			num = str[i] - 'A' + 10;
		else
			num = str[i] - '0';
		sum += num * power(16, len - 1 - i);
	}
	printf("%lld", sum);
	return 0;
}

int power(int n, int p)
{
	long sum = 1;
	int i;
	
	for (i = 0; i < p; i++)
		sum *= n;
	return sum;
}
