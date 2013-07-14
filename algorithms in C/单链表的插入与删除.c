#include <stdio.h>
#include <stdlib.h>
typedef struct node { 
	int item;
	struct node *next;
}Node, *link;

void insert(link L, int i, int ins);
void delitem(link L, int i);
int main(void)
{
	int n, i, ins, delindex, insindex;
	link L = malloc(sizeof(Node)), pre, cur;//L是头节点 	
	pre = L;
	pre->next = NULL;
	scanf("%d", &n);//n 个节点的链表 
	for (i = 0; i < n; i++)
	{
		cur = (link)malloc(sizeof(Node));//顺序建立链表 需要两个指针 
		scanf("%d", &cur->item);
		pre->next = cur; cur->next = NULL;
		pre = cur;
	}
	printf("insert number and index:");
	scanf("%d%d", &ins, &insindex);
	insert(L, insindex, ins);//insert  and display
	printf("\ndelete index:");
	scanf("%d", &delindex);
	delitem(L, delindex);//delete and display
	
	return 0;
}
void insert(link L, int i, int ins)//在第i位 前 插入元素 
{
	int j;
	link p, s;
	p = L; j = 0;
	while (p && j < i-1)//p 定位到第i-1位（第0位是头节点） 
	{
		p = p->next;
		j++;
	}
	if (!p || i < 1) 
		printf("ERRoR! out of index!\n");
	else
	{
		s = (link)malloc(sizeof(Node));
		s->item = ins; s->next = p->next;
		p->next = s;
	}
	//display
	p = L->next;
	while (p)
	{
		printf("%d ", p->item);
		p = p->next;
	}
	
		
}
void delitem(link L, int i)//删除第i位元素 
{
	int j;
	link p, s;
	p = L; j = 0;
	while (p && j < i-1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || i < 1) //需检查下一位是不是NULL 
		printf("ERRoR! out of index!\n");
	else
	{
		s = p->next;
		p->next = s->next;
		free(s);
	}
	//display
	p = L->next;
	while (p)
	{
		printf("%d ", p->item);
		p = p->next;
	}
	
}
