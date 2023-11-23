#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int numTrees(int n) {
    int *dp;
    int i,j;
    int ret;

    dp = (int *)malloc(sizeof(int) * (n + 1));
    dp[0] = 1;

    for(i = 1; i <= n; ++i){
        dp[i] = 0;
        for(j = 1; j <= i; ++j)
            dp[i] += (dp[j-1] * dp[i-j]);
    }

    ret = dp[n];
    free(dp);
    return ret;
}

int main()
{
    printf("%d\n", numTrees(1024));
    return 0;
}