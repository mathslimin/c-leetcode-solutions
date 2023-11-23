#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int findMin(int* nums, int numsSize) {
    int start,end,mid;
    start = 0;
    end = numsSize - 1;

    while(start < end){
        mid = start + (end - start) / 2;
        if(nums[mid] > nums[end])
            start = mid + 1;
        else if(nums[mid] < nums[end])
            end = mid;
        else
            --end;
    }

    return nums[start];
}

int main() {
    int nums[] = {2, 2, 2, 0, 1};
    int numsSize = 5;
    int min = findMin(nums, numsSize);
    printf("The minimum value is %d\n", min);
    return 0;
}
