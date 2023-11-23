#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isMatch(char* s, char* p) {
    int **dp;
    int len_s, len_p;
    int i,j;
    int ret;

    len_s = strlen(s);
    len_p = strlen(p);
    dp = (int **)malloc(sizeof(int *) * (len_s + 1));
    for(i = 0; i <= len_s; ++i){
        dp[i] = (int *)malloc(sizeof(int) * (len_p + 1));
        memset(dp[i], 0, sizeof(int) * (len_p + 1));
    }

    dp[0][0] = 1;
    for(i = 0; i <= len_s; ++i){
        for(j = 1; j <= len_p; ++j){
            if(p[j-1] != '.' && p[j-1] != '*'){
                dp[i][j] = (i > 0 && dp[i-1][j-1] && s[i-1] == p[j-1]);
            } else if(p[j-1] == '.'){
                dp[i][j] = (i > 0 && dp[i-1][j-1]);
            }else if(j > 1){
                if(dp[i][j-1] || dp[i][j-2])
                    dp[i][j] = 1;
                else if(i>0 && (p[j-2]==s[i-1] || p[j-2]=='.') && dp[i-1][j])
                    dp[i][j] = 1;
            }
        }
    }

    ret = dp[len_s][len_p];

    for(i = 0; i <= len_s; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}

int main() {
    char* s1 = "aa";
    char* p1 = "a";
    printf("%s, %s: %d", s1, p1, isMatch(s1, p1)); // false

    char* s2 = "aa";
    char* p2 = "*";
    printf("%s, %s: %d", s2, p2, isMatch(s2, p2)); // true

    char* s3 = "cb";
    char* p3 = "?a";
    printf("%s, %s: %d", s3, p3, isMatch(s3, p3)); // false

    char* s4 = "adceb";
    char* p4 = "*a*b";
    printf("%s, %s: %d", s4, p4, isMatch(s4, p4)); // true

    char* s5 = "acdcb";
    char* p5 = "a*c?b";
    printf("%s, %s: %d", s5, p5, isMatch(s5, p5)); // false

    return 0;
}