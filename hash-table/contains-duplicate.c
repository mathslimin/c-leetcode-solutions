#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void* a, const void* b)
{
    return *(const int*)a - *(const int*)b;
}

bool containsDuplicate(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 1; ++i)
        if (nums[i] == nums[i + 1])
            return true;

    return false;
}

// main函数
int main() {
    int nums[] = {1,2,3,1};
    int numsSize = sizeof(nums)/sizeof(int);
    bool result = containsDuplicate(nums, numsSize);
    printf("%d", result);
    return 0;
}