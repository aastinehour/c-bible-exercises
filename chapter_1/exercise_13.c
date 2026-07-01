/*
Exercise 1-13:

Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLENGTH 15

int main() {
    int character;
    int status = OUT;
    int length = 0;
    int histogram[MAXLENGTH + 1];
    int i;

    /* Initialize all counts to 0 */
    for (i = 0; i <= MAXLENGTH; i++) {
        histogram[i] = 0;
    }

    /* Reads input, tracks word boundaries via state variable */
    while ((character = getchar()) != EOF) {
        if (character == ' ' || character == '\n' || character == '\t') {
            if (status == IN) {
                ++histogram[length];
                length = 0;
                status = OUT;
            }
        } else {
            ++length;
            status = IN;
        }
    }

    /* Catch the final word if input doesn't end in whitespace */
    if (status == IN) {
        ++histogram[length];
    }

    /* Find the tallest bar, to know how many rows to print */
    int graph_height = 0;
    for (i = 0; i <= MAXLENGTH; i++) {
        if (histogram[i] > graph_height) {
            graph_height = histogram[i];
        }
    }

    /* Prints bars top-down, one row at a time, across all columns. */
    int row, column;
    for (row = graph_height; row >= 1; row--) {
        for (column = 1; column <= MAXLENGTH; column++) {
            if (histogram[column] >= row) {
                printf(" x ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    for (i = 1; i <= MAXLENGTH; i++) {
        printf("---");
    }

    printf("\n");

    for (i = 1; i <= MAXLENGTH; i++) {
        printf("%3d", i);
    }

    printf("\n");
}