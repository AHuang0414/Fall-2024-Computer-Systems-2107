/*
 * Name:	Andrew Huang
 * Section:	03
 * Lab:  	CIS2107_Lab08_Manual 
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
void startsWithB(char *string[]);
void endsWithed(char *string[]);

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

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    //test for endsWithed
    endsWithed(series);

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
    char *strNum = "";
    for (int i = 0; i < strlen(num); i++) {
        if (!isdigit(*(num + i))) {
            continue;
        }
        strcat(strNum, *(num + i));
    }
    printf("%s", strNum);
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    

}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
  
  
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
  
  
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
 
 
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
   
   
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[]) {

 

}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[]) {


}