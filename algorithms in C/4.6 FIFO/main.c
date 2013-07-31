#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QUEUE.h"
#include "Item.h"

int main(void)
{
	Item str[100];
	int i, N;
	
	scanf("%s", str);
	N = strlen(str);
	QUEUEinit(N);
	for (i = 0; i < N; i++)
	{	
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			printf("%c	", str[i]);
			QUEUEput(str[i]);
			putchar('\t');
			QUEUEdisplay();
		}
		if (str[i] == '*')
		{
			printf("%c	", str[i]);
			printf("%c\t", QUEUEget());
			QUEUEdisplay();
		}
	}
	return 0;
}
