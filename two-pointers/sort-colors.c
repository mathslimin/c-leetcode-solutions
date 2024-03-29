#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortColors(int* nums, int numsSize)
{
    int i;
    int zero, one, two;

    zero = one = two = 0;
    for (i = 0; i < numsSize; ++i) {
        if (nums[i] == 0) {
            nums[two++] = nums[one];
            nums[one++] = nums[zero];
            nums[zero++] = 0;
        } else if (nums[i] == 1) {
            nums[two++] = nums[one];
            nums[one++] = 1;
        } else {
            nums[two++] = 2;
        }
    }
}

int main(){
    int nums[] = {2,0,2,1,1,0};
    int numsSize = 6;
    sortColors(nums, numsSize);
    for(int i=0; i<numsSize; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}