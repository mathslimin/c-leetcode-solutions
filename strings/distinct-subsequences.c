#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
由于这道题目需要用到动态规划，因此我们先定义一个二维数组dp，其中dp[i][j]表示t的前i个字符和s的前j个字符的子序列个数。
然后，我们可以根据t[i]和s[j]是否相等来决定dp[i][j]的值：
- 如果t[i]和s[j]不相等，则s[j]不能用于匹配t[i]，因此dp[i][j]等于dp[i][j-1]，即s的前j-1个字符和t的前i个字符的子序列个数。
- 如果t[i]和s[j]相等，则s[j]既可以用于匹配t[i]，也可以不用。如果s[j]用于匹配t[i]，则dp[i][j]等于dp[i-1][j-1]，即s的前j-1个字符和t的前i-1个字符的子序列个数；如果s[j]不用于匹配t[i]，则dp[i][j]等于dp[i][j-1]，即s的前j-1个字符和t的前i个字符的子序列个数。
最后，dp[tlen][slen]就是我们要求的答案。
*/
int numDistinct(char* s, char* t)
{
    int** dp;
    int i, j;
    int len_s, len_t;
    int ret;
    len_s = strlen(s);
    len_t = strlen(t);

    dp = (int**)malloc(sizeof(int*) * (len_s + 1));
    for (i = 0; i <= len_s; ++i) {
        dp[i] = (int*)malloc(sizeof(int) * (len_t + 1));
        memset(dp[i], 0, sizeof(int) * (len_t + 1));
    }

    for (i = 0; i <= len_s; ++i)
        dp[i][0] = 1;

    for (i = 1; i <= len_s; ++i) {
        for (j = 1; j <= len_t; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (s[i - 1] == t[j - 1])
                dp[i][j] += dp[i - 1][j - 1];
        }
    }

    ret = dp[len_s][len_t];
    for (i = 0; i <= len_s; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}

int main() {
    char s[] = "babgbag";
    char t[] = "bag";
    printf("%d", numDistinct(s, t)); // 输出3
    return 0;
}