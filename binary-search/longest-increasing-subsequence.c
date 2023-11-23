#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

int lengthOfLIS(int* nums, int numsSize) {
    int *dp;
    int i,j;
    int max = 0;

    dp = (int *)malloc(sizeof(int) * numsSize);
    for(i = 0; i < numsSize; ++i){
        dp[i] = 1;
        for(j = 0; j < i; ++j)
            if(nums[j] < nums[i])
                dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
    }

    for(i = 0; i < numsSize; ++i)
        if(dp[i] > max)
            max = dp[i];

    free(dp);
    return max;
}

int main()
{
    int nums0[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int nums1[] = {1, 0, 1, 1};
    assert(lengthOfLIS(nums0, sizeof(nums0) / sizeof(nums0[0])) == 4);
    assert(lengthOfLIS(nums1, sizeof(nums1) / sizeof(nums1[0])) == 2);

    printf("all tests passed!\n");

    return 0;
}
