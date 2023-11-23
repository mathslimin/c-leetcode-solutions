// 4. 寻找两个正序数组的中位数

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int len1;
int len2;

int findKth(int *a, int sa, int *b, int sb, int k)
{
    if(sa >= len1)
        return b[sb + k - 1];
    if(sb >= len2)
        return a[sa + k - 1];
    if(k == 1)
        return a[sa] < b[sb] ? a[sa] : b[sb];

    int ka = sa + k / 2 - 1 >= len1 ? INT_MAX
        : a[sa + k / 2 - 1];
    int kb = sb + k / 2 - 1 >= len2 ? INT_MAX
        : b[sb + k / 2 - 1];
    if(ka < kb)
        return findKth(a, sa + k / 2, b, sb, k - k / 2);
    else
        return findKth(a, sa, b, sb + k / 2, k - k / 2);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len;

    len1 = nums1Size;
    len2 = nums2Size;
    len = len1 + len2;

    if(len % 2)
        return findKth(nums1, 0, nums2, 0, len / 2 + 1);
    else
        return (findKth(nums1, 0, nums2, 0, len / 2) +
            findKth(nums1, 0, nums2, 0, len / 2 + 1)) / 2.0;
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int nums1Size = 2;
    int nums2Size = 1;
    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("The median is %f", result);

    int nums3[] = {1, 2};
    int nums4[] = {3, 4};
    int nums3Size = 2;
    int nums4Size = 2;
    result = findMedianSortedArrays(nums3, nums3Size, nums4, nums4Size);
    printf("The median is %f", result);

    return 0;
}