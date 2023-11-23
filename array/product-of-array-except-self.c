#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int product = 1;
    int *left;
    int *right;
    int i;

    left = (int *)malloc(sizeof(int) * numsSize);
    right = (int *)malloc(sizeof(int) * numsSize);
    left[0] = 1;
    for(i = 1; i < numsSize; ++i)
        left[i] = nums[i-1] * left[i-1];

    right[numsSize-1] = 1;
    for(i = numsSize - 2; i >= 0; --i)
        right[i] = nums[i+1] * right[i+1];

    for(i = 0; i < numsSize; ++i)
        left[i] *= right[i];

    *returnSize = numsSize;
    free(right);
    return left;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize;
    int *result = productExceptSelf(nums, numsSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}
