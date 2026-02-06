#ifndef PASSWORD_H
#define PASSWORD_H
#define HAS_UPPER 1 //0001
#define HAS_LOWER 2 //0010
#define HAS_DIGIT 4 //0100
#define HAS_SYMBOL 8 //1000
#define HAS_LENGTH 16  // 10000 
#include <stddef.h>

int analyze_password(const char *p);
int analyze_flags(int flags); 

#endif
