#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isNumber(char* s)
{
    int len;
    int i, e;
    bool num = false;
    bool exp = false;
    bool dot = false;
    i = 0;
    len = strlen(s);
    e = len - 1;

    while (i <= e && s[i] == ' ')
        i++;

    if (i > len - 1)
        return false;

    while (e >= i && s[e] == ' ')
        e--;

    if (s[i] == '+' || s[i] == '-')
        i++;

    while (i <= e) {
        char c = s[i];

        if (isdigit(c)) {
            num = true;
        } else if (c == '.') {
            if (exp || dot)
                return false;
            dot = true;
        } else if (c == 'e') {
            if (exp || !num)
                return false;
            num = false;
            exp = true;
        } else if (c == '+' || c == '-') {
            if (s[i - 1] != 'e')
                return false;
        } else {
            return false;
        }

        i++;
    }

    return num;
}

int main() {
    // testing code
    char s1[] = "0";
    char s2[] = " 0.1 ";
    char s3[] = "abc";
    char s4[] = "1 a";
    char s5[] = "2e10";
    
    printf("%s is a number: %d\n", s1, isNumber(s1));
    printf("%s is a number: %d\n", s2, isNumber(s2));
    printf("%s is a number: %d\n", s3, isNumber(s3));
    printf("%s is a number: %d\n", s4, isNumber(s4));
    printf("%s is a number: %d\n", s5, isNumber(s5));
    
    return 0;
}