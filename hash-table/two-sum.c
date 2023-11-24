#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* twoSum(int* nums, int numsSize, int target){
    int* res = (int*)malloc(sizeof(int) * 2);
    int hashTable[20001] = {0}; // 哈希表，存储每个元素的值和下标
    for(int i = 0; i < numsSize; i++){
        int complement = target - nums[i]; // 计算差值
        if(hashTable[complement + 10000] != 0){ // 如果哈希表中存在差值的下标
            res[0] = hashTable[complement + 10000] - 1; // 返回两个数的下标
            res[1] = i;
            return res;
        }
        hashTable[nums[i] + 10000] = i + 1; // 将当前元素的值和下标存入哈希表
    }
    return res;
}

int main(){
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int* res = twoSum(nums, numsSize, target);
    printf("[%d, %d]", res[0], res[1]);
    free(res);
    return 0;
}