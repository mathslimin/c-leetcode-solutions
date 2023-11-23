#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isMatch(char* s, char* p) {
    int lens, lenp;
    int index_s, index_p;
    int back;
    int prev_s, prev_p;

    lens = strlen(s);
    lenp = strlen(p);
    index_s = 0;
    index_p = 0;
    back = 0;

    while(index_s < lens){
        if(index_p < lenp && (p[index_p] == '?' || p[index_p] == s[index_s])){
            index_s++;
            index_p++;
        }else if(p[index_p] == '*'){
            while(index_p < lenp && p[index_p] == '*')
                index_p++;

            if(index_p == lenp)
                return true;

            back = 1;
            prev_s = index_s;
            prev_p = index_p;
        }else if(back){
            prev_s++;
            index_s = prev_s;
            index_p = prev_p;
        }else{
            return false;
        }
    }

    while(index_p < lenp && p[index_p] == '*')
        index_p++;

    return index_p == lenp;
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