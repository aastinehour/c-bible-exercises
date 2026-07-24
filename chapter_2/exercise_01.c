/*
Exercise 2-1:

Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.
*/

#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("----------- CHAR -----------\n");
    printf("bits: %d\n", CHAR_BIT);
    printf("char range: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("signed char range: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char max: %u\n", UCHAR_MAX);
    printf("\n");

    printf("----------- INT ------------\n");
    printf("int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int max: %u\n", UINT_MAX);
    printf("\n");

    printf("----------- SHORT ----------\n");
    printf("short range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short max: %u\n", USHRT_MAX);
    printf("\n");

    printf("----------- LONG ----------\n");
    printf("long range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long max: %lu\n", ULONG_MAX);

    return 0;
}