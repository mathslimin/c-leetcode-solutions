#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isIsomorphic(char* s, char* t) {
    int ms[256] = {0};
    int mt[256] = {0};

    int len = strlen(s);

    for(int i = 0; i < len; ++i){
        if(ms[s[i]] != mt[t[i]])
            return false;

        ms[s[i]] = i + 1;
        mt[t[i]] = i + 1;
    }

    return true;
}

int main() {
    char* s = "egg";
    char* t = "add";
    bool res = isIsomorphic(s, t);
    printf("%d", res);
    return 0;
}