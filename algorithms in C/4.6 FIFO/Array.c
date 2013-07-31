#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

static Item *q;
static int N, head, tail;
void QUEUEinit(int maxN)
{
	q = malloc((maxN + 1) * sizeof(Item));
	N = maxN + 1; head = N; tail = 0;
}
int QUEUEempty()
{
	return head % N == tail;
}
void QUEUEput(Item item)
{
	q[tail++] = item; 
	tail = tail%N;
}
Item QUEUEget()
{
	head = head % N; 
	return q[head++];
}
void QUEUEdisplay()
{
	int i;
	if (head >= tail)	
		for (i = head; i < tail + N; i++)
			printf("%c ", q[i%N]);
	else
		for (i = head; i < tail; i++)
			printf("%c ", q[i]);
	putchar('\n');
}
