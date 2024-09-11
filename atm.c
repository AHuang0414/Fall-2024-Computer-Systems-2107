/*
Andrew Huang

9/10/2024

CIS 2107

Lab 3 ATM Machine

Write a C program for a ATM Machine by implementing functions (for the menu), such as requiring a PIN and different types of transactions.

1. Balence - show balence
2. Cash withdrawl - withdrawl money, subtract from balence, +1 to transaction, can only withdrawl in $20s (20, 40 60, etc.)
3. Cash deposit - deposit money, add to balence, +1 to transaction, can only add whole dollar bills (1, 5, 10, 20, etc.)
4. Quit - exit program
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


void showBalence(int currentBalence) {
    printf("\nCurrent balence: $%d\n", currentBalence);
}

int showCashWithdrawl(int currentBalence) {
    int withdrawlAmount;
    int wantReceipt;
    printf("How much would you like to withdrawl? Please enter in bills of $20s. i.e. 20, 40, 60, etc. : ");
    scanf("%d", &withdrawlAmount);

    // printf("\n(before) withCashWithdrawl balence: %d", currentBalence);

    currentBalence = currentBalence - withdrawlAmount;

    // printf("\n(after) withCashWithdrawl balence: %d", currentBalence);


    printf("\nWould you like a receipt? Press 1 for 'Yes' and 2 for 'No': ");
    scanf("%d", &wantReceipt);

    if (wantReceipt == 1) printf("Receipt printing...\n");
    
    return currentBalence;
}

int showCashDeposit(int currentBalence) {
    int depositAmount = 0;
    printf("How much would you like to deposit? Please enter in whole doller bills $. i.e 1, 5, 10, 20. No coins.");

    return 0;
}

int finish(int finalBalence, int totalTransactions) {
    printf("\nToday you made [%d] total transactions.", totalTransactions);
    printf("\nThank you for using \"Temple\" ATM Machine!");
    exit(0);
}


int main() {
    int PIN = 3014, inputPIN;
    int totalTransactions = 0;
    int balence = 5000;

    printf("Welcome to \"Temple\" ATM Machine!\n");
    printf("\n\tPlease enter your PIN number: ");

    for (int attempts = 3; attempts > 0; attempts--) {
        scanf("%d", &inputPIN);
        // printf("You entered: %d", inputPIN);
        if (inputPIN == PIN) {
            break;
        }
        if (inputPIN <= 0) printf("Invalid inputs, try again.");
        printf("\n\tWrong PIN, %d tries left: ", attempts-1);
        if (attempts - 1 == 0) {
            printf("\nError occured: incorrect PIN!");
            exit(0);
        }
    }

    int menuOption = 0;

    printf("\nWelcome Nana! Please enter number 1 through 4 to select menu options: ");
    while (true) {

        if (menuOption == 0) {
            printf("\n\t 1. Balence");
            printf("\n\t 2. Cash withdrawl");
            printf("\n\t 3. Cash deposition");
            printf("\n\t 4. Quit");
            printf("\nEnter here: ");
            scanf("%d", &menuOption);
        }
        
        if (menuOption > 0 && menuOption <= 4) {
            if (menuOption == 1) {
                showBalence(balence);
                menuOption = 0;
            }
            else if (menuOption == 2)
            {
                balence = showCashWithdrawl(balence);
                totalTransactions += 1;
                menuOption = 0;
            }
            else if (menuOption == 3)
            {
                balence = showCashDeposit(balence);
                totalTransactions += 1;
                menuOption = 0;
            }
            else if (menuOption == 4)
            {
                finish(balence, totalTransactions);
            }
        }
        else {
            printf("Invalid menu option, please try again: ");
            menuOption = 0;
        }

    }


}