#include <stdio.h>
#include <stdlib.h>
#include "STACK.h"

static Item *s;
static int i;
void STACKinit(int maxN)
{ 
	s = (int *)malloc(maxN * sizeof(int)); 
	i = 0; 
}
int STACKempty()
{
	return i == 0;
}
void STACKpush(Item item)
{
	s[i++] = item;
}
Item STACKpop()
{
	return s[--i];
}
