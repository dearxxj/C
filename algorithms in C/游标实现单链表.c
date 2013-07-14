#include <stdio.h>
#define MAXSIZE 1000
//to actualize "(A-B) combine (B-A)" 
struct {
	int data;
	int next;
}space[MAXSIZE];
typedef int Cursor;
typedef int Elemtype;
 
void InitSpace();
int mymalloc();
void myfree(int p);
int main(void)
{
	int n, m, i, j;
	Elemtype b;//from set B
	InitSpace();
	Cursor head = mymalloc();
	Cursor r = head, p, k;
	
	printf("enter elemnum of set A and B:");
	scanf("%d%d", &m, &n);
	for (j = 1; j <= m; j++)
	{
		i = mymalloc();
		scanf("%d", &space[i].data);
		space[r].next = i; r = i;//r direct to last of set A
	}
	space[r].next = 0;
	for (j = 1; j <= n; j++)
	{
		scanf("%d", &b); 
		p = head; k = space[head].next;
		while (k != space[r].next && space[k].data != b)
		{
			p = k; k = space[k].next;//similar to p = p->next
		}
		if (k == space[r].next)// 如果space中没有b，则插入之 
		{
			i = mymalloc();
			space[i].data = b;
			space[i].next = space[r].next;
			space[r].next = i;
		}
		else//如果space中有b，则删除之
		{
			space[p].next = space[k].next;
			myfree(k);
			if (r == k) r = p;
		}
	}
	return 0;
}

void InitSpace()
{
	int i;
	for (i = 0; i < MAXSIZE-1; i++) space[i].next = i+1;
	space[MAXSIZE-1].next = 0;
}

int mymalloc(void)
{
	int p;
	p = space[0].next;//space[0]是备用空间 
	space[0].next = space[p].next;
	return p;
}

void myfree(int p)
{
	space[p].next = space[0].next; space[0].next = p;
}
