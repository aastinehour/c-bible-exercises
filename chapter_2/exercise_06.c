/*
Exercise 2-6:

Write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p set to the rightmost n bits of y,
leaving the other bits unchanged.
*/

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned setbits_2(unsigned x, int p, int n, unsigned y);

int main(void) {
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    int shift = p + 1 - n;
    unsigned mask = ~(~0 << n);
    unsigned cleared_x = ~(mask << shift) & x;
    unsigned y_bits = (y & mask) << shift;

    return cleared_x | y_bits;
}

/* Alternate solution */
unsigned setbits_2(unsigned x, int p, int n, unsigned y) {
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
}