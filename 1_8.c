#include <stdio.h>
int main()
{
	int c, space, tab, enter;
    space = 0;
    tab = 0;
    enter = 0;
    while ((c = getchar()) != EOF) {
		if (c == ' ')
			++space;
        if (c == '	')
			++tab;
        if (c == '\n')
			++enter;
    }
    printf("�ո�%d �Ʊ����%d ���У�%d", space, tab, enter);
    
	sleep(5000);
	return 0;
}
