#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//不超过8位的16进制转换为十进制 注意考虑输入值的范围！！！ 
int power(int, int);
void trans(char str[]);
int main(void)
{
	char str[7];
	int n;
	int i;
	char (*p)[7];
	
 	//set input
	while (scanf("%d", &n) != 1 || (n < 1 || n > 10))
	{
		while (getchar() != '\n')
			continue;	
	}
	p = (char (*)[7])malloc(n * 7 * sizeof(char));//a n*7 string array
	for (i = 0; i < n; i++)
		scanf("%s", p[i]);
	//output
	for (i = 0; i < n; i++)
		trans(p[i]);
	free(p);
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
void trans(char str[])
{
	char ox[8];
	long long num;
	int i;
	int len;
	long long sum = 0;
	
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] > 64)
			num = str[i] - 'A' + 10;
		else
			num = str[i] - '0';
		sum += num * power(16, len - 1 - i);
	}
	i = 0;

	if (sum == 0)
		ox[i++] = '0'; 
	while (sum > 0)
	{
		ox[i++] = '0' + (sum % 8);
		sum /= 8;	
	}
	while (i-- > 0)
		printf("%c", ox[i]);
	putchar('\n');
}
