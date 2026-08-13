/*
Exercise 2-6:

Write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p set to the rightmost n bits of y,
leaving the other bits unchanged.
*/

unsigned setbits(unsigned x, int p, int n, unsigned y);

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