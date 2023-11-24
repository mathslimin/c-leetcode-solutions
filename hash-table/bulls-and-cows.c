#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* getHint(char* secret, char* guess)
{
    int* ret;
    int a = 0;
    int b = 0;
    int len = strlen(guess);
    int m[256] = {0};

    ret = malloc(sizeof(int) * (len + 2));

    for (int i = 0; i < len; ++i) {
        if (secret[i] == guess[i]) {
            ++a;
        } else {
            m[secret[i]]++;
        }
    }

    for (int i = 0; i < len; ++i) {
        if (secret[i] != guess[i] && m[guess[i]]) {
            m[guess[i]]--;
            ++b;
        }
    }

    len = sprintf(ret, "%dA%dB", a, b);
    ret[len] = 0;

    return ret;
}

int main() {
    char* secret = "1807";
    char* guess = "7810";
    char* res = getHint(secret, guess);
    printf("%s", res); // 1A3B
    free(res);
    return 0;
}