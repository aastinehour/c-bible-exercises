/*
Exercise 1-21:

Write a program 'entab' that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing.
Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
*/

#include <stdio.h>

#define TABSTOP 8

void display_blanks(int num_spaces, int num_tabs);

int main(void) {
    int character;
    int length = 0; 
    int num_tabs = 0;
    int num_spaces = 0;

    while ((character = getchar()) != EOF) {
        if (character == ' ') {
            int spaces = TABSTOP - (length % TABSTOP);

            ++num_spaces;

            if (num_spaces == spaces) {
                length += spaces;
                
                /* If spaces == 1, a tab and a space do the same thing - in this case, a space is used */
                if (spaces > 1) {
                    num_spaces = 0;
                    ++num_tabs;
                }
                
            }
        } else if (character == '\n') {
            display_blanks(num_spaces, num_tabs);
            putchar(character);

            length = 0; 
            num_spaces = 0;
            num_tabs = 0;
        } else {
            display_blanks(num_spaces, num_tabs);
            putchar(character);

            length += num_spaces + 1;
            num_spaces = 0;
            num_tabs = 0;
        }
        
    }   

    return 0;
}

/* Displays the refactored blanks */
void display_blanks(int num_spaces, int num_tabs) {
    for (int i = 1; i <= num_tabs; i++) {
        putchar('\t');
    }

    for (int i = 1; i <= num_spaces; i++) {
        putchar(' ');
    }
}