#include <stdio.h>
#include <stdlib.h>
typedef struct node { 
	int item;
	struct node *next;
}Node, *link;

int main(void)
{
	int i, N, M;
	
	scanf("%d%d", &N, &M);
	link x = malloc((N+1)*sizeof(Node));
	for (i = 1; i < N; i++)
	{
		x->item = i;
		x->next = ++x;
	}7
	x->item = N;
	x->next = x[1];
	while (N > 1)
	{
		for (i = 1; i < M; i++)
			x[]
	}
	 
	return 0;
}

