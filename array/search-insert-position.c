#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int searchInsert(int* nums, int numsSize, int target) {
    int start,end,mid;

    start = 0;
    end = numsSize - 1;
    while(start < end){
        mid = (start + end) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return nums[start] < target ? start + 1 : start;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int numsSize = 4;
    int target = 5;
    int result = searchInsert(nums, numsSize, target);
    printf("%d", result);
    return 0;
}
