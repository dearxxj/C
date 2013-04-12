#include <stdio.h>
//#include "pe12-2a.h"
#include "pe12-2a.c"

int main(void)
{	
	int mode;
	
	printf("enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while (mode >= 0) 
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("enter 0 for metric mode, 1 for US mode: ");
		printf("(-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}
