#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int minSubArrayLen(int s, int* nums, int numsSize) {
    int i,j;
    int sum;
    int ret = numsSize + 1;

    sum = 0;
    j = 0;
    for(i = 0; i < numsSize; ++i){
        while(j < numsSize && sum < s){
            sum += nums[j++];
        }

        if(sum >= s)
            ret = j - i < ret ? j - i : ret;
        sum -= nums[i];
    }

    return ret == numsSize + 1 ? 0 : ret;
}

int main() {
    int s = 7;
    int nums[] = {2,3,1,2,4,3};
    int numsSize = 6;

    printf("%d", minSubArrayLen(s, nums, numsSize));

    return 0;
}
