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
        //n < or > m两种情况下的前半部分打印不一样 
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
		//后半部分打印一样的 
        while (j < m - i)
        {
            printf("%c", 'A' + j);
            j++;
        }
        putchar('\n');
    }
}

