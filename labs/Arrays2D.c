/*
Andrew Huang

9/23/2024

CIS 2107

Lab 5 Processing 2D Arrays 

Write a C program with functions creating and using 2D arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


int maxNum(int **array, int row, int column);
int rowSum(int **array, int row, int column);
int columnSum(int **array, int row, int column);
bool isSquare(int row, int column);
void displaysOutput(int **array, int row, int column);


int main() {
    
    int rows, columns;
    
    puts("Lets create a 2D array!\n");

    do {
        printf("Enter the number of rows: ");
        scanf("%d", &rows);
        printf("Enter the number of columns: ");
        scanf("%d", &columns);
    } while (rows < 1 || columns < 1);

    int **numberArray2D = malloc(sizeof(int *) * rows);

    for (int i = 0; i < rows; i++) {
        numberArray2D[i] = malloc(sizeof(int) * columns);
    }

    puts("\nEnter the numbers for the 2D array: ");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int givenNum = 0;
            printf("Enter [%d][%d]: ", i, j);
            scanf("%d", &givenNum);
            // scanf("%d", &numberArray2D[i][j]);
            numberArray2D[i][j] = givenNum;
        }
    }

    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < columns; j++) {
    //         printf("%4d ", numberArray2D[i][j]);
    //     }
    //     puts("");
    // }

    puts("");
    printf("The 2D array is: \n");

    displaysOutput(numberArray2D, rows, columns);

    puts("");
    printf("The maximum number is: %d\n", maxNum(numberArray2D, rows, columns));

    puts("");
    for (int i = 0; i < rows; i++) {
        printf("The sum of row %d is: %d\n", i, rowSum(numberArray2D, i, columns));
    }

    puts("");
    for (int i = 0; i < columns; i++) {
        printf("The sum of column %d is: %d\n", i, columnSum(numberArray2D, rows, i));
    }

    puts("");
    bool square = isSquare(rows, columns);
    switch (square) {
        case true:
            printf("The array is square\n");
            break;
        case false:
            printf("The array is not square\n");
            break;
    }

    exit(0);
}


//takes a 2D array pointer pointer and the number of rows and columns, and prints content of array to screen
void displaysOutput(int **array, int row, int column) {
    for (size_t i = 0; i < row; i++) {
        printf("{");
        for (size_t j = 0; j < column; j++) {
            printf(" [ %d ] ", array[i][j]);
        }
        printf("}");
        puts("");
    }
}

//takes a 2D array pointer pointer and the number of rows and columns, and returns the highest int in the array
int maxNum(int **array, int row, int column) {
    int max = 0;

    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < column; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }

    return max;
}

//takes a 2D array pointer pointer and the number of rows and columns, and returns the sum of the given row
int rowSum(int **array, int selectRow, int column) {
    int sum = 0;
    for (size_t i = 0; i < column; i++) {
        sum += array[selectRow][i];
    }

    return sum;
}

//takes a 2D array pointer pointer and the number of rows and columns, and returns the sum of the given column
int columnSum(int **array, int row, int selectColumn) {
    int sum = 0;
    for (size_t i = 0; i < row; i++) {
        sum += array[i][selectColumn];
    }
    
    return sum;
}

//takes a 2D array pointer pointer and returns true if the array is square (# of rows == # of columns), false otherwise
bool isSquare(int rows, int columns) {
    // printf("sizeof(**array): %d\n", sizeof(**array));
    // printf("sizeof(*array): %d\n", sizeof(*array));
    // printf("sizeof(array): %d\n", sizeof(array));
    // printf("sizeof(array[0]): %d\n", sizeof(array[0]));
    // printf("sizeof(array[0][0]): %d\n", sizeof(array[0][0]));

    // size_t rows = sizeof(array) / sizeof(array[0]);
    // printf("rows: %d\n", rows);
    // size_t cols = sizeof(array[0]) / sizeof(array[0][0]);
    // printf("cols: %d\n", cols);

    if (rows == columns) {
        return true;
    } else {
        return false;
    }
}