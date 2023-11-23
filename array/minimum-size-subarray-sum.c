#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int minSubArrayLen(int s, int* nums, int numsSize) {
    int i,j;
    int sum;
    int count;
    int ret = numsSize + 1;

    i = 0;
    j = 0;
    sum = 0;
    count = 0;
    while(1){
        if(i < numsSize && sum >= s){
            if(count < ret)
                ret = count;
            sum -= nums[i++];
            count--;
        }else if(j < numsSize){
            sum += nums[j++];
            count++;
        }else{
            break;
        }
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
