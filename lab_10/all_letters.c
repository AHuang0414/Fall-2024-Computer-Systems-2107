#include "mylib.h"
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h> 

int all_letters(char *s) {
    while (*s != '\0') {
        if (isalpha(*s)) {
            continue;
        }
        else {
            return 0;
        }
    }
    
    return 1;
}