#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

char *str_zip(char *s1, char *s2) {
    int LENGTH_PART_1 = 0;
    int LENGTH_PART_2 = 0;
    while (s1[LENGTH_PART_1] != '\0') {
        LENGTH_PART_1++;
    }
    while (s2[LENGTH_PART_2] != '\0') {
        LENGTH_PART_2++;
    }
    int LENGTH = LENGTH_PART_1 + LENGTH_PART_2; 
    // printf("%d\n", LENGTH);

    char *combinedString = (char *)malloc((LENGTH+1) * sizeof(char)); // +1 for '\0'
    combinedString[0] = 0;

    int index = 0, index_1 = 0, index_2 = 0;
    while(index < LENGTH) {
        if (index_1 < LENGTH_PART_1) {
            combinedString[index] = s1[index_1];
            index_1++;
            index++;
        }
        if (index_2 < LENGTH_PART_2) {
            combinedString[index] = s2[index_2];
            index_2++;
            index++;
        }
    }
    combinedString[LENGTH] = '\0';

    return combinedString;
}