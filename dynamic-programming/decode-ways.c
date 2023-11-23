#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int numDecodings(char* s) {
    int *dp;
    int i,len,value;

    len = strlen(s);
    if(len == 0)
        return 0;

    dp = (int *)malloc(sizeof(int) * (len + 1));
    dp[0] = 1;
    dp[1] = s[0] != '0' ? 1 : 0;
    for(i = 2; i <= len; ++i){
        dp[i] = s[i-1] != '0' ? dp[i-1] : 0;

        value = (s[i-2] - '0') * 10 + (s[i-1] - '0');
        if(value >= 10 && value <= 26)
            dp[i] += dp[i-2];
    }

    value = dp[len];
    free(dp);
    return value;
}

int main() {
    char s1[] = "12";
    printf("%s: %d", s1, numDecodings(s1));
    char s2[] = "226";
    printf("%s: %d", s2, numDecodings(s2));
    char s3[] = "0";
    printf("%s: %d", s3, numDecodings(s3));
    char s4[] = "1";
    printf("%s: %d", s4, numDecodings(s4));
    char s5[] = "10";
    printf("%s: %d", s5, numDecodings(s5));
    return 0;
}