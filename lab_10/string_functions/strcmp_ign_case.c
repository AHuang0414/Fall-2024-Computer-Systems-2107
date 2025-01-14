#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int strcmp_ign_case(char *s1, char *s2) {
    // A < Z (A is valued less than Z b/c ASCII)
    // A appears before Z
    //CASE 1: if s1, then s2 (-)
    //CASE 2: if s2, then s1 (+)
    //DEFAULT: equal (0)

    while (*s1 != '\0' || *s2 != '\0') {
        if (toupper(*s1) < toupper(*s2)) { // CASE 1
            return -1;
        }
        else if (toupper(*s1) == toupper(*s2)) {
            s1++;
            s2++;
            continue;
        }
        else {
            return 1;
        }
    }

    return 0; //assume equal default
}