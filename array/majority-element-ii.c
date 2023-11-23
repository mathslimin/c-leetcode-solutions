#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int *ret;
    int c1,c2,arr1,arr2;
    int i;
    int size = 0;

    arr1 = nums[0];
    arr2 = nums[0];
    c1 = 0;
    c2 = 0;
    for(i = 0; i < numsSize; ++i){
        if(arr1 == nums[i]){
            c1++;
            continue;
        }

        if(arr2 == nums[i]){
            c2++;
            continue;
        }

        if(c1 == 0){
            arr1 = nums[i];
            c1++;
            continue;
        }

        if(c2 == 0){
            arr2 = nums[i];
            c2++;
            continue;
        }

        c1--;
        c2--;
    }

    c1 = 0;
    c2 = 0;
    for(i = 0; i < numsSize; ++i){
        if(arr1 == nums[i])
            c1++;
        else if(arr2 == nums[i])
            c2++;
    }

    ret = (int *)malloc(sizeof(int) * 2);
    if(c1 > numsSize / 3)
        ret[size++] = arr1;
    if(c2 > numsSize / 3)
        ret[size++] = arr2;

    *returnSize = size;

    return ret;
}

int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int* res = majorityElement(nums, numsSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);
    return 0;
}
