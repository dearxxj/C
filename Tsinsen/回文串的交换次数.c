#include <stdio.h>
//����������������û����ַ��������ٽ������� 
//������õݹ��𣿣��� 
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
	if (0 == n%2)//����ż����� 
		for (i = 0; i < n/2; i++)
		{
			find = 0;
			for (k = n-1-i; k > i; k--)
			{
				if (str[k] == str[i])
				{
					ans += exc_tms(str, k, n-1-i);//�Ѻ�iλ��ͬ��Ԫ�طŵ�n-1-i�� 
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
			if (0 == find && 1 == notfind)//Ԫ�ؽ����ֳ���һ�εĸ����Ķ���һ�������γɻ��� 
			{
				printf("Impossible");
				ans0 = 0;
				break;
			}
			else if (0 == find && 0 == notfind)
			{
				notfind = 1;
				ans += n/2 - i;//�Ѹ�Ԫ�طŻ��ַ����м�Ĵ��� 
				n++;    //��������Ԫ�أ��������n-2i+1��Ԫ���ųɻ��� 
			}			
		}
	if (ans0)
		printf("%d", ans);
	return 0;
}

int exc_tms(char s[], int a, int b)//��s[a]������s[b]��������� 
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

