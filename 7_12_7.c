#include <stdio.h>
#define PLEVER 10.00
#define EXH (int)40
int main(void)
{	
	int h = 0;
	float tpay, apay,tax;
	const float R1 = 0.15;
	const float R2 = 0.20;
	const float R3 = 0.25;
	tpay=apay=tax=0.0; 	
	
	while (1){
	printf("how many hours do you work a week? :");
	scanf("%d", &h);
	if (h > EXH) 
		h =EXH + (h - EXH)*1.5;
	tpay = (float)h * PLEVER;
	if (tpay <= 300.0)
		tax = R1 * tpay;
	else if (tpay <= 450.0)
		tax = R1 * 300.0 + R2 * (tpay - 300.0);
	else tax = R1 * 300.0 + R2 * 150.0 + R3 * (tpay - 450.0);
	apay = tpay - tax;
	printf("total pay %.2f tax %.2f actually pay %.2f\n", tpay, tax, apay);
	}
	return 0;
}
