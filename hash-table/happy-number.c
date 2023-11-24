#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool happy(int n, int *count)
{
    if(n == 1)
        return true;
    if(*count == 100 || n == 0)
        return false;

    int tmp = 0;
    int d;
    while(n > 0){
        d = n % 10;
        n /= 10;
        tmp += d * d;
    }

    *count++;
    return happy(tmp,count);
}

bool isHappy(int n) {
    int count = 0;
    return happy(n,&count);
}

int main(){
    int n = 19;
    bool result = isHappy(n);
    printf("%d", result);
    return 0;
}