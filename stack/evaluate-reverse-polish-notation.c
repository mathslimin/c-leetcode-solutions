#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_op(char* s)
{
    return !strcmp(s, "+") || !strcmp(s, "-") || !strcmp(s, "*") || !strcmp(s, "/");
}

int evalRPN(char** tokens, int tokensSize)
{
    int* st;
    int top = -1;
    int res, left, right;
    int i;

    st = malloc(sizeof(int) * tokensSize);
    for (i = 0; i < tokensSize; ++i) {
        char* s = tokens[i];
        if (!is_op(s)) {
            st[++top] = atoi(s);
        } else {
            right = st[top--];
            left = st[top--];
            switch (s[0]) {
                case '+':
                    res = left + right;
                    break;
                case '-':
                    res = left - right;
                    break;
                case '*':
                    res = left * right;
                    break;
                case '/':
                    res = left / right;
                    break;
                default:
                    break;
            }

            st[++top] = res;
        }
    }

    res = st[top];
    free(st);
    return res;
}

int main() {
    char* tokens[] = {"2", "1", "+", "3", "*"};
    int tokensSize = 5;
    int res = evalRPN(tokens, tokensSize);
    printf("%d", res); // expect output: 9

    char* tokens2[] = {"4", "13", "5", "/", "+"};
    int tokensSize2 = 5;
    int res2 = evalRPN(tokens2, tokensSize2);
    printf("%d", res2); // expect output: 6

    return 0;
}