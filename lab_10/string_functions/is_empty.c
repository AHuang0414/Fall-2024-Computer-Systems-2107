#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int is_empty(char *s) {
    if (s == NULL || s[0] == '\0') return 1;

    while (*s != '\0') {
        if (!isspace(*s)) {
            return 0;
        }
        s++;
    }

    return 1; //assume empty by default
}