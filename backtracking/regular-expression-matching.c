#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isMatch(char* s, char* p) {
    if(*p == 0)
        return *s == 0;

    if(p[1] != '*')
        return (*s == *p || (*p == '.' && *s != 0)) &&
            isMatch(s+1,p+1);

    while(*s == *p || (*p == '.' && *s != 0)){
        if(isMatch(s,p+2))
            return true;
        s++;
    }

    return isMatch(s,p+2);
}

int main() {
    char s[] = "aa";
    char p[] = "a*";
    bool result = isMatch(s, p);
    printf("%s", result ? "true" : "false");
    return 0;
}