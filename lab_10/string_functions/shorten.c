#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void shorten(char *s, int new_len) {
    // printf("%d\n", sizeof(char));
    char *newStr = (char *)calloc(new_len+1, sizeof(char)); // +1 for '\0'
    if (newStr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    int index = 0;
    while (index < new_len && s[index] != '\0' )
    {
        newStr[index] = s[index];
        index++;
    }
    
    newStr[new_len] = '\0';

    printf("%s", newStr);
    free(newStr);
}