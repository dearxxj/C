#include <stdio.h>
#include <float.h>
int main(void)
{	float n1 = 1.0/3.0;
	double n2 = 1.0/3.0;
	
	printf("%d %d\n", FLT_DIG, DBL_DIG);
	printf("%.4f %.12f %.16f\n", n1, n1, n1);
	printf("%.4f %.12f %.18f\n", n2, n2, n2);
	
	return 0;
}
