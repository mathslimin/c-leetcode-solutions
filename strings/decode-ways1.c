#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numDecodings(char* s) {
    if (s[0] == '0') return 0; // 如果第一个字符是0，无法解码
    int len = strlen(s);
    int dp[len+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= len; i++) {
        int one = s[i-1] - '0';
        int two = (s[i-2] - '0') * 10 + one;
        if (one >= 1 && one <= 9) dp[i] += dp[i-1];
        if (two >= 10 && two <= 26) dp[i] += dp[i-2];
    }
    return dp[len];
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