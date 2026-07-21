/*
Exercise 1-23:

Write a program to remove all comments from a C program. 
Don't forget to handle quoted strings and charater constants properly. C comments do not nest.
*/

#include <stdio.h>

#define IN_COMMENT 1
#define OUT_COMMENT 0

void handle_inline_comment(void);
void handle_multiline_comment(void);
void handle_string(void);

int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\"') {
            putchar(c);
            handle_string();
        }

        if (c == '/') {
            int d = getchar();
            if (d == '/') {
                handle_inline_comment();
            } else if (d == '*') {
                handle_multiline_comment();
            } else {
                putchar(c);
                putchar(d);
            }
        } else {
            putchar(c);
        }
    } 

    return 0;
}

void handle_inline_comment(void) {
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        ;
    }

    if ((c == '\n')) {
        putchar(c);
    }
}

void handle_multiline_comment(void) {
    int comment_status = IN_COMMENT;

    while (comment_status == IN_COMMENT) {
        int c = getchar();
        if (c == '*') {
            int d = getchar();
            if (d == '/') {
                comment_status = OUT_COMMENT;
            }
        }
    }
}

void handle_string(void) {
    int c;
    while ((c = getchar()) != EOF && c != '\"') {
        putchar(c);
    }
}