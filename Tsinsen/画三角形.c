#include <stdio.h>
void draw(int x);
int main(void)
{
	int x;
	
	scanf("%d", &x);
	draw(x);
	return 0;
}

void draw(int x)
{     
	printf("%c", 'A' + x - 1);
	if (1 != x)
		return draw(x - 1);
	printf("%c", 'A' + x - 1);		
}
