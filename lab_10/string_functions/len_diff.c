#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int len_diff(char *s1, char *s2) {
    int length1 = 0;
    int length2 = 0;

    while(s1[length1]!='\0')
    {
        length1++;
    }
    while(s2[length2]!='\0')
    {
        length2++;
    }

    return length1 - length2;
}