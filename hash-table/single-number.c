#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int singleNumber(int* nums, int numsSize) {
    int ret = 0;

    for(int i = 0; i < numsSize; ++i)
        ret ^= nums[i];

    return ret;
}

int main(){
    int nums[] = {1,2,2,3,3,4,4};
    int numsSize = 7;
    int result = singleNumber(nums, numsSize);
    printf("The single number is: %d", result);
    return 0;
}