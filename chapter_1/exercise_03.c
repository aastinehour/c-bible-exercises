/*
Exercise 1-3:

Modyify the temperature conversion program to print a heading above the table.
*/

#include <stdio.h>

int main () {
	float fahr, celsius;
	int min, max, step;

	min = 0;
	max = 300;
	step = 25;

	fahr = min;

	printf("far --- cel\n"); // <- Table heading

	while (fahr <= max) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f\t%3.1f\n", fahr, celsius);
		fahr += step;
	}
}
