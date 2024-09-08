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

    float itemPrice, discountPercent, discountAmount, initalCost, finalTotal;
    double itemQuantity;


    printf("Welcome to \"Temple\" store");

    printf("\n");

    printf("\n\tEnter item price: "); //get item price
    scanf("%f", &itemPrice); 
    if (itemPrice <= 0) { //check if price is negative
        printf("\n\tThis is not a valid item price. \n\tPlease run the program again\n");
        printf("\nThank you for using \"Temple\" store\n");
        exit(1);
    }

    double intPart, fracPart;

    printf("\tEnter quantity: "); //get the # of items
    scanf("%lf", &itemQuantity);
    fracPart = modf(itemQuantity, &intPart); 
    if (itemQuantity <= 0 || fracPart != 0) { //check if quantity is negative number or a fraction
        printf("\n\tThis is not a valid quantity order. \n\tPlease run the program again\n");
        printf("\nThank you for using \"Temple\" store\n");
        exit(1);
    }
    else if (itemQuantity <= 49)
    {
        discountPercent = 0;
        discountAmount = 0;
    }
    
    else if (itemQuantity <= 99) //apply discounts based on number of items 
    {
        discountPercent = 0.10;
        discountAmount = itemPrice * itemQuantity * discountPercent;
    }
    else if (itemQuantity <= 149)
    {
        discountPercent = 0.15;
        discountAmount = itemPrice * itemQuantity * discountPercent;
    }
    else if (itemQuantity >= 150)
    {
        discountPercent = 0.20;
        discountAmount = itemPrice * itemQuantity * discountPercent;
    }
    

    initalCost = itemPrice * itemQuantity; //find the cost before discount
    finalTotal = initalCost - discountAmount; //final cost after discounts


    printf("\n\tThe item price is: $%.2f", itemPrice);
    printf("\n\tThe order is: %.f item(s)", itemQuantity);
    printf("\n\tThe cost is: $%.2f", initalCost);
    printf("\n\tThe discount is: %2.f%%", discountPercent*100);
    printf("\n\tThe discount amount is: $%.2f", discountAmount);
    printf("\n\tThe total is: $%.2f", finalTotal);

    printf("\n");

    printf("\nThank you for using \"Temple\" store \n");
    exit(0);
}