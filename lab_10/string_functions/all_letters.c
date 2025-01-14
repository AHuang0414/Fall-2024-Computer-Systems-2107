#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int all_letters(char *s) {
    while (*s != '\0') {
        if (!isalpha(*s) && !isspace(*s)) {
            return 0;
        }
        s++;
    }

    return 1;
}