#include <stdio.h>
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    printf("Fahrenheit-Celsius table\n");
    
    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = lower;
    while(fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    sleep(5000);
	return 0;
}
