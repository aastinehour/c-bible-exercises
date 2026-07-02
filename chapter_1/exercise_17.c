/*
Exercise 1-17:

Write a progam to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

#define TARGET_LENGTH 80
#define MAXLINE 1000

int getlength (char line[], int maxline);

int main (void) {
    char input_line[MAXLINE];
    int len;

    while ((len = getlength(input_line, MAXLINE)) > 0) {
        if (len > TARGET_LENGTH) {
            printf("LONGER THAN 80 CHARACTERS: %s\n", input_line);
        }
    }

    return 0;
}

int getlength (char line[], int maxline) {
    /* Fills line array with user input */
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    /* Manages adding newline character to array */
    if (c == '\n') {
        if (i < maxline - 1) {
            line[i] = c;
            ++i;
        }
    }

    /* Sets the last item of line array to be null character */
    line[i] = '\0';

    return i;
}