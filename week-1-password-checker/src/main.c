#include <stdio.h>
#include "password.h"

static const char* strength_label(int score) {
    if (score <= 2) return "WEAK";
    if (score <= 4) return "MEDIUM";
    return "STRONG";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    const char *p = argv[1];

    int flags = analyze_password(p);
    int score = analyze_flags(flags); // o score_from_flags(flags)

    printf("Length:    %s\n", (flags & HAS_LENGTH) ? "OK" : "NO");
    printf("Uppercase: %s\n", (flags & HAS_UPPER)  ? "OK" : "NO");
    printf("Lowercase: %s\n", (flags & HAS_LOWER)  ? "OK" : "NO");
    printf("Digit:     %s\n", (flags & HAS_DIGIT)  ? "OK" : "NO");
    printf("Symbol:    %s\n", (flags & HAS_SYMBOL) ? "OK" : "NO");

    printf("\nScore: %d/5\n", score);
    printf("Strength: %s\n", strength_label(score));

    return 0;
}
