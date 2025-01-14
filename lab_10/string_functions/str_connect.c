#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

char *str_connect(char **strs, int n, char c) {
    int LENGTH = 0;
    for (int i = 0; i < n; i++) {
        // printf("%s\n", strs[i]);
        int tempLength = 0;
        while (strs[i][tempLength] != '\0') {
            LENGTH++;
            tempLength++;
        }
    }
    // printf("Length is: %d\n", LENGTH);
    int TOTAL_LENGTH = LENGTH + (n-1);
    // printf("Total Length is: %d\n", TOTAL_LENGTH);

    char *newStr = malloc(sizeof(char) * (TOTAL_LENGTH + 1));
    if (newStr == NULL) return NULL;

    int new_index = 0;
    for (int i = 0; i < n; i++) {
        // printf("%s\n", strs[i]);
        int temp_index = 0;
        while (strs[i][temp_index] != '\0') {
            newStr[new_index] = strs[i][temp_index];
            temp_index++;
            new_index++;
        }
        newStr[new_index] = c;
        new_index++;
    }
    newStr[TOTAL_LENGTH] = '\0';

    return newStr;
}