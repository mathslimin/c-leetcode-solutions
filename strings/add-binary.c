#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//由于题目中要求返回字符串类型，因此我们需要先动态分配一个字符串数组来存储结果。然后从字符串的末尾开始逐位相加，同时考虑进位的情况，最后将结果反转输出即可。

char* addBinary(char* a, char* b) {
    int len_a = strlen(a), len_b = strlen(b);
    int len_res = len_a > len_b ? len_a : len_b;
    char* res = (char*)malloc((len_res + 1) * sizeof(char));
    res[len_res] = '\0';
    int carry = 0, i = len_a - 1, j = len_b - 1, k = len_res - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res[k--] = sum % 2 + '0';
        carry = sum / 2;
    }
    return res + k + 1;
}

int main() {
    char a[] = "1010";
    char b[] = "1011";
    char* res = addBinary(a, b);
    printf("%s", res);
    return 0;
}