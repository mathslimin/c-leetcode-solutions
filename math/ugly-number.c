#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isUgly(int num)
{
    if (num == 0)
        return false;

    while (num % 5 == 0)
        num /= 5;

    while (num % 3 == 0)
        num /= 3;

    while (num % 2 == 0)
        num /= 2;

    return num == 1;
}

int main() {
    int num = 1994;
    int result = isUgly(num);
    printf("%d = %d", num, result);
    return 0;
}