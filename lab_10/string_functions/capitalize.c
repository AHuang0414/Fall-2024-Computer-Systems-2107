#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void capitalize(char *s) { 
    int LENGTH = 0;
    while (s[LENGTH] != '\0') LENGTH++;

    char *newStr = (char*)malloc(sizeof(char) * LENGTH+1); // +1 for '\0'
    
    int index = 0;
    while (s[index] != '\0') {
        if (isalpha(s[index]) && (index == 0 || isspace(s[index-1]))) {
            newStr[index] = toupper(s[index]);
        }
        else {
            newStr[index] = tolower(s[index]);
        }
        index++;
    }

    newStr[LENGTH] = '\0';

    printf("%s", newStr);
    free(newStr);
}