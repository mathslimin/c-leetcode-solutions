#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int search(int* nums, int numsSize, int target) {
    int start,end,mid;

    start = 0;
    end = numsSize -1;

    while(start <= end){
        mid = (start + end) / 2;
        if(nums[mid] == target){
            return mid;
        }

        if(nums[start] < nums[mid]){
            if(target >= nums[start] && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }else if(nums[start] > nums[mid]){
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

int main(){
    int nums[7] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = search(nums, 7, target);
    printf("%d", result);
    return 0;
}
