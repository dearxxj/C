#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
typedef struct QUEUEnode *link;
struct QUEUEnode {
	Item item;
	link next;	
};
static link head, tail;
link NEW(Item item, link next)
{
	link x = malloc(sizeof *x);
	x->item = item; x->next = next;
}
void QUEUEinit(int maxN)
{
	head = NULL;
}
int QUEUEempty()
{
	return head == NULL;
}
void QUEUEput(Item item)
{
	if (head == NULL)
	{
		head = (tail = NEW(item, head));
		return;
	}
	tail->next = NEW(item, tail->next);
	tail = tail->next;
}
Item QUEUEget()
{
	Item item = head->item;
	link t = head->next;
	free(head); head = t;
	return item;
}
void QUEUEdisplay()
{
	link ptr;
	ptr = head;
	while (ptr)
	{
		printf("%c ", ptr->item);
		ptr = ptr->next;
	}
	putchar('\n');
}
