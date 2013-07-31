#include <stdio.h>
#include <stdlib.h>
#include "POLY.h"
#define MAXBIT 1000
int n[MAXBIT], m[MAXBIT];
int main(void)
{
	int Nlen, Mlen;
	char ch, oprt;
	Poly t, x;
	int i;
	Nlen = Mlen = 0;
	
	printf("Enter two long integers formula like (a+b OR a*b):\n");
	
	while (((ch = getchar()) >= '1') && (ch <= '9'))
		n[Nlen++] = ch - '0';
	while ((ch < '1') || (ch > '9'))
	{
		if ((ch == '+') || (ch == '*'))
			oprt = ch;
		ch = getchar();
	}
	while ((ch >= '1') && (ch <= '9'))
	{
		m[Mlen++] = ch - '0';
		ch = getchar();
	}
	for (i = Nlen - 1, t = POLYterm(0, Nlen - 1); i >= 0; i--)
		t->a[i] = n[i];
	for (i = Mlen - 1, x = POLYterm(0, Mlen - 1); i >= 0; i--)
		x->a[i] = m[i];
	if ('+' == oprt)
		POLYshow(POLYadd(t, x));
	else if ('*' == oprt)
		POLYshow(POLYmult(t, x));	
	
	return 0;
}

