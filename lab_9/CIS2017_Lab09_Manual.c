/*
 * Name:	Andrew Huang
 * Section:	03
 * Lab:  	CIS2107_Lab09_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[], int size);
void endsWithed(char *string[], int size);

int main() {

    //random generator
    srand((unsigned)time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    puts("\n");
    //test for compareStr
    compareStr("Test1", "Test2");

    puts("");
    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    puts("\n");
    //test for randomize
    randomize();

    puts("\n");
    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    puts("\n");
    //test for reverse
    char line[] = "Hello world";
    // printf("%d", strlen(line));
    reverse(line);

    puts("");
    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    puts("\n");
    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    puts("\n");
    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    int size = sizeof(series) / sizeof(series[0]);
    startsWithB(series, size);

    puts("\n");
    //test for endsWithed
    endsWithed(series, size);
}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
    // printf("%c", *s); //T
    // printf("%s", s);
    // printf("%u", strlen(s)); //14
    // char upperStr[strlen(s)]; //make char array of same length as original
    // char lowerStr[strlen(s)]; //make char array of same length as original

    printf("Uppercase String: ");
    for (int i = 0; i < strlen(s); i++) {
        printf("%c", toupper(*(s + i)));
        // upperStr[i] = toupper(*(s + i));
    }

    puts("");

    printf("Lowercase String: ");
    for (int i = 0; i < strlen(s); i++) {
        printf("%c", tolower(*(s + i)));
    }

    // printf("Uppercase String: %s", upperStr);
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    int n1 = atoi(s1), n2 = atoi(s2), n3 = atoi(s3), n4 = atoi(s4);
    int numbers[4] = {n1, n2, n3, n4};
    
    // for (int i = 0; i < 4; i++) {
    //     printf("%d ", numbers[i]);
    // }

    return n1 + n2 + n3 + n4;
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    float f1 = atof(s1), f2 = atof(s2), f3 = atof(s3), f4 = atof(s4);

    return f1 + f2 + f3 + f4;
}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    int cmp = strcmp(s1, s2);
    if (cmp > 0) {
        printf("%s > %s", s1, s2);
    }
    else if (cmp < 0) {
        printf("%s < %s", s1, s2);
    }
    else {
        printf("%s == %s", s1, s2);
    }
}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
    int cmp = strncmp(s1, s2, n);
    // printf("%d", cmp);
    if (cmp > 0) {
        printf("%s > %s", s1, s2);
    }
    else if (cmp < 0) {
        printf("%s < %s", s1, s2);
    }
    else {
        printf("%s == %s", s1, s2);
    }
}

//6.(Random Sentences) 
void randomize(void) {
    char *articles[5] = {"the", "a", "one", "some", "any"};
    char *noun[5] = { "boy", "girl", "dog", "town", "car"};
    char *verbs[5] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[5] = {"to", "from", "over", "under", "on"};

    //Pattern: article + noun + verb + preposition + article + noun
    for (int i = 0; i < 30; i++) {
        int randomChoice = rand() % 5;
        // printf("%d ", randomChoice);
        // printf("%c ", articles[randomChoice][0]);
        // char *tempStr = articles[randomChoice];
        // printf("%s ", tempStr);
        // printf("%c%s ",toupper(articles[randomChoice][0]), tempStr+1);
        printf("%c%s ",toupper(articles[randomChoice][0]), (articles[randomChoice]+1));
        printf("%s ", noun[rand() % 5]);
        printf("%s ", verbs[rand() % 5]);
        printf("%s ", preposition[rand() % 5]);
        printf("%s ", articles[rand() % 5]);
        printf("%s. ", noun[rand() % 5]);
    }

}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
    // char strNum[12] = ""; // 10 + 1 (for the '\0')
    // for (int i = 0; i < strlen(num); i++) {
    //     char curNum = *(num + i);
    //     // printf("current char: %c\n", curNum);
    //     if (!isdigit(curNum)) {
    //         // printf("%c is not a char\n", curNum);
    //         continue;
    //     }
    //     // printf("current char: %c\n", curNum);
    //     char temp[2] = {curNum, '\0'};
    //     strcat(strNum, temp);
    // }
    // printf("Phone Number: %s", strNum);
    
    char strNum[12] = "";
    char *token = strtok(num, "()- ");
    int counter = 0;
    while (token != NULL) {
        // printf("Token Piece: %s\n", token);
        for (int i = 0; i < strlen(token); i++) {
            if (isdigit(token[i])) { 
                char temp[2] = {token[i], '\0'};
                strcat(strNum, temp); 
            }
        }
        counter++;
        if (counter == 1) strcat(strNum, " ");

        token = strtok(NULL, "()- "); // Get the next token
    }
    printf("Phone Number: %s", strNum);

    return 0;
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    // printf("length of text: %d\n", strlen(text));
    int lengthOfReverse = strlen(text);
    char copyText[lengthOfReverse+1];
    strcpy(copyText, text);
    // printf("Copied: %s\n", copyText);
    char *tokText = strtok(text, " ");
    int tokPartsCount = 0;
    
    while (tokText != NULL) { 
        // printf("Text Line: %s\n", tokText);
        // printf("length %d\n", strlen(tokText));
        tokPartsCount++;
        tokText = strtok(NULL, " ");
    }

    // printf("Num of tok parts: %d", tokPartsCount);
    char *tokArr[tokPartsCount];
    int arrCounter = 0;
    char *tokTextCopy = strtok(copyText, " ");
    
    while (tokTextCopy != NULL) {
        // printf("Text Line: %s\n", tokTextCopy);
        tokArr[arrCounter] = tokTextCopy; 
        // printf("array of pos %d is %s\n", arrCounter, tokArr[arrCounter]);
        arrCounter++;
        tokTextCopy = strtok(NULL, " ");
    }

    // printf("length of text: %d\n", strlen(text));
    char reverseStr[lengthOfReverse + 1]; // + 1 to ensure it has space for '/0'
    reverseStr[0] = '\0';

    for (int i = arrCounter-1; i >= 0; i--) {
        strcat(reverseStr, tokArr[i]);
        if (i > 0) strcat(reverseStr, " ");
    }

    printf("Reversed String: %s", reverseStr);
}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
    int count = 0;
    char *occur = strstr(line, sub);
    int subLength = strlen(sub);
    // printf("Sub %d\n", subLength);
    // printf("Substring is: [%s]\n", occur);

    int subPos = 0;
    for (int i = 0; i < strlen(occur); i++) {
        // printf("subPos: %d\n", subPos);
        if (occur[i] == sub[subPos]) {
            subPos++;
        }
        else {
            subPos = 0;
        }
        if (subPos == subLength) {
            count++;
            subPos = 0;
        } 
    }

    return count;
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    int count = 0;
    // for (int i = 0; i < strlen(line); i++) {
    //     if (c == line[i]) count++;
    // }

    char *occur = strchr(line, c);

    while (occur != NULL) {
        count++;
        occur = strchr(occur + 1, c);
    }

    return count;
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    // printf("%s\n", string);
    char upedString[strlen(string) + 1];
    
    int j = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (isalpha(string[i])) {  
            upedString[j++] = toupper(string[i]); 
        }
    }

    upedString[j] = '\0';  
    // printf("%s\n", upedString);

    char alphabet[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    int num[sizeof(alphabet)/sizeof(alphabet[0])]; 

    for (int i = 0; i < sizeof(alphabet) / sizeof(alphabet[0]); i++) {
        num[i] = countChar(upedString, alphabet[i]);
        if (num[i] == 0) continue;
        printf("%c | %c : %d\n", alphabet[i], tolower(alphabet[i]), num[i]);    
    }

}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
    int count = 0;

    char *tokenCountString = strtok(string, " \n");

    while (tokenCountString != NULL) {
        // printf("%s \n", tokenCountString);
        count++;
        tokenCountString = strtok(NULL, " \n");
    }

    return count;
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[], int size) {
    // printf("Number of strings: %d\n", size);
    // printf("Number of strings: %d\n", sizeof(string)+1); // + 1 b/c index starts at 0

    printf("Words beginning with B: \n");
    // int i = 0;
    // while (string[i] != NULL) {
    //     // printf("Length of string index [%d]: %lu\n", i, strlen(string[i]));
    //     int j = 0;
        
    //     if (string[i][j] == 'b' || string[i][j] == 'B') {
    //         while (string[i][j] != '\0') {
    //             printf("%2c", string[i][j]); // print char
    //             j++;
    //         }
    //     }

    //     puts("");
    //     i++;
    // }

    for (int i = 0; i < size; i++) {
        if (string[i][0] == 'b' || string[i][0] == 'B') {
            printf("    %s\n", string[i]); 
        }
    }

}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[], int size) {
    
    printf("Words ending with ed: \n");
    for (int i = 0; i < size; i++) {
        int j = strlen(string[i]);
        if (j < 2) continue;
        
        if (toupper(string[i][j-2]) == 'E' && toupper(string[i][j-1]) == 'D') {
            printf("    %s\n", string[i]);
        }

    }

}