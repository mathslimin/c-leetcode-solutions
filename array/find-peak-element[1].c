#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int findPeakElement(int* nums, int numsSize) {
    int start,end,mid;
    start = 0;
    end = numsSize - 1;

    while(start < end){
        mid = start + (end - start) / 2;
        if(nums[mid] < nums[mid+1])
            start = mid + 1;
        else
            end = mid;
    }

    return start;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(int);
    int peak = findPeakElement(nums, numsSize);
    printf("The peak element is %d\n", nums[peak]);
    return 0;
}
