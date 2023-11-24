#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    int rx = 0;
    int tmp = x;
    while (tmp) {
        rx = 10 * rx + (tmp % 10);
        tmp /= 10;
    }

    return rx == x;
}

int main() {
    int num1 = 12321;
    int num2 = -123;
    int num3 = 10;
    bool res1 = isPalindrome(num1);
    bool res2 = isPalindrome(num2);
    bool res3 = isPalindrome(num3);
    printf("%d\n", res1); // 1
    printf("%d\n", res2); // 0
    printf("%d\n", res3); // 0
    return 0;
}