/*
Andrew Huang

9/18/2024

CIS 2107

Lab 4 Processing 1D Arrays 

Write a C program with functions creating and using 1D arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define RAND_MIN 0
#define RAND_MAX 100
#define ARRAY_SIZE 40

// #define COLOR_BOLD  "\e[1m"
// #define COLOR_OFF   "\e[m"

void fillArray(int array[], int size);
int findWithRange(int array[], int size, int startIndex, int endIndex);
void reverseArray(int array[], int size);
void reverseSelectedRangeWithinArray(int array[], int startIndex, int endIndex);
int findSequence(int array[], int size, int num1, int num2);


int main() {
    int numberArray[ARRAY_SIZE];

    puts("------------------------------------------- Filling array with random ints");

    fillArray(numberArray, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 10 == 0) {
            puts("");
        }
        printf("%4d ", numberArray[i]);
    }

    // int startIndex = -1, endIndex = -1;
    // while (ARRAY_SIZE < startIndex  || startIndex < 0 || ARRAY_SIZE < endIndex || endIndex < 0) {
    //     printf("\nStarting index: ");
    //     scanf("%d", &startIndex);

    //     printf("\nEnding Index: ");
    //     scanf("%d", &endIndex);
    // }

    puts("\n\n------------------------------------------- Finding the highest int between 2 given indexes");

    int startIndex = 12, endIndex = 18; //select indexes to search from and to
    int highNum = findWithRange(numberArray, ARRAY_SIZE, startIndex, endIndex);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 10 == 0) {
            puts("");
        }
        if (i == startIndex) {
            printf("[%4d", numberArray[i]);
            continue;
        }
        else if (i == endIndex) {
            printf("%4d]", numberArray[i]);
            continue;
        }
        printf("%4d ", numberArray[i]);
    }

    printf("\n\nHigh number between index [%d] - [%d]: %d", startIndex, endIndex, highNum);

    puts("\n\n------------------------------------------- Reversing the array on all indexes");

    printf("%s", "\nOriginal: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 10 == 0) {
            puts("");
        }
        printf("%4d ", numberArray[i]);
    }
    
    reverseArray(numberArray, ARRAY_SIZE);
    printf("%s", "\n\nReversed: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 10 == 0) {
            puts("");
        }
        printf("%4d ", numberArray[i]);
    }

    reverseArray(numberArray, ARRAY_SIZE); //return it to orginal array for later use 

    puts("\n\n------------------------------------------- Reversing the array between 2 indexes");

    int startRangeIndex = 20, endRangeIndex = 30; //select indexes to reverse from and to

    printf("%s", "\nOriginal: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 10 == 0) {
            puts("");
        }
        if (i == startRangeIndex) {
            printf("[%4d", numberArray[i]);
            continue;
        }
        else if (i == endRangeIndex) {
            printf("%4d]", numberArray[i]);
            continue;
        }
        printf("%4d ", numberArray[i]);
    }
 
    reverseSelectedRangeWithinArray(numberArray, startRangeIndex, endRangeIndex);
    printf("%s%d%s%d%s", "\n\nReversed between indexes [", startRangeIndex, "] - [", endRangeIndex, "]: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 10 == 0) {
            puts("");
        }
        if (i == startRangeIndex) {
            printf("[%4d", numberArray[i]);
            continue;
        }
        else if (i == endRangeIndex) {
            printf("%4d]", numberArray[i]);
            continue;
        }
        printf("%4d ", numberArray[i]);
    }

    reverseSelectedRangeWithinArray(numberArray, startRangeIndex, endRangeIndex); //reverse it again to make it back into the orignal array

    puts("\n\n------------------------------------------- Finding a sequence of number(s)");    
    int seqNum1 = -1, seqNum2;

    printf("%s", "\nOriginal: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 10 == 0) {
            puts("");
        }
        printf("%4d ", numberArray[i]);
    }

    while (seqNum1 < 0 || seqNum1 > 100 || seqNum2 < 0 || seqNum2 > 100) {
        printf("\n\n%s", "Enter the two numbers: ");
        scanf("%d%d", &seqNum1, &seqNum2);
    }

    int foundIndex = findSequence(numberArray, ARRAY_SIZE, seqNum1, seqNum2);
    
    printf("%s", "\nOriginal: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 10 == 0) {
            puts("");
        }
        if (i == foundIndex) {
            printf("[%4d", numberArray[i]);
            ++i;
            printf("%4d]", numberArray[i]);
            continue;
        }
        printf("%4d ", numberArray[i]);
    }
    printf("\n\n%s%d%s%d%s%d%s", "The sequence of < ", seqNum1, " ", seqNum2, " > is found at index: [", foundIndex, "]");
    puts("\n");

    exit(0);
}


//takes a 1D array and fills it up with random ints 0 --> 100 inclusive, size of array is manually given
void fillArray(int array[], int size) {
    srand((unsigned)time(NULL));
    // int size = sizeof(array) / sizeof(array[0]);
    
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (RAND_MAX+1) + RAND_MIN;
    }

}


//takes a 1D array, given the size, starting index and ending index. returns the highest int between the indexes
int findWithRange(int array[], int size, int startIndex, int endIndex) {
    int max = 0;

    if (startIndex < 0 || startIndex > size) {
        startIndex = 0;
    }
    if (endIndex < 0 || endIndex > size) {
        endIndex = size-1;
    }

    for (int i = startIndex; i <= endIndex; i++) {
        if (array[i] > max) max = array[i];
    }

    return max;
}


//takes a 1D array, given the size, and reverses it on all indexes
void reverseArray(int array[], int size) {
    // int size = sizeof(array) / sizeof(array[0]);
    // int size = 40;

    for (int i = 0; i <= size/2; i++) {
        int currentElem = i;
        int lastElem = size-i-1;

        int tempFirst = array[currentElem];
        int tempLast = array[lastElem];
        
        array[currentElem] = tempLast;
        array[lastElem] = tempFirst;
    } 
}


//takes 1D array, a starting index, and ending index. reverses the array from start to end indexes
void reverseSelectedRangeWithinArray(int array[], int startIndex, int endIndex) {
    if (startIndex < 0 || startIndex > ARRAY_SIZE) startIndex = 0;
    if (endIndex < 0 || endIndex > ARRAY_SIZE) endIndex = ARRAY_SIZE-1;

    while (startIndex < endIndex) {
        int tempFirstInt = array[startIndex];

        array[startIndex] = array[endIndex];
        array[endIndex] = tempFirstInt;

        startIndex++;
        endIndex--;
    }
}


//takes a 1D array, given the size, and two int inputs. returns the index of the first number of the sequence if it is found, or -1 if not
int findSequence(int array[], int size, int num1, int num2) {
    int foundIndex = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] == num1 && array[i+1] == num2) {
            foundIndex = i;
            break;
        }
    }

    return foundIndex;
}