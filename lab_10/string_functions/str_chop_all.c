#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

char **str_chop_all(char *s, char c) {
    int countC = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) countC++;
    }

    char **newStr = (char **)malloc((countC * sizeof(char *)) + 1);
    if (newStr == NULL) return NULL;

    int total_index = 0;
    for (int row = 0; row < countC; row++) {
        int index = 0;
        while (s[total_index] != c) {
            index++;
            total_index++;
            if (s[total_index] == '\0') break;
        }
        newStr[row] = (char *)malloc(sizeof(char) * (index +1));
        if (newStr[row] == NULL) return NULL;

        for (int i = 0; i < index; i++) {
            newStr[row][i] = s[total_index-index+i];
        }
        newStr[row][index] = '\0';
        total_index++;
    }
    newStr[countC] = NULL;
    
    return newStr;
}