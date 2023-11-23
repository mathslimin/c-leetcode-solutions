#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int findPeakElement(int* nums, int numsSize) {
    int start,end;
    start = 0;
    end = numsSize - 1;

    while(start < end){
        int mid = (start + end) / 2;
        if(nums[mid] < nums[mid+1])
            start = mid + 1;
        else
            end = mid;
    }

    return start;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int numsSize = 4;
    int result = findPeakElement(nums, numsSize);
    printf("Peak element index: %d", result);
    return 0;
}
