/*
Exercise 2-7:

Write a function invert(x, p, n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
leaving the others unchanged.
*/

unsigned invert(unsigned x, int p, int n);

int main(void) {
    return 0;
}

unsigned invert(unsigned x, int p, int n) {
    int shift = p + 1 - n;
    unsigned mask = ~(~0 << n) << shift;
    
    unsigned cleared_x = x & ~mask; /* creates a 'hole' in x where inverted bits need to be placed */
    
    unsigned inverted_mask = ~x & mask; /* mask with the inverted digits in place */
    
    unsigned solution = inverted_mask | cleared_x; /* slots the inverted digits into the cleared hole */

    return solution;
}

/* 
invert() can technically be written in one line, as so:

(x & ~(~(~0 << n) << (p + 1 - n))) | (~x & (~(~0 << n) << (p + 1 - n)))
*/