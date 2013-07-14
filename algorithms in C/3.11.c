#include <stdio.h>
#include <stdlib.h>
typedef struct node *link;
struct node {
	int item; 
	link next;
};

int main(void)
{
	int N, i;
	struct node heada, headb;
	link t, u, x, a = &heada, b;
	scanf("%d", &N);
	for (i = 0, t = a; i < N; i++)
	{
		t->next = malloc(sizeof *t);
		t = t->next; t->next = NULL;
		t->item = rand()%1000;
		printf("%d ", t->item);
	}
	b = &headb; b->next = NULL;
	putchar('\n');
	for (t = a->next; t != NULL; t = u)
	{
		u = t->next;
		for (x = b; x->next != NULL; x = x->next)
			if (x->next->item > t->item) break;
		t->next = x->next; x->next = t;
	}
	for (x = b->next; x != NULL; x = x->next)
		printf("%d ", x->item);
	return 0;
}

