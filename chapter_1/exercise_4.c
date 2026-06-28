/*
EXERCISE 1-4

DISPLAYS A REVERSED VERSION OF THE TABLE FROM 1-3, SHOWING CELSIUS -> FAHRENHEIGHT CONVERSIONS
*/

#include <stdio.h>

int main () {
	float fahr, celsius;
	int min, max, step;

	min = 0;
	max = 300;
	step = 25;

	celsius = min;

	printf("cel --- far\n");

	while (celsius <= max) {
		fahr = (9.0 / 5.0 * celsius) + 32;
		printf("%3.0f\t%3.1f\n", celsius, fahr);
		celsius += step;
	}
}
