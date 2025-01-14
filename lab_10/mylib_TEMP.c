#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
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
    
    printf("\"%s\"", (s + startIndex));
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
    
    printf("\"%.*s\"", length, s);
}

void rm_space(char *s) {
    int length = 0;
    while (s[length] != '\0') {
        // printf("%c ", s[length]);
        length++;
    }

    char newStr[length+1];

    int index = 0;
    while (*s != '\0') {
        if (!isspace(*s)) {
            newStr[index] = *s;
            index++;
        }
        s++;
    }

    newStr[index] = '\0';

    printf("\"%s\"", newStr);
}

int find(char *h, char *n) {
    for (int i = 0; h[i] != '\0'; i++) {
        if (h[i] == *n) return i;
    }

    return -1;
}

char *ptr_to(char *h, char *n) {
    while (*h != '\0') {
        if (*n == *h) {
            return h;
        }
        h++;
    }

    return NULL;
}

int is_empty(char *s) {
    if (s == NULL || s[0] == '\0') return 1;

    while (*s != '\0') {
        if (!isspace(*s)) {
            return 0;
        }
        s++;
    }

    return 1; //assume empty by default
}

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

int strcmp_ign_case(char *s1, char *s2) {
    // A < Z (A is valued less than Z b/c ASCII)
    // A appears before Z
    //CASE 1: if s1, then s2 (-)
    //CASE 2: if s2, then s1 (+)
    //DEFAULT: equal (0)

    while (*s1 != '\0' || *s2 != '\0') {
        if (toupper(*s1) < toupper(*s2)) { // CASE 1
            return -1;
        }
        else if (toupper(*s1) == toupper(*s2)) {
            s1++;
            s2++;
            continue;
        }
        else {
            return 1;
        }
    }

    return 0; //assume equal default
}

void take_last(char *s, int n) {
    int LENGTH = 0;
    while (s[LENGTH] != '\0') LENGTH++;

    if (n >= LENGTH) return;
    
    for (int index = 0; s[LENGTH-n + index] != '\0'; index++) {
        s[index] = s[LENGTH-n + index];
    }

    s[n] = '\0';
}

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

char *pad(char *s, int d) {
    int LENGTH = 0;
    while (s[LENGTH] != '\0') LENGTH++;

    if (d < LENGTH) d = LENGTH;

    char *newStr = (char*)malloc(sizeof(char) * d+1);
    if (newStr == NULL) return NULL;

    int index = 0;
    while (index < d) {
        if (*(s + index) != '\0' && index < LENGTH) {
            *(newStr + index) = *(s + index);
        }
        else {
            *(newStr + index) = ' ';
        }
        index++;
    }
    *(newStr + d) = '\0';

    return newStr;
}

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

char *repeat(char *s, int x, char sep) {
    if (s == NULL) return NULL;

    int LENGTH = 0;
    while (s[LENGTH] != '\0') LENGTH++;
    int TOTAL_LENGTH = (LENGTH * x) + (x-1);

    char *newStr = (char*)malloc(sizeof(char) * (TOTAL_LENGTH + 1));
    if (newStr == NULL) return NULL;  

    int total_index = 0;
    for (int i = 0; i < x; i++) {
        int index = 0;
        while (s[index] != '\0') {
            newStr[total_index] = s[index];
            total_index++;
            index++;
        }
        newStr[total_index] = sep;
        total_index++;
    }
    newStr[TOTAL_LENGTH] = '\0';

    return newStr;
}

char *replace(char *s, char *pat, char *rep) {
    int OG_LENGTH = 0, PAT_LENGTH = 0, REP_LENGTH = 0;
    while (s[OG_LENGTH] != '\0') OG_LENGTH++;
    while (rep[REP_LENGTH] != '\0') REP_LENGTH++;
    while (pat[PAT_LENGTH] != '\0') PAT_LENGTH++;

    int patCount = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        bool isPat = true;
        if (toupper(pat[0]) == toupper(s[i])) {
            for (int j = 0; j < PAT_LENGTH; j++) {
                if (toupper(pat[j]) != toupper(s[j + i])) {
                    isPat = false;
                    break;
                }
            }
            if (isPat) {
                patCount++;
            }
        }
    }

    int TOTAL_LENGTH = OG_LENGTH - (patCount * PAT_LENGTH) + (patCount * REP_LENGTH); // i.e. bobisdadis = 10, is = 2, beep = 4 (total should be 14 = bobbeepdadbeep);  10 - (2 * 2) + (2 * 4) = 10 - 4 + 8 = 14
    char *newStr = (char*)malloc(sizeof(char) * (TOTAL_LENGTH + 1));
    if (newStr == NULL) return NULL;

    int s_index = 0, new_index = 0;
    while (s[s_index] != '\0') {
        bool isPat = false;
        if (toupper(pat[0]) == toupper(s[s_index])) {
            isPat = true;
            for (int i = 0; i < PAT_LENGTH; i++) {
                if (toupper(s[s_index + i]) != toupper(pat[i])) {
                    isPat = false;
                    break;
                }
            }
        }
        
        if (isPat) {
            for (int i = 0; i < REP_LENGTH; i++) {
                newStr[new_index] = rep[i];
                new_index++;
            }
            s_index += PAT_LENGTH;
        }
        else {
            newStr[new_index] = s[s_index];
            new_index++;
            s_index++;
        }

    }

    newStr[TOTAL_LENGTH] = '\0';

    return newStr;
}

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