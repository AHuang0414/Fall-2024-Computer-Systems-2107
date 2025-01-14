#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int ends_with_ignore_case(char *s, char *suff) {
    int SUFF_LENGTH = 0, LENGTH = 0;
    while (suff[SUFF_LENGTH] != '\0') SUFF_LENGTH++;
    while (s[LENGTH] != '\0') LENGTH++;
    
    int startIndex = LENGTH - SUFF_LENGTH;
    if (startIndex < 0) return 0;

    int count = 0;
    while (s[startIndex]!= '\0') {
        if (toupper(suff[count]) == toupper(s[startIndex])) count++;
        startIndex++;
    }

    if (count != SUFF_LENGTH) return 0;

    return 1; //assume it is suffix
}