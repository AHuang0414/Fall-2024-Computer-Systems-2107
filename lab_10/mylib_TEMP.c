#include "mylib.h"
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
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

int num_in_range(char *s1, char b, char t) {  
    int num = 0;
    
    while (*s1 != '\0') {
        if (toupper(b) <= toupper(*s1) &&  toupper(*s1) <= toupper(t)) {
            num++;
        }
        s1++;
    }

    return num;
}