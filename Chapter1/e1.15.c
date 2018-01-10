/*
 * Exercise 1.15
 * Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion
 */
#include <stdio.h>

#define LOWER 0 // lower limit of temperature table
#define UPPER 300 // upper limit
#define STEP 20 // step size

float ftoc (int fahr);

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, .., 300
 */
int main (void)
{
	int fahr;
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d\t%6.1f\n", fahr, ftoc(fahr));

	return 0;
}

/* converts Fahrenheit to Celius
 */
float ftoc (int fahr)
{
	float celsius = (5.0 / 9.0) * (fahr - 32.0);
	return celsius;
}
