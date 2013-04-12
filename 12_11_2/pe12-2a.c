#include <stdio.h>
//#include "pe12-2a.h"

static int mode;
static float dist, fuel;

void set_mode(int inmode)
{
	if (inmode > 1) 
	{
		printf("Invalid mode specified. US mode used.\n");
		mode = 1;
	}
	else
		mode = inmode;
}

void get_info(void)
{
	switch (mode)
	{
		case 0: {
			printf("enter distance traveled in kilometers: ");
			scanf("%f", &dist);
			printf("enter fuel consumed in liters: ");
			scanf("%f", &fuel);
			break;
		}
		case 1: {
			printf("enter distance traveled in miles: ");
			scanf("%f", &dist);
			printf("enter fuel consumed in gallons: ");
			scanf("%f", &fuel);
			break;
		}
	}
}

void show_info(void)
{
	switch (mode)
	{
		case 0: printf("fuel consumption is %.1f kilometers per liter.\n", dist/fuel);break;		
		case 1: printf("fuel consumption is %.1f miles per gallon.\n", dist/fuel);break;				
	}
}
