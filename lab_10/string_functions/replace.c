#include "mylib.h"
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

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