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
    printf("空格：%d 制表符：%d 换行：%d", space, tab, enter);
    
	sleep(5000);
	return 0;
}
