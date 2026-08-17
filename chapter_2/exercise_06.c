/*
Exercise 2-6:

Write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p set to the rightmost n bits of y,
leaving the other bits unchanged.
*/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void) {
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = 0;

    for (int i = 0; i < n; i++) {
        mask = mask << 1;
        mask = mask | 1;
    }

    unsigned temp_n = y & mask;
    temp_n = temp_n << p;

    mask = mask << p;
    mask = ~mask;

    x = x & mask;
    x = x | temp_n;

    return x;
}