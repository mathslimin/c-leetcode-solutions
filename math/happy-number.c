#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isHappy(int n)
{
    int flag[100];
    int result;

    memset(flag, 0, sizeof(int) * 100);

    while (n) {
        if (n == 1)
            return true;
        if (n < 100 && !flag[n])
            flag[n] = 1;
        else if (n < 100 && flag[n])
            break;
        result = 0;
        while (n) {
            result += (n % 10) * (n % 10);
            n /= 10;
        }

        n = result;
    }

    return false;
}

int main(){
    int n = 19;
    bool result = isHappy(n);
    printf("%d", result);
    return 0;
}