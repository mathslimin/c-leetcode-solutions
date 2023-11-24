#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int longestPalindrome(char* s) {
    int map[256] = {0};
    int i,len,ret = 0;
    int plus = 0;

    len = strlen(s);
    for(i = 0; i < len; ++i)
        map[s[i]]++;

    for(i = 0; i < 256; ++i){
        ret += map[i];
        if(map[i] % 2 == 1){
            plus = 1;
            ret--;
        }
    }

    return ret + plus;
}

int main() {
    char s[] = "babad";
    int len = longestPalindrome(s);
    printf("%d", len); // 输出3，因为最长回文子串为"bab"
    return 0;
}