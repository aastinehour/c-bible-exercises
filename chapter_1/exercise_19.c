/*
Exercise 1-19:

Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAX_LENGTH 500

void reverse(char line[]);
int readline(char line[], int max_length);

int main(void) {
    char line[MAX_LENGTH];

    /* Loop runs while the input length > 0 */
    while (readline(line, MAX_LENGTH) > 0) {
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}

/* Reverses the string argument */
void reverse(char line[]) {
    int start = 0;
    int end = 0;
    char temp;

    while (line[end] != '\0') {
        ++end;
    }
    --end;

    while (start < end) {
        temp = line[start];
        line[start] = line[end];
        line[end] = temp;
        --end;
        ++start;
    }
}

/* Reads a line of user input and dumps it in line[] */
int readline(char line[], int max_length) {
    int character;
    int i = 0;
    while ((character = getchar()) != EOF && character != '\n' && i < max_length - 1) {
        line[i] = character;
        ++i;
    }
    line[i] = '\0';

    return i;
}