#include <stdio.h>
char *a;
int i;

int eval()
{	
	int x = 0;
	while (a[i] == ' ') i++;
	if (a[i] == '+')
	{
		i++;
		return eval() + eval();
	}
	if (a[i] == '*')
	{
		i++;
		return eval() * eval();
	}
	while ((a[i] >= '1') && (a[i]) <= '9')
		x = 10 * x + (a[i++] - '0');
	return x;
}
int main(void)
{
	char str[100];
	char ch;
	i = 0;
	while ((ch = getchar()) != '\n')
		str[i++] = ch;
	a = str;
	printf("%d", eval());
	return 0;
}

