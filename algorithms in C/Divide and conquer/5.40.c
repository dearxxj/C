#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int knowP[1000] = {0};
int P(int i)
{
	if (knowP[i] != 0) return knowP[i];
	if (i == 0 || i == 1) return 0;
	else if (i % 2 == 0)
		return knowP[i] = i/2 + P(i/2) + P(i/2);
	else
		return knowP[i] = i/2 + P(i/2) + P(i/2 + 1);
}

int main(void)
{
	int N, i;
	FILE *out;
	
	scanf("%d", &N);
	if ((out = fopen("data.txt", "w")) == NULL)
	{
		fprintf(stderr, "can't create file 'data.txt'");
		exit(1);
	}
	for (i = 0; i <= N; i++)
	{	
		printf("%d	%.6f\n", i, P(i) - i * log10(i/2.0));
		fprintf(out, "%d	%.6f\n", i, P(i) - i * log10(i/2.0));
	}
	fclose(out);
	return 0;
}

