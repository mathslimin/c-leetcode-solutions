#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int searchInsert(int* nums, int numsSize, int target) {
    int ret = -1;
    int start,end,mid;

    start = 0;
    end = numsSize - 1;

    while(start <= end){
        mid = (start + end) / 2;
        if(nums[mid] == target){
            ret = mid;
            break;
        }else if(nums[mid] > target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    if(ret == -1)
        ret = nums[mid] > target ? mid : mid + 1;

    return ret;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 5;
    int index = searchInsert(nums, numsSize, target);
    printf("The index of %d in the array is %d", target, index);
    return 0;
}