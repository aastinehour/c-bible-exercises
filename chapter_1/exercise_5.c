/*
EXCERCISE 1-5

MODIFY THE TEMPERATURE CONVERSION PROGRAM TO PRINT THE TABLE IN REVERSE ORDER, THAT IS, FROM 300 DEGRESS TO 0

NOW USES A FOR() LOOP
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
