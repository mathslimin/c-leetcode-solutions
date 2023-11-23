#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static int leq_count(int *nums, int numsSize, int target)
{
    int i,ret;

    ret = 0;
    for(i = 0;i < numsSize; ++i)
        if(nums[i] <= target)
            ++ret;

    return ret;
}

int findDuplicate(int* nums, int numsSize) {
    int start,end,mid,c;
    start = 1;
    end = numsSize-1;

    while(start <= end){
        mid = (start + end) / 2;
        c= leq_count(nums,numsSize,mid);
        if(c <= mid)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return start;
}

int main() {
    // 在此处定义数组并初始化
    int nums[] = {1, 3, 4, 2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    // 调用函数查找重复元素
    int result = findDuplicate(nums, numsSize);
    
    // 输出结果
    printf("The duplicate number is: %d", result);
    
    return 0;
}