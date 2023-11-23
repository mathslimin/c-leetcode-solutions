#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isInterleave(char* s1, char* s2, char* s3) {
    int len1,len2,len3;
    int **dp;
    int i,j;
    bool ret;

    len1 = strlen(s1);
    len2 = strlen(s2);
    len3 = strlen(s3);

    if(len1 + len2 != len3)
        return false;

    dp = (int **)malloc(sizeof(int *) * (len1 + 1));
    for(i = 0; i <= len1; ++i)
        dp[i] = (int *)malloc(sizeof(int) * (len2 + 1));

    dp[0][0] = 1;
    for(i = 1; i <= len1; ++i)
        dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);

    for(j = 1; j <= len2; ++j)
        dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);


    for(i = 1; i <= len1; ++i){
        for(j = 1; j <= len2; ++j){
            dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i + j - 1])) ||
                    (dp[i][j-1] && (s2[j-1] == s3[i + j - 1]));
        }
    }

    ret = dp[len1][len2];
    for(i = 0; i <= len1; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}

int main() {
    char s1[] = "aabcc";
    char s2[] = "dbbca";
    char s3[] = "aadbbcbcac";
    printf("%d", isInterleave(s1, s2, s3)); // expect 1

    char s4[] = "aabcc";
    char s5[] = "dbbca";
    char s6[] = "aadbbbaccc";
    printf("%d", isInterleave(s4, s5, s6)); // expect 0

    return 0;
}