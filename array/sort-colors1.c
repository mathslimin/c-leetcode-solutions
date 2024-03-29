#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void sortColors(int* nums, int numsSize) {
    int i;
    int zero = -1;
    int one = -1;
    int two = -1;

    for(i = 0; i < numsSize; ++i){
        if(nums[i] == 0){
            nums[++two] = 2;
            nums[++one] = 1;
            nums[++zero] = 0;
        }else if(nums[i] == 1){
            nums[++two] = 2;
            nums[++one] = 1;
        }else{
            nums[++two] = 2;
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
