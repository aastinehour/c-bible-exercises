/*
Exercise 2-5:

Write the function any(s1, s2), which returns the first location in the string s1 where any character from the string s2 occurs,
or -1 if s1 contains no characters from s2. 

(The standard library function strpdrk does the same job but returns a pointer to the location.)
*/

#include <stdio.h>

int any(char s1[], char s2[]);
void test(char s[], int expected);

int main(void) {
    char test1[] = ""; /* -1 */
    char test2[] = "hello, world!"; /* 0 */
    char test3[] = "l"; /* 2 */
    char test4[] = "x"; /* -1 */

    test(test1, -1);
    test(test2, 0);
    test(test3, 2);
    test(test4, -1);

    return 0;
}

int any(char s1[], char s2[]) {
    int loc, i;
    for (loc = 0; s1[loc] != '\0'; loc++) {
        for (i = 0; s2[i] != '\0'; i++) {
            if (s1[loc] == s2[i]) {
                return loc;
            }
        }
    }

    return -1;
}

void test(char s[], int expected) {
    char hello[] = "hello, world!";
    int loc = any(hello, s);

    printf("any(\"hello, world!\", \"%-15s\")  -->  %2d\t\t\t", s, loc);

    /* adds pass/fail flags depending on result */
    if (loc == expected)
        printf("\033[1;32mPASSED\033[0m\n");
    else
        printf("\033[1;31mFAILED\033[0m\n");
}