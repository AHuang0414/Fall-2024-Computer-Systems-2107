#include "mylib.h"
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h> 

int all_letters(char *s) {
    while (*s != '\0') {
        if (!isalpha(*s) && !isspace(*s)) {
            return 0;
        }
        s++;
    }

    return 1;
}

int num_in_range(char *s1, char b, char t) {  
    int num = 0;
    
    while (*s1 != '\0') {
        if (toupper(b) <= toupper(*s1) &&  toupper(*s1) <= toupper(t)) {
            num++;
        }
        s1++;
    }

    return num;
}

int diff(char *s1, char *s2) {
    int diffCount = 0;

    int length1 = 0;
    while(s1[length1]!='\0')
    {
        length1++;
        // printf("Length 1: %i\n", length1);
    }

    int length2 = 0;
    while(s2[length2]!='\0')
    {
        length2++;
        // printf("Length 2: %i\n", length2);
    }

    if (length1 > length2) {
        // puts("s1 larger");
        length2 = length1;
        length1 = 0;
        while (length1 < length2) {
            if (s1[length1] != s2[length1]) diffCount++;
            length1++;
        }
    }
    else if (length1 == length2) {
        // puts("equal length");
        length1 = 0;
        while (length1 < length2) {
            if (s1[length1] != s2[length1]) diffCount++;
            length1++;
        }
    }
    else {
        // puts("s2 larger");
        length1 = length2;
        length2 = 0;
        while (length1 > length2) {
            if (s1[length2] != s2[length2]) diffCount++;
            length2++;
        }
    } 
    
    return diffCount;
}

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

int len_diff(char *s1, char *s2) {
    int length1 = 0;
    int length2 = 0;

    while(s1[length1]!='\0')
    {
        length1++;
    }
    while(s2[length2]!='\0')
    {
        length2++;
    }

    return length1 - length2;
}

void rm_left_space(char *s) {
    int startIndex = 0;
    int length = 0;
    while(s[length]!='\0')
    {
        if (!isspace(s[length])) {
            startIndex = length;
            break;
        }
        length++;
    }
    
    printf("%s", (s + startIndex));
}

void rm_right_space(char *s) {
    int length = 0;
    while (s[length] != '\0') {
        // printf("%c ", s[length]);
        length++;
    }
    // printf("%d", length);

    while (length > 0) {
        if (!isspace(s[length-1])) {
            // printf("%d", length);
            break;
        }
        length--;
    }
    
    printf("%.*s", length, s);
}

void rm_space(char *s) {
    
}