#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool search(int* nums, int numsSize, int target) {
    int start,end,mid;
    start = 0;
    end = numsSize - 1;

    while(start <= end){
        mid = (start + end) / 2;
        if(nums[mid] == target){
            return true;
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
            ++start;
        }
    }

    return false;
}

int main() {
    int nums[] = {2, 5, 6, 0, 0, 1, 2};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 0;
    bool result = search(nums, numsSize, target);
    printf("%d\n", result);
    return 0;
}
