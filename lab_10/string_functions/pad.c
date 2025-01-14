#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

char *pad(char *s, int d) {
    int LENGTH = 0;
    while (s[LENGTH] != '\0') LENGTH++;

    if (d < LENGTH) d = LENGTH;

    char *newStr = (char*)malloc(sizeof(char) * d+1);
    if (newStr == NULL) return NULL;

    int index = 0;
    while (index < d) {
        if (*(s + index) != '\0' && index < LENGTH) {
            *(newStr + index) = *(s + index);
        }
        else {
            *(newStr + index) = ' ';
        }
        index++;
    }
    *(newStr + d) = '\0';

    return newStr;
}