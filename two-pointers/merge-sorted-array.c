#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**

题目描述：

给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 nums1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例：

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
*/
void merge(int* nums1, int m, int* nums2, int n)
{
    int end = m + n - 1;
    int i, j;

    i = m - 1;
    j = n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j])
            nums1[end--] = nums1[i--];
        else
            nums1[end--] = nums2[j--];
    }

    while (j >= 0)
        nums1[end--] = nums2[j--];
}

void printArray(int* nums, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", nums[i]);
        if (i != size - 1) {
            printf(",");
        }
    }
    printf("]");
}

int main() {
    int nums1[] = {1,2,3,0,0,0};
    int m = 3;
    int nums2[] = {2,5,6};
    int n = 3;
    merge(nums1, m, nums2, n);
    printArray(nums1, m + n);
    return 0;
}