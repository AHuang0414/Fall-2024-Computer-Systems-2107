#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

char *dedup(char *s) {
    int LENGTH = 0;
    while (s[LENGTH] != '\0') LENGTH++;
    char *newStr = (char*)(malloc(sizeof(char) * LENGTH+1));

    int index = 0, newIndex = 0;
    while (s[index] != '\0') {
        bool isDupe = false; 

        for (int i = 0; i < newIndex; i++) {
            if (newStr[i] == s[index]) {
                isDupe = true;
                break;
            }
        }
        if (!isDupe) {
            newStr[newIndex] = s[index];
            newIndex++;
        }
        index++;
    }
    newStr[newIndex] = '\0';

    return newStr;
}