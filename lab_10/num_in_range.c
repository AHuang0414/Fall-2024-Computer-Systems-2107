#include "mylib.h"
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h> 

int num_in_range(char *s1, char b, char t) {
    char uppercaseAlpha[26] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    
    int num = 0;
    int currentIndex = 0;
    int endIndex = 0;
    char *temp = s1;
    for (int i = 0; i < 26; i++) {
        if (toupper(*temp) == uppercaseAlpha[i]) {
            currentIndex = i;
            break;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (toupper(t) == uppercaseAlpha[i]) {
            endIndex = i;
            break;
        }
    }

    while (*s1 != '\0' && currentIndex < endIndex) {
        if (toupper(*s1) == uppercaseAlpha[currentIndex]) {
            num++;
        }
        s1++;
    }

    return num;
}