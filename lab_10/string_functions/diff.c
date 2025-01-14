#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int diff(char *s1, char *s2) {
    int diffCount = 0;

    int length1 = 0;
    while(s1[length1]!='\0')
    {
        length1++;
        // printf("Length 1: %i\n", length1);
    }

    int length2 = 0;
    while(s2[length2]!='\0')
    {
        length2++;
        // printf("Length 2: %i\n", length2);
    }

    if (length1 > length2) {
        // puts("s1 larger");
        length2 = length1;
        length1 = 0;
        while (length1 < length2) {
            if (s1[length1] != s2[length1]) diffCount++;
            length1++;
        }
    }
    else if (length1 == length2) {
        // puts("equal length");
        length1 = 0;
        while (length1 < length2) {
            if (s1[length1] != s2[length1]) diffCount++;
            length1++;
        }
    }
    else {
        // puts("s2 larger");
        length1 = length2;
        length2 = 0;
        while (length1 > length2) {
            if (s1[length2] != s2[length2]) diffCount++;
            length2++;
        }
    } 
    
    return diffCount;
}