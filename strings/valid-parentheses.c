#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s)
{
    char* st;
    int len, i;
    int top;
    char ch;

    len = strlen(s);
    st = (char*)malloc(sizeof(char) * len);
    top = -1;
    for (i = 0; i < len; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st[++top] = s[i];
        else {
            if (top == -1)
                return false;

            ch = st[top--];
            if ((ch == '(' && s[i] != ')') || (ch == '[' && s[i] != ']') || (ch == '{' && s[i] != '}'))
                return false;
        }
    }

    free(st);
    return top == -1;
}

int main() {
    char s[10000] = "()()()";
    if (isValid(s)) {
        printf("括号匹配成功！");
    } else {
        printf("括号匹配失败！");
    }
    return 0;
}