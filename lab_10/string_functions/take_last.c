#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void take_last(char *s, int n) {
    int LENGTH = 0;
    while (s[LENGTH] != '\0') LENGTH++;

    if (n >= LENGTH) return;
    
    for (int index = 0; s[LENGTH-n + index] != '\0'; index++) {
        s[index] = s[LENGTH-n + index];
    }

    s[n] = '\0';
}