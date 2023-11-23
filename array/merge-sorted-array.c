#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int end = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while(i >= 0 && j >= 0)
        nums1[end--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

    while(i >= 0)
        nums1[end--] = nums1[i--];

    while(j >= 0)
        nums1[end--] = nums2[j--];
}

int main() {
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int nums2[3] = {2, 5, 6};
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");
    return 0;
}
