#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STACK.h"
#define Nmax 1000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(void) 
{
	int i = 0, N = 0;
	Item tmp;
	char *a = (char *)malloc(Nmax * sizeof(char));

	printf("Enter a postfix expression: \n");
	while ((a[i++] = getchar()) != '\n');
	N = i - 1;
	STACKinit(N);
	for (i = 0; i < N; i++)
	{
		if (a[i] == '+') 
		{
			STACKpush(STACKpop() + STACKpop());
			continue;// 1
		}
		if (a[i] == '*')
		{
			STACKpush(STACKpop() * STACKpop());
			continue;// 2
		}
		if (a[i] == '-') 
		{
			tmp = STACKpop();
			STACKpush(STACKpop() - tmp);
			continue;// 1
		}
		if (a[i] == '/') 
		{
			tmp = STACKpop();
			STACKpush(STACKpop() / tmp);
			continue;// 1
		}
		if ((a[i] >= '0') && (a[i] <= '9'))// 以下三行 把相邻的数字字符组合成十进制整数 
			STACKpush((Item)0);
		while ((a[i] >= '0') && (a[i] <= '9'))
			STACKpush(10*STACKpop() + (Item)(a[i++] - '0'));
		if (a[i] != ' ') i--; // 3
											//1, 2, 3 使得+*和数字之间没有空格也能运行正确 
		
	}
	printf("%d \n", STACKpop());
	return 0;
}
