/*
Exercise 1-15:

Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
*/

#include <stdio.h>

#define MIN 0
#define MAX 300
#define STEP 25

float fahr_to_celcius(int fahr);

int main () {
    printf("far --- cel\n");

    int fahr;
    for (fahr = 0; fahr <= MAX; fahr += STEP) {
        printf("%3d\t%3.1f\n", fahr, fahr_to_celcius(fahr));
    }
}

/* Takes in a fahrenheight input and returns it in celsius */
float fahr_to_celcius(int fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}