#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void rm_empties(char **words) {
    int validIndex = 0;
    for (int i = 0; words[i] != NULL; i++) {
        if (words[i][0] != '\0') {
            words[validIndex] = words[i];
            validIndex++;
        }
    }

    words[validIndex] = NULL;

    for (int i = 0; words[i] != NULL; i++) {
        printf("%s", words[i]);
        printf(" ");
    }
}