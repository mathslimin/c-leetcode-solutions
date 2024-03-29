#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int uniquePaths(int m, int n) {
    int **dp;
    int i,j;
    int ret;

    dp = (int **)malloc(sizeof(int *) * m);
    for(i = 0; i < m; ++i)
        dp[i] = (int *)malloc(sizeof(int) * n);

    for(i = 0; i < m; ++i)
        dp[i][0] = 1;
    for(j = 0; j < n; ++j)
        dp[0][j] = 1;

    for(i = 1; i < m; ++i){
        for(j = 1; j < n; ++j)
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
    }

    ret = dp[m-1][n-1];
    for(i = 0; i < m; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}

int main() {
    int m = 3, n = 7;
    int result = uniquePaths(m, n);
    printf("The number of unique paths is %d", result);
    return 0;
}