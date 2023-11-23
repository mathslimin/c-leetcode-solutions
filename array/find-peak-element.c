#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int findPeakElement(int* nums, int numsSize) {
    int i;
    for(i = 1; i < numsSize; ++i)
        if(nums[i-1] > nums[i])
            return i-1;

    return numsSize - 1;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(int);
    int peak = findPeakElement(nums, numsSize);
    printf("The peak element is %d\n", nums[peak]);
    return 0;
}
