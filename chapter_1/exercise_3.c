/*
EXERCISE 1-3

DISPLAYS A CONVERSION TABLE OF FAHRENHEIGHT TO CELSIUS
*/

#include <stdio.h>

int main () {
	float fahr, celsius;
	int min, max, step;

	min = 0;
	max = 300;
	step = 25;

	fahr = min;

	printf("far --- cel\n");

	while (fahr <= max) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f\t%3.1f\n", fahr, celsius);
		fahr += step;
	}
}
