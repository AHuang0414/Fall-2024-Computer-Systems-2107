/* 
Name: Andrew Huang
Date: 9/30/2024
Course: CSI2107 
HW#: Lab 06: ““Arrays of Pointers to Functions” 

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
    unsigned int students, exams;

    printf("%s", "Enter the number of students: ");
    scanf("%u", &students);

    printf("%s", "Enter the number of exams: ");
    scanf("%u", &exams);

    int grades[students][exams];

    for (size_t i = 0; i < students; i++)
    {
        for (size_t j = 0; j < exams; j++)
        {
            printf("Enter grade for student [%d], exam [%d]: ", i + 1, j + 1);
            scanf("%d", &grades[i][j]);
        }
    }

    // for (size_t i = 0; i < students; i++) {
    //     for (size_t j = 0; j < exams; j++) {
    //         printf("%u ", grades[i][j]);
    //     }
    //     puts("");
    // }

    void (*processGrades[4])(int, int, int[students][exams]) = {printArray, minimum, maximum, average};

    int choice = 0;

    while (choice != 4) {
        puts("Enter number (0 - 3) for the following options and 4 to quit: ");
        puts("\t0. Print the array of grades (printArray)");
        puts("\t1. Find the minimum grade (minimum)");
        puts("\t2. Find the maximum grade (maximum)");
        puts("\t3. Print the average on all tests for each student (average)");
        puts("\t4. End Program");
        printf("Enter here: ");
        scanf("%u", &choice);

        puts("---------------------------------");
        if (choice == 4) exit(0);
        else if (choice < 0 || choice > 4) {
            puts("> Please enter a valild number");
            puts("---------------------------------");
            continue;
        }

        processGrades[choice](students, exams, grades);
        puts("---------------------------------");

        // switch (choice) {
        //     case 0:
        //     puts("--------------------------------- Students & Grades");
        //         processGrades[0](students, exams, grades);
        //     puts("---------------------------------");
        //         break;
        //     case 1:
        //         processGrades[1](students, exams, grades);
        //         break;
        //     case 2:
        //         processGrades[2](students, exams, grades);
        //         break;
        //     case 3:
        //         processGrades[3](students, exams, grades);
        //         break;
        //     case 4:
        //         puts("Im die, thank you forever");
        //         exit(0);
        //     default:
        //         puts("> Please enter a valid number (0 - 3)");
        //         break;
        // }
    }

    return 0;
}

void printArray(int students, int exams, int grades[students][exams]) {
    printf("%-15s", "Exams");
    for (size_t k = 0; k < exams; k++) {
        printf("%-5zu", k);
    }
    puts("");

    for (size_t i = 0; i < students; i++) {
        printf("Student %zu: ", i);
        for (size_t j = 0; j < exams; j++) {
            printf("%5d", grades[i][j]);
        }
        puts("");
    }
}

void minimum(int students, int exams, int grades[students][exams]) {
    unsigned int mini = 100;
    for (size_t i = 0; i < students; i++) {
        for (size_t j = 0; j < )
    }
}

void maximum(int students, int exams, int grades[students][exams]){
}

void average(int students, int exams, int grades[students][exams]){
}
