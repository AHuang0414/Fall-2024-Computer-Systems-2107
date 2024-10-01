/* 
Name: Andrew Huang
Date: 9/30/2024
Course: CSI2107 
HW#: Lab 05: ““Arrays of Pointers to Functions” 

Objective: To design and implement array of function pointer. 

The purpose of this program is to modify existing code related to examslecting 
grades for individual students in a 2D matrix and determining the minimum, maximum, and each average. 

// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

int main()
{
    size_t students, exams;

    printf("%s", "Enter the number of students: ");
    scanf("%u", &students);

    printf("%s", "Enter the number of exams: ");
    scanf("%u", &exams);

    int grades[students][exams];

    for (size_t i = 0; i < students; i++)
    {
        for (size_t j = 0; j < exams; j++)
        {
            printf("Enter the grade for student %d, exam %d: ", i + 1, j + 1);
            scanf("%d", &grades[i][j]);
        }
    }

    void (*processGrades[4])(int, int, int[][exams]) = {printArray, minimum, maximum, average};

    unsigned int choice = 0;

    while (choice >= 0 && choice < 3)

    puts("Enter number (0 - 3) for the following options: ");
    puts("\t0. Print the array of grades (printArray)");
    puts("\t1. Find the minimum grade (minimum)");
    puts("\t2. Find the maximum grade (maximum)");
    puts("\t3. Print the average on all tests for each student (average)");
    puts("\t4. End Program");


    return 0;
}

void printArray(int students, int exams, int grades[students][exams]){
    for (size_t i = 0; i < students; i++) {
        for (size_t j = 0; j < exams; j++) {
            printf("Student %u, Exam %u grade: %u", i, j, grades[i][j]);
        }
    }
}

void minimum(int students, int exams, int grades[students][exams]){
}

void maximum(int students, int exams, int grades[students][exams]){
}

void average(int students, int exams, int grades[students][exams]){
}
