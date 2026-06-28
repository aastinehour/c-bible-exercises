/*
Exercise 1-4:

Write a program to print the corresponding Celsius to Fahrenheit table.

Tip: F = (9/5) * C + 32
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
