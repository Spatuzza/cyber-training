# Password Strength Checker (C)

Educational CLI tool written in C to analyze password strength using bit flags.

## Features
- Length analysis
- Uppercase / lowercase detection
- Digit detection
- Symbol detection
- Automatic score calculation (bitmask-based)

## Build
```bash
gcc src/main.c src/password.c -Iinclude -o passcheck
