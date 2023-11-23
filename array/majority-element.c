#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int majorityElement(int* nums, int numsSize) {
    int count;
    int ret;
    int i;

    count = 0;
    for(i = 0; i < numsSize; ++i){
        if(count == 0)
            ret = nums[i];
        if(ret == nums[i])
            count++;
        else
            count--;
    }

    return ret;
}

int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int res = majorityElement(nums, numsSize);
    printf("res: %d ", res);
    return 0;
}
