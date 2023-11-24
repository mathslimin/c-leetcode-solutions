#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addDigits(int num) {
    return 1 + (num - 1) % 9;
}

int main() {
    int num = 38;
    printf("%d", addDigits(num)); // expected output: 2
    return 0;
}