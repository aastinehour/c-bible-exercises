/* 
Exercise 1-14:

Write a program to print a histogram of the frequencies of different characters in its input.
*/

#include <stdio.h>

int main (void) {
    int letters[26];
    int character;
    int i, k;

    /* Zero out the letters array */
    for (i = 0; i < 26; i++) {
        letters[i] = 0;
    }

    while ((character = getchar()) != EOF) {
        if (character >= 'a' && character <= 'z') {
            ++letters[character - 'a'];
        } else if (character >= 'A' && character <= 'Z') {
            ++letters[character - 'A'];
        }
    }

    /* Displays the histogram (horizontally) */
    for (i = 0; i < 26; i++) {
        /* Only displays data for letters that have at least 1 occurence */
        if (letters[i] > 0) {
            printf("%c: ", 'a' + i);
            for (k = 1; k <= letters[i]; k++) {
                printf("-");
            }
            printf("\n");
        }
    }

    return 0;
}