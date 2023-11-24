#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int carry = 1;
    int* ret;
    int count;
    int i;

    count = digitsSize + 1;
    ret = (int*)malloc(sizeof(int) * count);

    for (i = digitsSize - 1; i >= 0; --i) {
        ret[--count] = (digits[i] + carry) % 10;
        carry = (digits[i] + carry) / 10;
    }

    if (carry)
        ret[--count] = 1;

    *returnSize = digitsSize + 1 - count;

    return ret + count;
}

int main() {
    int digits[] = {1, 2, 3};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize;
    int* result = plusOne(digits, digitsSize, &returnSize);
    printf("Input: [");
    for (int i = 0; i < digitsSize; i++) {
        printf("%d", digits[i]);
        if (i != digitsSize - 1) {
            printf(", ");
        }
    }
    printf("]Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i != returnSize - 1) {
            printf(", ");
        }
    }
    printf("]");
    return 0;
}