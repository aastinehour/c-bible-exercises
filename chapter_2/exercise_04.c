/*
Exercise 2-4:

Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any character is the string s2.
*/

#include <stdio.h>

void squeeze(char s1[], char s2[]);
void test(char s1[], char s2[]);

int main(void) {
    char test1[] = "he";
    char test2[] = "world ll!o";
    char test3[] = "";
    char test4[] = "!llheo xoxo";
    char test5[] = "hello, world!";

    char hello1[] = "hello, world!";
    char hello2[] = "hello, world!";
    char hello3[] = "hello, world!";
    char hello4[] = "hello, world!";
    char hello5[] = "hello, world!";

    test(hello1, test1); /* llo, world! */
    test(hello2, test2); /* he, */
    test(hello3, test3); /* hello, world! */
    test(hello4, test4); /* ,wrd */
    test(hello5, test5); /*  */

    return 0;
}


void squeeze(char s1[], char s2[]) {
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; i++) {
        /* scan the string until either a match or '\0' is found */
        for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++)
            ;

        /* if the end of s2 is reached cleanly, there was no character match and the character is cleared to be added */
        if (s2[j] == '\0')
            s1[k++] = s1[i];
    }

    s1[k] = '\0';
}

void test(char s1[], char s2[]) {
    printf("squeeze(\"%s\", \"%s\") --> ", s1, s2);
    squeeze(s1, s2);
    printf("\"%s\"\n", s1);
}