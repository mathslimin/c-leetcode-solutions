#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define min_2(x,y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x < _y ? _x : _y; \
})

#define MAX_VALUE (INT_MAX - 1)

int coinChange(int* coins, int coinsSize, int amount) {
    int *dp;
    int i,j;
    int ret;

    dp = (int *)malloc(sizeof(int) * (amount+1));

    dp[0] = 0;
    for(i = 1; i <= amount; ++i)
        dp[i] = MAX_VALUE;

    for(i = 0; i <=amount; ++i){
        for(j = 0; j < coinsSize; j++)
            if(i + coins[j] <= amount)
                dp[i+coins[j]] = min_2(dp[i+coins[j]], dp[i] + 1);
    }

    ret = dp[amount];
    free(dp);

    return ret == MAX_VALUE ? -1 : ret;
}

int main() {
    // 测试用例1：coins=[1,2,5], amount=11，预期输出3
    int coins1[] = {1, 2, 5};
    int coinsSize1 = 3;
    int amount1 = 11;
    int expected1 = 3;
    int result1 = coinChange(coins1, coinsSize1, amount1);
    printf("Test Case 1: expected=%d, result=%d", expected1, result1);
}