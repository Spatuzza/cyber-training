#include <string.h>
#include "password.h"

int check_length(const char *password) {
    if(strlen(password)>8){
        return 1;
    }else{
        return 0;
    }
}

int analyze_password(const char *p){
    int flags = 0;
    for(int i = 0; p[i] != '\0'; i++){
        if(p[i] >= 'A' && p[i] <= 'Z') flags |= HAS_UPPER;
        else if(p[i] >= 'a' && p[i] <= 'z') flags |= HAS_LOWER;
        else if(p[i] >= '0' && p[i] <= '9') flags |= HAS_DIGIT;
        else flags |= HAS_SYMBOL;
    }
    if (check_length(p)) flags |= HAS_LENGTH;
    return flags;
}

int analyze_flags(int flags){
    int score = 0;
    int mask = flags & (HAS_UPPER|HAS_LOWER|HAS_DIGIT|HAS_SYMBOL|HAS_LENGTH);

    while (mask != 0){
        score += (mask & 1);
        mask >>= 1;
    }
    return score;
}

