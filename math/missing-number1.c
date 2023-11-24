#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int missingNumber(int* nums, int numsSize)
{
    int i;
    int sum;

    sum = numsSize * (1 + numsSize) / 2;
    for (i = 0; i < numsSize; ++i)
        sum -= nums[i];

    return sum;
}

int main() {
    int nums[] = {7, 1, 5, 3, 6, 4};
    int numsSize = 6;
    int answer = missingNumber(nums, numsSize);
    printf("answer: %d\n", answer);
    return 0;
}