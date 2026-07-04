/*
Exercise 1-20:

Write a program 'detab' that replaces tabs in the input with the proper number of blanks to space to the next tab stop.
Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define TABSTOP 8

int main (void) {
    int col = 0;
    int character;
    int i;

    while ((character = getchar()) != EOF) {
        if (character == '\t') {
            int spaces = TABSTOP - (col % TABSTOP);
            for (i = 1; i <= spaces; i++) {
                putchar(' ');
            }
            col += spaces;
        } else if (character == '\n') {
            putchar(character);
            col = 0;
        } else {
            putchar(character);
            ++col;
        }
    }
}