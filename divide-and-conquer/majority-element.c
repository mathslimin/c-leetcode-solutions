#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int majorityElement(int* nums, int numsSize) {
    int count,value,i;

    count = 0;
    for(i = 0; i < numsSize; ++i){
        if(count == 0){
            ++count;
            value = nums[i];
        }else if(value == nums[i]){
            ++count;
        }else{
            --count;
        }
    }

    return value;
}

int main() {
    int nums[] = {3, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int majority = majorityElement(nums, numsSize);
    printf("The majority element is %d", majority);
    return 0;
}