#include <stdio.h>

int Gcd(int, int);
int main(void)
{
	int a, b, c;
	
	scanf("%d%d%d", &a, &b, &c);
	
	switch (c)
	{
		case 1: printf("%d", a + b);break;
		case 2: printf("%d", a - b);break;
		case 3: printf("%d", a * b);break;
		case 4: printf("%d", a / b);break;
		case 5: printf("%d", a % b);break;
		case 6: printf("%d", Gcd(a, b));break;
		case 7: printf("%d", (a * b)/Gcd(a, b));break;
	}
	return 0;
}
int Gcd(int a, int b)
{
	if (0 == b) 
		return a;
	return Gcd(b, a % b);
}
