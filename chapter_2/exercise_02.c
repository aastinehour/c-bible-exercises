/*
Exercise 2-2:

Write a loop equivalent to the for loop above without using && or ||.

for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++1)
    s[i] = c;
*/

#include <stdio.h>

enum boolean { NO, YES };
enum boolean check = YES;

int main(void) {
    int i = 0;
    int lim = 1000;
    int c;
    char s[lim];
    
    while (check == YES) {
        if (i >= lim - 1) {
            check = NO;
        } else if ((c = getchar()) == '\n') {
            check = NO;
        } else if (c == EOF) {
            check = NO;
        } else {
            s[i] = c;
            ++i;
        }
    }

    return 0;
}