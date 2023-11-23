#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int search(int* nums, int numsSize, int target) {
    int start, mid, end;

    start = 0;
    end = numsSize - 1;
    while(start <= end){
        mid = (start + end) / 2;
        if(nums[mid] == target){
            return mid;
        }

        if(nums[mid] > nums[start]){
            if(target >= nums[start] && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }else if(nums[mid] < nums[start]){
            if(target > nums[mid] && target <= nums[end])
                start = mid + 1;
            else
                end = mid - 1;
        }else{
            start++;
        }
    }

    return -1;
}

int main() {
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int result = search(nums, numsSize, target);
    printf("The index of target %d is %d", target, result);
    return 0;
}