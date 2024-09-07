/*
Andrew Huang

9/5/2024

2107

Lab 2 Revenue

Write a C program called revenue to calculate the revenue from a sale based on the unit price and quantity of a product input by the user.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    float itemPrice;
    int itemQuantity;


    printf("Welcome to \"Temple\" store");

    printf("\n");

    printf("\n\tEnter item price: ");
    scanf("%lf", &itemPrice);

    printf("\tEnter quantity: ");
    scanf("%d", &itemQuantity);


    printf("\n\tThe item price is: $%.2f", itemPrice);
    printf("\n\tThe order is: ");
    printf("\n\tThe cost is: ");
    printf("\n\tThe discount is: ");
    printf("\n\tThe discount amount is: ");
    printf("\n\tThe total is: ");

    printf("\n");

    printf("\nThank you for using \"Temple\" store \n");
    exit(0);
}