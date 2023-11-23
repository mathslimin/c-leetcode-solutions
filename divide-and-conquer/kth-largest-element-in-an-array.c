#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int findKthLargest(int* nums, int numsSize, int k) {
    int start,end;
    int i,j;
    int tmp,value;

    start = 0;
    end = numsSize - 1;
    --k;

    while(start < end){
        i = start - 1;
        j = end + 1;
        value = nums[(i+j)/2];

        while(i < j){
            while(nums[++i] > value) ;

            while(value > nums[--j]) ;

            if(i < j){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }

        if(j >= k)
            end = j;
        else
            start = j+1;
    }

    return nums[k];
}

int main() {
    int nums[] = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int numsSize = sizeof(nums) / sizeof(int);
    int result = findKthLargest(nums, numsSize, k);
    printf("第 %d 大的元素是 %d", k, result);
    return 0;
}