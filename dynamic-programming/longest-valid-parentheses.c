#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int longestValidParentheses(char* s) {
    int *match,*st;
    int i,top,len,cur_count,max_count;

    len = strlen(s);
    match = (int *)malloc(sizeof(int) * len);
    st = (int *)malloc(sizeof(int) * len);
    memset(match, 0, sizeof(int) * len);
    top = -1;

    for(i = 0; i < len; ++i){
        if(s[i] == '('){
            st[++top] = i;
        }else if(top > -1){
            match[i] = 1;
            match[st[top]] = 1;
            top--;
        }
    }

    cur_count = 0;
    max_count = 0;
    for(i = 0; i < len; ++i){
        if(match[i])
            ++cur_count;
        else
            cur_count = 0;
        max_count = cur_count > max_count ? cur_count : max_count;
    }

    free(match);
    free(st);

    return max_count;
}

int main() {
    char s1[] = "(()";
    char s2[] = ")()())";
    char s3[] = "";
    char s4[] = "()()()";
    char s5[] = "((()))()()";

    printf("%d\n", longestValidParentheses(s1)); // expected output: 2
    printf("%d\n", longestValidParentheses(s2)); // expected output: 4
    printf("%d\n", longestValidParentheses(s3)); // expected output: 0
    printf("%d\n", longestValidParentheses(s4)); // expected output: 6
    printf("%d\n", longestValidParentheses(s5)); // expected output: 10

    return 0;
}
