#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *arr;
    int num = nums1Size + nums2Size;
    int i,j,k;
    double ret;

    arr = (int *)malloc(sizeof(int) * num);
    i = 0;
    j = 0;
    k = 0;
    while(i < nums1Size && j < nums2Size)
        arr[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];

    while(i < nums1Size)
        arr[k++] = nums1[i++];
    while(j < nums2Size)
        arr[k++] = nums2[j++];

    if(num % 2)
        ret = arr[num/2];
    else
        ret = (arr[(num-1)/2] + arr[num/2]) / 2.0;

    free(arr);
    return ret;
}

int main() {
    int nums1[] = {1, 2, 4, 7};
    int nums1Size = 4;
    int nums2[] = {3, 5, 6};
    int nums2Size = 3;

    double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    printf("The median of the two sorted arrays is %.2f", median);

    return 0;
}
