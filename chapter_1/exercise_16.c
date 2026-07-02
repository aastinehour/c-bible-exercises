/*
Exercise 1-16:

Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines,
and as much as possible of the text.
*/

#include <stdio.h>

#define MAXLINE 1000

int getlength(char line[], int maxline);
void copy(char from[], char to[]);

/* Print longest input line */
int main (void) {
    int len; /* Current line length */
    int max; /* Maximum line length */
    char line [MAXLINE]; /* Curent input line */
    char longest[MAXLINE]; /* Longest line */

    max = 0;
    while ((len = getlength(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }

    if (max > 0) {
           printf("%d: %s", max, longest);
    }

    return 0;
}

/* read a line into  */
int getlength (char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    int extra = 0;
    if (c != EOF && c != '\n') {
        extra = 1;
        while ((c = getchar()) != EOF && c != '\n') {
            ++extra;
        }
    }
    
    if (c == '\n') {
        if (i < lim - 1) {
            s[i] = c;
            ++i;
        }
    }

    s[i] = '\0';
    return i + extra;
}

/* Copy the "from[]" array to the "to[]" array */
void copy(char from[], char to[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
} 