#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void reverse(int *nums, int start, int end)
{
    int tmp;
    while(start < end){
        tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;

        ++start;
        --end;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums,0,numsSize - k - 1);
    reverse(nums,numsSize - k,numsSize -1);
    reverse(nums,0,numsSize-1);
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(int);
    int k = 3;
    rotate(nums, numsSize, k);
    printf("After rotating %d steps, the array becomes: ", k);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
