#include <stdio.h>
int main()
{
/*my version*//*
    int c, pc;
	pc = '\n';
    while ((c = getchar()) != EOF) {
		if(c == ' ' || c == '\n' || c == '\t')
			pc = c;
        else if ((pc == ' ' || pc == '\n' || pc == '\t') && (c != ' ' && c != '\n' && c != '\t')) {
			/*ǰһ������Ϊ��ĸ ��һ����Ϊ��ĸʱ����*//*
            putchar('\n');
            putchar(c);
            pc = c;
        }
        else 
			putchar(c);            			
    }*/

/*version on book */   
    int c, inspace;
    
    inspace = 0;
    while ((c = getchar()) != EOF) 
    {
		if (c == ' ' || c == '\n' || c == '\t')
        {
			if (inspace == 0) 
            {
				inspace = 1;
                putchar('\n');      
            }
        }
        else 
        {
			putchar(c);
            inspace = 0;
        }
	}
	sleep(5000);
	return 0;
}
