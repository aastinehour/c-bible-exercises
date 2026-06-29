/*
Exercise 1-9:

Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
*/

#include <stdio.h>

int main () {
	int c;
	int last_c = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ' || last_c != ' ') {
			putchar(c);
		}

		last_c = c;
	}
}
