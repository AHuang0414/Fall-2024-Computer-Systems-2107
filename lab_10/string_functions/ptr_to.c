#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

char *ptr_to(char *h, char *n) {
    while (*h != '\0') {
        if (*n == *h) {
            return h;
        }
        h++;
    }

    return NULL;
}