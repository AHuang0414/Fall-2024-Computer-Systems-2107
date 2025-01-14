#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

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