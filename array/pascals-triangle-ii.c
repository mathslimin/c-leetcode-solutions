#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* getRow(int rowIndex, int* returnSize) {
    int *ret;
    int i,j;
    int tmp,prev;

    ret = (int *)malloc(sizeof(int) * (rowIndex + 1));
    memset(ret,0,sizeof(int) * (rowIndex + 1));

    for(i = 0; i <= rowIndex; ++i){
        ret[0] = 1;
        prev = ret[0];
        for(j = 1; j < i; ++j){
            tmp = ret[j];
            ret[j] = prev + ret[j];
            prev = tmp;
        }
        ret[i] = 1;
    }

    *returnSize = rowIndex + 1;
    return ret;
}

int main() {
    int rowIndex = 3; // 测试用例
    int returnSize;
    int* row = getRow(rowIndex, &returnSize);
    printf("The %dth row of Pascal's Triangle is: ", rowIndex);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", row[i]);
    }
    printf("\n");
    free(row); // 释放内存空间
    return 0;
}
