#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int start, end, mid;
    int *ret;

    ret = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    ret[0] = -1;
    ret[1] = -1;

    start = 0;
    end = numsSize - 1;

    while(start <= end){
        mid = (start + end) / 2;
        if((mid - 1 < 0 || nums[mid-1] != target) &&
            target == nums[mid]){
            ret[0] = mid;
            ret[1] = mid;
            break;
        }else if(nums[mid] >= target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    start = mid+1;
    end = numsSize - 1;
    while(start <= end){
        mid = (start + end) / 2;
        if((mid + 1 == numsSize || target != nums[mid+1]) &&
            target == nums[mid]){
            ret[1] = mid;
            break;
        }else if(nums[mid] > target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    return ret;
}

int main() {
    int nums[] = {5, 7, 7, 8, 8, 10};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 8;
    int returnSize;
    int* result = searchRange(nums, numsSize, target, &returnSize);
    printf("[%d, %d]", result[0], result[1]); // 输出结果
    free(result); // 释放结果数组的内存空间
    return 0;
}
