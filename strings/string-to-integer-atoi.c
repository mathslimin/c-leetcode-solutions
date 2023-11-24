#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int myAtoi(char* str)
{
    int is_neg;
    int ret;

    is_neg = 1;
    while (*str == ' ')
        str++;

    if (*str == '+') {
        str++;
    } else if (*str == '-') {
        is_neg = -1;
        str++;
    }

    ret = 0;
    while (*str && (*str >= '0' && *str <= '9')) {
        int tmp = ret;
        ret = (ret * 10) + *str - '0';
        if (ret / 10 != tmp)
            return is_neg == -1 ? INT_MIN : INT_MAX;
        str++;
    }

    return is_neg * ret;
}

int main() {
    char str1[] = "42";
    char str2[] = "   -42";
    char str3[] = "4193 with words";
    char str4[] = "words and 987";
    char str5[] = "-91283472332";
    printf("%d\n", myAtoi(str1)); // expected output: 42
    printf("%d\n", myAtoi(str2)); // expected output: -42
    printf("%d\n", myAtoi(str3)); // expected output: 4193
    printf("%d\n", myAtoi(str4)); // expected output: 0
    printf("%d\n", myAtoi(str5)); // expected output: -2147483648
    return 0;
}