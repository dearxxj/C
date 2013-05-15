#include <stdio.h>

int main(void)
{
	int ch;
	int tail;
	int gc, all;
	
	gc = all = 0;
	while ((ch = getchar()) != '\n')
	{
		if ('G' == ch || 'C' == ch)
			gc++;
		all++;
	}
	
	tail = (2*(all%gc) >= gc) ? 1: 0;
	printf("%d", (100*gc/all) + tail);
	return 0;
}

