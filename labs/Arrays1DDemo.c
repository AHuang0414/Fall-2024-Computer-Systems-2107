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

void fillArray(int array[], int size);
void findWithRange();
void reverseArray();
void reverseSelectedRangeWithinArray();
void findSequence();


int main() {
    int numberArray[ARRAY_SIZE];

    fillArray(numberArray, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 10 == 0) {
            puts("");
        }
        printf("%4d ", numberArray[i]);
    }

    return 0;
}

//takes a 1D array and fills it up with random ints 0 --> 100 inclusive, size of array is manually given
void fillArray(int array[], int size) {
    srand((unsigned)time(NULL));
    // int size = sizeof(array) / sizeof(array[0]);
    
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (RAND_MAX+1) + RAND_MIN;
    }

}

