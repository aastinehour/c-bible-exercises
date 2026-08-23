/*
Exercise 2-8:

Write a function rightrot(x, n) that rerturns the value of the integer x rotated to the right by n bit positions.
*/

unsigned rightrot(unsigned x, int n);

int main(void) {
    return 0;
}

unsigned rightrot(unsigned x, int n) {
    unsigned base_mask = ~0u << n;
    unsigned mov_mask = ~(~0u << n);

    unsigned base = x & base_mask;
    unsigned mov = x & mov_mask;

    base >>= n;
    mov <<= (sizeof(x) * 8) - n;

    return base | mov;
}