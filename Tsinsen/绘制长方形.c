# include <stdio.h>
void rec(int n, int m);
int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	while (n < 1 || n > 24 || m < 1 || m > 24)
		scanf("%d %d", &n, &m);	
	rec(n, m);

	return 0;
}

void rec(int n, int m)
{
	int i, j, k;
    
    for(i = 0; i < n; i++)
    {
        j = i;
        //n < or > m��������µ�ǰ�벿�ִ�ӡ��һ�� 
        if (n <= m)
        {
        	while (j > 0)
        	{
         	   printf("%c", 'A' + j);
	         	   j--;
	        }
    	}
    	else 
    	{
			if (i < m)
			{
				while (j > 0)
				{
					printf("%c", 'A' + j);
					j--;
				}
			}
			else
			{
				k = j - m;
				while (j > k)
				{
					printf("%c", 'A' + j);
					j--;
				}	
			}
		}
		//��벿�ִ�ӡһ���� 
        while (j < m - i)
        {
            printf("%c", 'A' + j);
            j++;
        }
        putchar('\n');
    }
}

