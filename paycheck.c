/*
Andrew Huang

9/5/2024

2107

Lab 2 Paycheck

Write a C program called paycheck to calculate the paycheck for a Temple employee based on the hourlySalary, weeklyTime
(working for maximum 40 hours) and overtime (working for more than 40 hours).
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    double ID;
    float hourlySalary, weeklyHours, overtimeHours = 0;
    double intPart, fracPart;

    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n");
    
    
    printf("\n\tEnter Employee Number: "); // getting employee ID
    scanf("%lf", &ID);
    fracPart = modf(ID, &intPart);
    // printf("FracPart: %lf", fracPart);
    // printf("IntPart: %lf", intPart);
    if (ID <= 0 || fracPart != 0) {
        printf("\n\tThis is not a valid Employee Number. \n\tPlease run the program again\n");
        printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    } 
    

    printf("\tEnter Hourly Salary: "); // getting hourly salary
    scanf("%f", &hourlySalary);
    if (hourlySalary <= 0) {
        printf("\n\tThis is not a valid hourly salary amount. \n\tPlease run the program again\n");
        printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    } 
    

    printf("\tEnter Weekly Time: "); //getting weekly time (# of hours worked in a week)
    scanf("%f", &weeklyHours);
    if (weeklyHours <= 0) 
    {
        printf("\n\tThis is not a weekly time. \n\tPlease run the program again\n");
        printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    } 
    else if (weeklyHours > 40)
    {
        overtimeHours = weeklyHours - 40; 
    }
    

    float regularPay = hourlySalary * (weeklyHours - overtimeHours); //calc pay for 40<= hours by removing overtime hours

    float overtimePay = (hourlySalary * 1.5) * overtimeHours; //calc overtime pay for 40+ hours, minus the inital 40

    float netPay = regularPay + overtimePay; //calc net pay with regular pay and adding overtime if needed 


    printf("\t=================================================\n");

    printf("\tEmployee #: %.f\n", ID);
    printf("\tHourly Salary: $%.2f\n", hourlySalary);
    printf("\tWeekly Time: %.2f\n", weeklyHours);
    printf("\tRegular Pay: $%.2f\n", regularPay);
    printf("\tOvertime Pay: $%.2f\n", overtimePay);
    printf("\tNet Pay: $%.2f", netPay);
    
    printf("\n\t=================================================\n");

    printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");

    exit(0);
}


