/*
Exercise 1-11:

How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
*/

#include <stdio.h>

#define IN 1 // Inside a word
#define OUT 0 // Outside a word

int main () {
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while ((c = getchar()) != EOF) {
		++nc; // Counts the new character

		if (c == '\n') {
			++nl; // Counts the newline
		}

		if (c == '\n' || c == ' ' || c == '\t') {
			state = OUT; // Sets the state to OUT if c is blank
		} else if (state == OUT) {
			state = IN; // Sets the state to IN if c is not blank
			++nw; // Counts the new word
		}
	}

	printf("\nLines: %d\n", nl);
	printf("Words: %d\n", nw);
	printf("Characters: %d\n", nc);
}
