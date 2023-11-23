#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int firstMissingPositive(int* nums, int numsSize) {
    int i = 0;

    while(i < numsSize){
        if(nums[i] <= 0 || nums[i] >= numsSize || nums[i] == i + 1
                || nums[i] == nums[nums[i] - 1]){
            ++i;
        }else{
            int tmp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[tmp-1] = tmp;
        }
    }

    for(i = 0; i < numsSize; ++i)
        if(nums[i] != i + 1)
            break;

    return i + 1;
}

int main() {
    int nums[] = {3, 4, -1, 1};
    int numsSize = sizeof(nums) / sizeof(int);
    int result = firstMissingPositive(nums, numsSize);
    printf("%d", result);
    return 0;
}
