#include <stdio.h>
#include <stdlib.h>
typedef struct Node *link;
struct Node{
	int a;
	link next;
};
int max(link node)
{
	int u;
	if (node->next == NULL) return node->a;
	u = max(node->next);
	return node->a > u ? node->a: u;
}
int main(void)
{
	link head = NULL;
	int n;
	link x = head;
	while (scanf("%d", &n))
	{	
		link t = malloc(sizeof *t);
		if(x == NULL)
		{
			head = t; x = head; x->next= NULL;
			x->a = n;
		}
		else
		{
			x->next = t; t->next = NULL; t->a = n;
			x = t;
		}
	}
	printf("%d", max(head));
	return 0;
}

