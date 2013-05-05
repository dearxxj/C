#include <stdio.h>

int main(void)
{
	int i, j, k, l;
	
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			for (k = 0; k < 4; k++)
				for (l = 0; l < 4; l++)
					printf("%c%c%c%c\n", 'A'+i, 'A'+j, 'A'+k, 'A'+l);
	return 0;
}

