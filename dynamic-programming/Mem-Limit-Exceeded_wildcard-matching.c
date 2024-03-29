#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isMatch(char* s, char* p) {
    int lens,lenp;
    int i,j;
    int **dp;
    int ret;

    lens = strlen(s);
    lenp = strlen(p);

    dp = malloc(sizeof(int *) * (lens + 1));
    for(i = 0; i <= lens; ++i){
        dp[i] = malloc(sizeof(int) * (lenp + 1));
        dp[i][0] = 0;
    }
    dp[0][0] = 1;

    for(i = 1; i <= lenp; ++i)
        dp[0][i] = dp[0][i-1] && (p[i-1] == '*');

    for(i = 1; i <= lens; ++i){
        for(j = 1; j <= lenp; ++j){
            if(p[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }else if(p[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1]);
            }
        }
    }

    ret = dp[lens][lenp];
    for(i = 0; i <= lens; ++i)
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