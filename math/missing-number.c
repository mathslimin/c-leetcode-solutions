#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int missingNumber(int* nums, int numsSize)
{
    int* arr;
    int i;
    int ret;

    arr = (int*)malloc(sizeof(int) * (numsSize + 1));
    memset(arr, 0, sizeof(int) * (numsSize + 1));

    for (i = 0; i < numsSize; ++i)
        arr[nums[i]] = 1;

    for (i = 0; i <= numsSize; ++i)
        if (arr[i] == 0) {
            ret = i;
            break;
        }

    free(arr);
    return ret;
}

int main() {
    int nums[] = {7, 1, 5, 3, 6, 4};
    int numsSize = 6;
    int answer = missingNumber(nums, numsSize);
    printf("answer: %d\n", answer);
    return 0;
}