/*
Exercise 1-24:

Write a program to check a C program for rudimentray syntax errors like unbalanced parentheses, brackets, and braces.
Don't forget about quotes, not single and double, escape sequences, and comments. 

(This program is hard if you do it in full generality.)
*/

#include <stdio.h>

#define RESOLVED 1
#define UNRESOLVED 0
#define IN_COMMENT 1
#define OUT_COMMENT 0

int resolved_parentheses = RESOLVED;
int resolved_brackets = RESOLVED;
int resolved_braces = RESOLVED;

void handle_strings(void);
void handle_chars(void);
void handle_inline_comment(void);
void handle_multiline_comment(void);
void display_errors(void);

int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        /* Filters out text in strings/chars */
        if (c == '\"') {
            handle_strings();
        } else if (c == '\"') {
            handle_chars();
        }

        /* Filters out text in comments */
        if (c == '/') {
            int g = getchar();
            if (g == '/') {
                handle_inline_comment();
            } else if (g == '*') {
                handle_multiline_comment();
            }
        }

        /* Accounts for (), {}, and [] by "flipping a switch" when one is encountered */
        if (c == '(' || c == ')') {
            resolved_parentheses = !resolved_parentheses;
        } else if (c == '{' || c == '}') {
            resolved_brackets = !resolved_brackets;
        } else if (c == '[' || c == ']') {
            resolved_braces = !resolved_braces;
        }
    }

    display_errors();

    return 0;
}

void handle_strings(void) {
    /* Ignores all text within strings */
    int c;
    while ((c = getchar()) != '\"') {
        ;
    }
}

void handle_chars(void) {
    /* Ignores all text within chars */
    int c;
    while ((c = getchar()) != '\'') {
        ;
    }
}

void handle_inline_comment(void) {
    /* Ignores all text within inline comments */
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        ;
    }
}

void handle_multiline_comment(void) {
    /* Ignores all text within multiline comments */
    int status = IN_COMMENT;
    while (status == IN_COMMENT) {
        int c = getchar();
        if (c == '*') {
            int d = getchar();
            if (d == '/') {
                status = OUT_COMMENT;
            }
        }
    }
}

void display_errors(void) {
    putchar('\n');
    putchar('\n');

    if (!resolved_parentheses) {
        printf("warning: unresolved parenthesis\n");
    } else if (!resolved_brackets) {
        printf("warning: unresolved brackets\n");
    } else if (!resolved_braces) {
        printf("warning: unresolved braces\n");
    }
}