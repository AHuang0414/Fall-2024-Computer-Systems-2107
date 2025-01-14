#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void rm_left_space(char *s) {
    int startIndex = 0;
    int length = 0;
    while(s[length]!='\0')
    {
        if (!isspace(s[length])) {
            startIndex = length;
            break;
        }
        length++;
    }
    
    printf("\"%s\"", (s + startIndex));
}