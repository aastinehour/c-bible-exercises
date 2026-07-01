/*
Exercise 1-12:

Write a program that prints its input one word per line.
*/

#include <stdio.h>

int main () {
    int c, prev_c;
    prev_c = 0;

    while ((c = getchar()) != EOF) {
        // Checks if the current character is whitespace
        if (c == ' ' || c == '\n' || c == '\t') { 
            // Checks that the previous character was not whitespace
            if (prev_c != ' ' && prev_c != '\n' && prev_c != '\t') {
                putchar('\n');
            }
        } else {
            putchar(c);
            putchar('\n');
        }

        prev_c = c;
    }
}