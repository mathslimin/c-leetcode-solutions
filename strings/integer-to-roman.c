#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
1. 从大到小列出罗马数字，包括基本数字和组合数字。
2. 将数字num从大到小依次与罗马数字进行比较，如果num大于等于当前罗马数字，则将该罗马数字加入结果字符串中，并将num减去该罗马数字。
3. 重复步骤2，直到num为0。
*/
char* intToRoman(int num) {
    char* roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* result = (char*)malloc(sizeof(char) * 20); // 结果字符串
    int index = 0; // 结果字符串的下标
    int i;
    for (i = 0; i < 13; i++) {
        while (num >= value[i]) { // 如果num大于等于当前罗马数字，则将该罗马数字加入结果字符串中，并将num减去该罗马数字
            num -= value[i];
            int len = strlen(roman[i]);
            memcpy(result + index, roman[i], len);
            index += len;
        }
    }
    result[index] = '\0'; // 将结果字符串末尾置为'\0'
    return result;
}

int main() {
    int num = 1994;
    char* result = intToRoman(num);
    printf("%d = %s", num, result);
    free(result);
    return 0;
}