#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addDigits(int num)
{
    int ret = num;
    while (num > 9) {
        ret = 0;
        while (num) {
            ret += (num % 10);
            num /= 10;
        }
        num = ret;
    }

    return ret;
}

int main() {
    int num = 38;
    printf("%d", addDigits(num)); // expected output: 2
    return 0;
}