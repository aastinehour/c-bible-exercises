/*
Exercise 1-18:

Write a progam to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
*/

#include <stdio.h>

#define MAX_LENGTH 500 /* Input array buffer */

int cleanline(char line[], int max_length);

int main (void) {
    char line[MAX_LENGTH];
    int len = 0;

    while ((len = cleanline(line, MAX_LENGTH)) != -1) {
        if (len > 0) {
            printf("%s\n", line);
        }
    }

    return 0;
}

/* Removes trailing blanks and tabs from a line */
int cleanline(char line[], int max_length) {
    int character;
    
    /* Dumps user input into line array */
    int i;
    for (i = 0; (character = getchar()) != EOF && i < max_length - 1 && character != '\n'; i++) {
        line[i] = character;
    }
    line[i] = '\0';

    if (character == EOF && i == 0) {
        return -1;
    }

    /* Trims whitespace from the end of line array */
    int j = i - 1;
    while (j >= 0 && (line[j] == ' ' || line[j] == '\t')) {
        line[j] = '\0';
        --j;
    }

    return j + 1;
}