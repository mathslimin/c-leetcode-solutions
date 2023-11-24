#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
题目描述

给定一个含有n个正整数的数组和一个正整数s，找出该数组中满足其和≥s的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回0。

示例

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。

输入: s = 4, nums = [1,4,4]
输出: 1
解释: 子数组 [4] 是该条件下的长度最小的连续子数组。

输入: s = 11, nums = [1,1,1,1,1,1,1,1]
输出: 0

*/
int minSubArrayLen(int s, int* nums, int numsSize)
{
    int ret = numsSize + 1;
    int start = 0;
    int end = 0;
    int sum = 0;

    while (end < numsSize) {
        sum += nums[end++];
        while (sum >= s) {
            ret = (end - start) < ret ? (end - start) : ret;
            sum -= nums[start++];
        }
    }

    return ret == numsSize + 1 ? 0 : ret;
}

int main() {
    int s1 = 7, nums1[] = {2,3,1,2,4,3};
    printf("%d\n", minSubArrayLen(s1, nums1, sizeof(nums1) / sizeof(int))); // 2
    int s2 = 4, nums2[] = {1,4,4};
    printf("%d\n", minSubArrayLen(s2, nums2, sizeof(nums2) / sizeof(int))); // 1
    int s3 = 11, nums3[] = {1,1,1,1,1,1,1,1};
    printf("%d\n", minSubArrayLen(s3, nums3, sizeof(nums3) / sizeof(int))); // 0
    return 0;
}