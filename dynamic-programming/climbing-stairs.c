#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int climbStairs(int n) {
    int *dp;
    int i,ret;

    dp = (int *)malloc(sizeof(int) * (n + 1));
    dp[0] = 1;
    dp[1] = 1;
    for(i = 2; i <= n; ++i)
        dp[i] = dp[i-1] + dp[i-2];

    ret = dp[n];
    free(dp);
    return ret;
}

int main() {
    printf("%d\n", climbStairs(1)); // 1
    printf("%d\n", climbStairs(2)); // 2
    printf("%d\n", climbStairs(3)); // 3
    printf("%d\n", climbStairs(4)); // 5
    printf("%d\n", climbStairs(5)); // 8
    return 0;
}