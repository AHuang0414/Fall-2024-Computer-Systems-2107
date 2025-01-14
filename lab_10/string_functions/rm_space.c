#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void rm_space(char *s) {
    int length = 0;
    while (s[length] != '\0') {
        // printf("%c ", s[length]);
        length++;
    }

    char newStr[length+1];

    int index = 0;
    while (*s != '\0') {
        if (!isspace(*s)) {
            newStr[index] = *s;
            index++;
        }
        s++;
    }

    newStr[index] = '\0';

    printf("\"%s\"", newStr);
}