#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int maxSubArray(int* nums, int numsSize) {
    int i, ret, sum;

    sum = 0;
    ret = INT_MIN;
    for(i = 0; i < numsSize; ++i){
        sum += nums[i];
        ret = sum > ret ? sum : ret;
        sum = sum > 0 ? sum : 0;
    }

    return ret;
}

int main() {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int numsSize = 9;
    int maxSum = maxSubArray(nums, numsSize);
    printf("最大子数组和为%d", maxSum);
    return 0;
}