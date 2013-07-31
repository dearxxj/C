#include <stdio.h>
#include <stdlib.h>
#include "STACK.h"

static Item *s;
static int i;
void STACKinit(int maxN)
{ 
	s = (Item *)malloc(maxN * sizeof(Item)); 
	i = 0; 
}
int STACKempty()
{
	return i == 0;
}
void STACKpush(Item item)
{
	if (i > Nmax)
		STACKerror("STACK full !");
	s[i++] = item;
}
Item STACKpop()
{
	if (i == 0)
		STACKerror("STACK empty !");
	return s[--i];
}
void STACKerror(char *s)
{
	printf("%s", s);
	exit(1);
}
