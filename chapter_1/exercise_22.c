/*
Exercise 1-22:

Write a program to 'fold' long input lines into two or more shorter lines after the last non-blank character taht occurs before the n-th column of input.
Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
*/

#include <stdio.h>

#define MAXCOL 10 /* Maximum output column length */
#define TABSTOP 8 /* Tabstop length */

void print_line(int pos);
int find_last_blank(int pos);
int rearrange(int pos);

char line[MAXCOL];


int main(void) {
    int c;
    int pos = 0;

    while ((c = getchar()) != EOF) {
        line[pos] = c;
        ++pos;

        if (c == '\t') {
            --pos;
            while (pos < MAXCOL && pos % TABSTOP != 0) {
            /* Replaces tab characters with spaces */
                line[pos] = ' ';
                ++pos;
            }

            if (pos >= MAXCOL) {
                print_line(pos);
                pos = 0;
            }
        } else if (c == '\n') {
            --pos;
            print_line(pos);
            pos = 0;
        } else if (pos >= MAXCOL) {
            pos = find_last_blank(pos);
            print_line(pos);
            pos = rearrange(pos);
        }
    }

    return 0;
}

void print_line(int pos) {
    int i;

    for (i = 0; i < pos; i++) {
       putchar(line[i]);
    }

    if (pos != 0) {
        putchar('\n');
    }
}

int find_last_blank(int pos) {

    while (pos >= 0 && line[pos] != ' ') {
        --pos;
    }
    
    if (pos < 0) {
    /* No blanks found */
        return MAXCOL;
    } else {
    /* pos stopped before it broke 0 -- a blank was hit */
        return pos + 1;
    }
}

int rearrange(int pos) {
    if (pos == MAXCOL) {
    /* There were no blanks */
        return 0;
    } else {
    /* pos contains the index of a blank */
        int i = 0;
        int j;

        for (j = pos; j < MAXCOL; j++) {
            line[i] = line[j];
            ++i;
        }

        return i;
    }
}