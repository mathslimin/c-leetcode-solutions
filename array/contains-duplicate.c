#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);

    for(int i = 1; i < numsSize; ++i)
        if(nums[i] == nums[i-1])
            return true;

    return false;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numsSize = 10;
    bool result = containsDuplicate(nums, numsSize);
    if (result) {
        printf("包含重复元素");
    } else {
        printf("不包含重复元素");
    }
    return 0;
}
