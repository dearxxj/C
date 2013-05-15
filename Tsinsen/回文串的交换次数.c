#include <stdio.h>
//交换相邻两个数获得回文字符串的最少交换次数 
//此题可用递归吗？？？ 
int exc_tms(char s[], int, int);
int main(void)
{
	int n;
	int ans = 0, ans0 = 1;
	int find, notfind = 0;
	int i, k;
	
	scanf("%d", &n);
	char str[n];
	scanf("%s", str);
	if (0 == n%2)//分奇偶的情况 
		for (i = 0; i < n/2; i++)
		{
			find = 0;
			for (k = n-1-i; k > i; k--)
			{
				if (str[k] == str[i])
				{
					ans += exc_tms(str, k, n-1-i);//把和i位相同的元素放到n-1-i处 
					find = 1;
					break;
				}
			}
			if (0 == find)
			{
				printf("Impossible");
				ans0 = 0;
				break;
			}			
		}
	else
		for (i = 0; i < n/2; i++)
		{
			find = 0;
			for (k = n-1-i; k > i; k--)
			{
				if (str[k] == str[i])
				{
					ans += exc_tms(str, k, n-1-i);
					find = 1;
					break;
				}
			}
			if (0 == find && 1 == notfind)//元素仅出现出现一次的个数的多于一个则不能形成回文 
			{
				printf("Impossible");
				ans0 = 0;
				break;
			}
			else if (0 == find && 0 == notfind)
			{
				notfind = 1;
				ans += n/2 - i;//把该元素放回字符串中间的次数 
				n++;    //先跳过此元素，将后面的n-2i+1个元素排成回文 
			}			
		}
	if (ans0)
		printf("%d", ans);
	return 0;
}

int exc_tms(char s[], int a, int b)//把s[a]交换到s[b]返回其次数 
{
	char tmp;
	int i;
	for (i = a; i < b;i++)
	{
		tmp = s[i];
		s[i] = s[i+1];
		s[i+1] = tmp;
	}
	return b-a;
}

