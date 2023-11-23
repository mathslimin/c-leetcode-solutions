#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *arr;
    int i;
    int carry = 1;
    int offset = 1;

    arr = (int *)malloc(sizeof(int) * (digitsSize+1));

    for(i = digitsSize-1; i >= 0; --i){
        int  tmp = digits[i] + carry;
        carry = tmp / 10;
        arr[i+1] = tmp % 10;
    }

    if(carry){
        arr[0] = carry;
        offset--;
    }

    *returnSize = digitsSize + 1 - offset;
    return arr + offset;
}

int main(){
    int digits[] = {1,2,3};
    int digitsSize = 3;
    int returnSize;
    int* result = plusOne(digits, digitsSize, &returnSize);
    printf("[");
    for(int i = 0; i < returnSize; i++){
        printf("%d", result[i]);
        if(i != returnSize - 1) printf(",");
    }
    printf("]");
    free(result);
    return 0;
}
