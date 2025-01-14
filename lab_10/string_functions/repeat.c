#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

char *repeat(char *s, int x, char sep) {
    if (s == NULL) return NULL;

    int LENGTH = 0;
    while (s[LENGTH] != '\0') LENGTH++;
    int TOTAL_LENGTH = (LENGTH * x) + (x-1);

    char *newStr = (char*)malloc(sizeof(char) * (TOTAL_LENGTH + 1));
    if (newStr == NULL) return NULL;  

    int total_index = 0;
    for (int i = 0; i < x; i++) {
        int index = 0;
        while (s[index] != '\0') {
            newStr[total_index] = s[index];
            total_index++;
            index++;
        }
        newStr[total_index] = sep;
        total_index++;
    }
    newStr[TOTAL_LENGTH] = '\0';

    return newStr;
}