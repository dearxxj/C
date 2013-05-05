#include <stdio.h>

int ans1=0,ans2=0;
void dg(int x,int last,int sum)
{
	int i;
	 
	if (x==0) 
	{
		ans1++;
		ans2+=sum;
		return;
	} 
	for (i=1;i<=3;i++)
		if (x>=i && (i!=1 || i!=last)) 
		{
			if (i==1) 
				dg(x-i,i,sum+1); 
			else 
				dg(x-i,i,sum);
		}
}
int main()
{
	int n;
	scanf("%d",&n);
	dg(n,-1,0);
	printf("%d\n%d",ans1,ans2);
	return 0;
} 

