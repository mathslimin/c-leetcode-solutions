#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b)
{
    return *(const int*)a - *(const int*)b;
}

int* get_4sum(int a, int b, int c, int d)
{
    int* arr = malloc(sizeof(int) * 4);
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;

    return arr;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{
    int** ret;
    int idx = 0;
    int count = 32;
    int i, j, start, end, sum;

    ret = malloc(sizeof(int*) * count);
    qsort(nums, numsSize, sizeof(int), cmp);

    for (i = 0; i < numsSize - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (j = i + 1; j < numsSize - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            start = j + 1;
            end = numsSize - 1;
            while (start < end) {
                sum = nums[i] + nums[j] + nums[start] + nums[end];
                if (sum == target) {
                    if (idx == count) {
                        count <<= 1;
                        ret = realloc(ret, sizeof(int*) * count);
                    }
                    ret[idx++] = get_4sum(nums[i], nums[j], nums[start], nums[end]);
                    ++start;
                    --end;
                    while (start < end && nums[start] == nums[start - 1])
                        ++start;
                    while (start < end && nums[end] == nums[end + 1])
                        --end;
                } else if (sum > target) {
                    --end;
                } else {
                    ++start;
                }
            }
        }
    }

    *returnSize = idx;
    return ret;
}


int main() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;
    int returnSize = 0;
    int **result = fourSum(nums, numsSize, target, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("  [%d, %d, %d, %d]%s", result[i][0], result[i][1], result[i][2], result[i][3], i == returnSize - 1 ? "" : ",");
        free(result[i]);
    }
    printf("]");
    free(result);

    return 0;
}