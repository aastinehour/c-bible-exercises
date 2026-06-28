/*
Exercise 1-5:

Modify the temperature conversion program to print the table in reverse order, that is, from 300 degress to 0.
*/

#include <stdio.h>

int main () {
	float fahr, celsius;

	printf("far --- cel\n");

	for (fahr = 300; fahr >= 0; fahr -= 25) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f\t%3.1f\n", fahr, celsius);
	}
}
