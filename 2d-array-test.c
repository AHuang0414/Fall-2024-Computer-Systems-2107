#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int maxNum(int row, int col, int array[row][col]);

int main() {
    int row, col;
    puts("Please enter the # of rows and cols: ");
    scanf("%d %d", &row, &col);

    int array2d[row][col];

    puts("Please fill the row and cols: ");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int givenNum = 0;
            printf("[%d][%d]: ", i, j);
            scanf("%d", &givenNum);
            array2d[i][j] = givenNum;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d ", array2d[i][j]);
        }
        puts("");
    }

}