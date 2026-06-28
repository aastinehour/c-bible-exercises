/*
Exercise 1-6:

Verify that the expression getchar() != EOF is 0 or 1.

Tip: The EOF character can be typed using ctrl+z on windows systems, or with ctrl+d on unix systems
*/

#include <stdio.h>

int main () {
	printf("value of getchar() != EOF: %d\n", getchar() != EOF);

}
