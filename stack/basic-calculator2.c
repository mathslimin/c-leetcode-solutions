#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate(char* s)
{
    int st[1000];
    int top = -1;
    int result = 0;
    int type = 1;
    int value;

    while (*s) {
        if (isdigit(*s)) {
            value = 0;
            while (isdigit(*s)) {
                value = value * 10 + *s - '0';
                s++;
            }

            result += (type * value);
        }

        if (*s == '+') {
            type = 1;
        } else if (*s == '-') {
            type = -1;
        } else if (*s == '(') {
            st[++top] = result;
            st[++top] = type;
            result = 0;
            type = 1;
        } else if (*s == ')') {
            type = st[top--];
            value = st[top--];

            result = value + (type * result);
        }
        s++;
    }

    return result;
}

int main(){
    char s[] = " 3+5 / 2 ";
    int res = calculate(s);
    printf("%d", res);
    return 0;
}