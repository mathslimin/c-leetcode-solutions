#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeElement(int* nums, int numsSize, int val)
{
    int count = -1;
    int i;

    for (i = 0; i < numsSize; ++i)
        if (nums[i] != val)
            nums[++count] = nums[i];

    return count + 1;
}

int main() {
    int nums[] = {1,1,1,2,2,3};
    int numsSize = sizeof(nums) / sizeof(int);

    int newNumsSize = removeElement(nums, numsSize, 2);

    printf("new array: ");
    for (int i = 0; i < newNumsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}