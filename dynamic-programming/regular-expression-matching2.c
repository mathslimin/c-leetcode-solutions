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

    while((*s == *p) || (*p == '.' && *s != 0)){
        if(isMatch(s,p+2))
            return true;
        s++;
    }

    return isMatch(s,p+2);
}

int main() {
    char* s1 = "aa";
    char* p1 = "a";
    printf("%s, %s: %d", s1, p1, isMatch(s1, p1)); // false

    char* s2 = "aa";
    char* p2 = "*";
    printf("%s, %s: %d", s2, p2, isMatch(s2, p2)); // true

    char* s3 = "cb";
    char* p3 = "?a";
    printf("%s, %s: %d", s3, p3, isMatch(s3, p3)); // false

    char* s4 = "adceb";
    char* p4 = "*a*b";
    printf("%s, %s: %d", s4, p4, isMatch(s4, p4)); // true

    char* s5 = "acdcb";
    char* p5 = "a*c?b";
    printf("%s, %s: %d", s5, p5, isMatch(s5, p5)); // false

    return 0;
}