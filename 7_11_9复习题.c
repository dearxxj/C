#include <stdio.h>
int main(void)
{	
	char ch;
		
	while ((ch = getchar()) != '#') {
		if (ch != '\n')
		{
			printf("step 1\n");
			if (ch == 'b')
				break;
			else if (ch != 'c') {		
				if (ch != 'g')
					printf("step 2\n");			
				printf("step 3\n");
			}
			
		}	
	}
	printf("done\n");
	return 0;
}
