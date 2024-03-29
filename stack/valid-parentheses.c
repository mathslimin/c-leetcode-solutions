#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_match(char left, char right)
{
    return (left == '(' && right == ')') || (left == '{' && right == '}') || (left == '[' && right == ']');
}

bool isValid(char* s)
{
    int* st;
    int top;
    int len;

    len = strlen(s);
    st = malloc(sizeof(int) * len);
    top = -1;

    while (*s) {
        if (*s == '(' || *s == '[' || *s == '{')
            st[++top] = *s;
        else if (top > -1 && is_match(st[top], *s))
            top--;
        else
            return false;

        s++;
    }

    free(st);
    return top == -1;
}

int main()
{
    char s[] = "[]";
    printf("%d\n", isValid(s));
    return 0;
}