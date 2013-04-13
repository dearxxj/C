#include <stdio.h>
int main()
{
	int c;
    int inspace;
    
    inspace = 0;
    while ((c = getchar()) != EOF)
    {	
		if (c == ' ')
		{	
            if (inspace == 0)
			{
				inspace = 1;
                putchar(c);
            }
        }
        if (c != ' ')
        {
			inspace = 0;
            putchar(c);
        }
    }
	sleep(5000);
	return 0;
}
