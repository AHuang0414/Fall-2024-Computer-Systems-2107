#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void rm_right_space(char *s) {
    int length = 0;
    while (s[length] != '\0') {
        // printf("%c ", s[length]);
        length++;
    }
    // printf("%d", length);

    while (length > 0) {
        if (!isspace(s[length-1])) {
            // printf("%d", length);
            break;
        }
        length--;
    }
    
    printf("\"%.*s\"", length, s);
}