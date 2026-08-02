/*
Exercise 2-3:

Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F.
*/

#include <stdio.h>

#define MAXLEN 1000

char line[MAXLEN];

int htoi(char s[]);
void setline(void);

int main(void) {
    printf("type hex number:\t");
    setline();
    printf("integer is:\t%d\n", htoi(line));
    return 0;
}

int htoi(char s[]) {
    int i = 0;
    int result = 0;

    /* skips past any 0x or 0X sequences at the beginning of s[] */
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i += 2;
    }

    while (1) {    
        if ('0' <= s[i] && s[i] <= '9') {
            result = result * 16 + (s[i] - '0');
            ++i;
        } else if ('a' <= s[i] && s[i] <= 'f') {
            result = result * 16 + (s[i] - 'a' + 10);
            ++i;
        } else if ('A' <= s[i] && s[i] <= 'F') {
            result = result * 16 + (s[i] - 'A' + 10);
            ++i;
        } else {
            return result;
        }
    }
}

void setline(void) {
    int c;
    int len = 0;
    while ((c = getchar()) != EOF && c != '\n' && len < MAXLEN) {
        line[len] = c;
        ++len;
    } 
}