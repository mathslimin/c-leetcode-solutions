#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
    int i, j;
    for (i = 0; i < numsSize; ++i) {
        for (j = i + 1; j <= i + k && j < numsSize; ++j)
            if (nums[i] == nums[j])
                return true;
    }

    return false;
}

// main函数
int main() {
    int nums[] = {1,2,3,1};
    int numsSize = 4;
    int k = 3;
    bool result = containsNearbyDuplicate(nums, numsSize, k);
    printf("%d", result);
    return 0;
}