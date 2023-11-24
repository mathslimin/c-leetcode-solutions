#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
题目描述：

一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26

给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。

示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ"（2 26）, "VF"（22 6）或者 "BBF"（2 2 6）。

示例 3:

输入: "0"
输出: 0
解释: 没有字符映射到以 0 开头的数字。

示例 4:

输入: "1"
输出: 1
解释: 它可以解码为 "A"（1）。

示例 5:

输入: "10"
输出: 1
解释: 它只能解码成 "J"（10）。

*/
int numDecodings(char* s)
{
    int len;
    int* dp;
    int i, value;
    int ret;

    len = strlen(s);
    if (len == 0)
        return 0;

    dp = (int*)malloc(sizeof(int) * (len + 1));

    dp[len] = 1;
    dp[len - 1] = s[len - 1] == '0' ? 0 : 1;

    for (i = len - 2; i >= 0; --i) {
        if (s[i] == '0')
            dp[i] = 0;
        else if ((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
            dp[i] = dp[i + 1] + dp[i + 2];
        else
            dp[i] = dp[i + 1];
    }

    ret = dp[0];
    free(dp);
    return ret;
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