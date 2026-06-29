/*
Exercise 1-8:

Write a program to count blanks, tabs, and newlines.
*/

#include <stdio.h>

int main () {
	int c;
	int blanks, tabs, newlines;

	blanks = 0;
	tabs = 0;
	newlines = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++blanks;
		}

		if (c == '\t') {
			++tabs;
		}

		if (c == '\n') {
			++newlines;
		}
	}

	printf("\nblanks: %d\n", blanks);
	printf("tabs: %d\n", tabs);
	printf("newlines: %d\n", newlines);
}
