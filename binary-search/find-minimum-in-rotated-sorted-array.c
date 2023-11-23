//153. 寻找旋转排序数组中的最小值

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int findMin(int* nums, int numsSize) {
    int start,end;
    start = 0;
    end = numsSize - 1;

    while(start < end){
        int mid = (start + end) / 2;
        if(nums[mid] > nums[end])
            start = mid + 1;
        else
            end = mid;
    }

    return nums[start];
}

int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int numsSize = sizeof(nums) / sizeof(int);
    int min = findMin(nums, numsSize);
    printf("The minimum value in the rotated sorted array is %d", min);
    return 0;
}