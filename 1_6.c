#include <stdio.h>
int main(void)
{
	printf("The value of EOF is %d\n\n", EOF);	
	while (getchar() != EOF)
		printf("The expression getchar() != EOF evaluates to %d\n", getchar() != EOF);
        
	sleep(5000);
	return 0;
}
