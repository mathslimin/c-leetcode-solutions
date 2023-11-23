#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int longestValidParentheses(char* s) {
    int *dp;
    int i,len,j,max_count;

    len = strlen(s);
    dp = (int *)malloc(sizeof(int) * (len + 1));
    dp[0] = 0;
    max_count = 0;

    for(i = 1; i <= len; ++i){
        j = i - dp[i-1] - 2;
        if(s[i-1] == '(' || j < 0 || s[j] != '('){
            dp[i] = 0;
        }else{
            dp[i] = dp[j] + dp[i-1] + 2;
            max_count = dp[i] > max_count ? dp[i] : max_count;
        }
    }

    free(dp);
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
