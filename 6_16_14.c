#include <stdio.h>
#include <string.h>
int main(void) 
{
	char line[255];
	int i;
	
	scanf("%[^\n]",line);
	i = strlen(line);
	while (i-- > 0) 
		putchar(line[i]);
}
