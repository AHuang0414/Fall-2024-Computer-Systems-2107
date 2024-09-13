/*
Andrew Huang

9/10/2024

CIS 2107

Lab 3 ATM Machine

Write a C program for a ATM Machine by implementing functions (for the menu), such as requiring a PIN and different types of transactions.

1. Balence - show balence
2. Cash withdrawl - withdrawl money, subtract from balence, +1 to transaction, can only withdrawl in $20s (20, 40 60, etc.), limit $1,000
3. Cash deposit - deposit money, add to balence, +1 to transaction, can only add whole dollar bills (1, 5, 10, 20, etc.), limit $10,000
4. Quit - exit program
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


void showBalence(int *currentBalence) { 
    printf("\n> Current Balence: $%d\n", *currentBalence);
}

void showCashWithdrawl(int *currentBalence, int *transactions, int *dailyLimit) { 
    unsigned int withdrawlAmount;
    int wantReceipt;
    puts("--------------------------");
    printf("%s","How much would you like to withdrawl? Please enter in bills of $20s. i.e. 20, 40, 60, etc. : ");
    scanf("%d", &withdrawlAmount);

    int counter = 3;
    while (counter > 0) {
        if (withdrawlAmount > *dailyLimit || withdrawlAmount %20 != 0 || withdrawlAmount <= 0) {
            counter -= 1;
            printf("Invalid input, try again. [%d] tries left: ", counter);
            if (counter == 0) {
                puts("\nError Occured: Invalid money validation, too many attempts!");
                exit(0);
            }   
            scanf("%d", &withdrawlAmount);
        }
        else {
            break;
        }
    }

    if (*dailyLimit >= withdrawlAmount && (withdrawlAmount % 20) == 0) {
        *currentBalence -= withdrawlAmount;
        *dailyLimit -= withdrawlAmount;
        *transactions += 1;
        puts("> Withdrawl Successful");
        printf("\nWould you like a receipt? Press 1 for 'Yes' and 2 for 'No': ");
        scanf("%d", &wantReceipt);
        if (wantReceipt == 1) printf("> Receipt printing...\n");
    }
    
    printf("> Daily Withdrawl Left: $%d\n", *dailyLimit);
    puts("--------------------------");

    // printf("\n(after) withCashWithdrawl balence: %d", currentBalence);

}

void showCashDeposit(int *currentBalence, int *transactions, int *dailyLimit) {
    unsigned int depositAmount = 0;
    int wantReceipt = 0;
    puts("--------------------------");
    printf("%s","How much would you like to deposit? Please enter in whole doller bills $. i.e 1, 5, 10, 20. : ");
    scanf("%d", &depositAmount);

    int counter = 3;
    while (counter > 0) {
        if (depositAmount > *dailyLimit || depositAmount <= 0) {
            counter -= 1;
            printf("Invalid input, try again. [%d] tries left: ", counter);
            if (counter == 0) {
                puts("\nError Occured: Invalid money validation, too many attempts!");
                exit(0);
            }   
            scanf("%d", &depositAmount);
        }
        else {
            break;
        }
    }

    if (*dailyLimit >= depositAmount) {
        *currentBalence += depositAmount;
        *dailyLimit -= depositAmount;
        *transactions += 1;
        puts("> Deposit Successful");   
        printf("\nWould you like a receipt? Press 1 for 'Yes' and 2 for 'No': ");
        scanf("%d", &wantReceipt);
        if (wantReceipt == 1) printf("> Receipt printing...\n");
    }

    printf("> Daily Deposit Left: $%d\n", *dailyLimit);
    puts("--------------------------");
}

void finish(int *finalBalence, int *totalTransactions) {
    int wantReceipt;    
    printf("\nWould you like a receipt? Press 1 for 'Yes' and 2 for 'No': ");
    scanf("%d", &wantReceipt);
    if (wantReceipt == 1) {
        printf("> Receipt printing...\n");
        printf("\nYour final balence is: $%d", *finalBalence);
        printf("\nToday you made [%d] total transactions.\n", *totalTransactions);
    } 

    printf("%s","\nThank you for using \"Temple\" ATM Machine!");
    exit(0);
}


int main() {
    int PIN = 3014, inputPIN;
    int totalTransactions = 0;
    int balence = 5000, dailyWithdrawlLimit = 1000, dailyDepositLimit = 10000;

    printf("%s","Welcome to \"Temple\" ATM Machine!\n");
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

    puts("\nWelcome Nana! Please enter number 1 through 4 to select menu options: ");
    while (true) {

        if (menuOption == 0) {
            puts("\nATM Menu:");
            printf("%s","1. Balence");
            printf("%s","\n2. Cash withdrawl");
            printf("%s","\n3. Cash deposition");
            printf("%s","\n4. Quit");
            printf("%s","\nEnter here: ");
            scanf("%d", &menuOption);
        }

        switch (menuOption)
        {
        case 1:
            showBalence(&balence);
            break;
        case 2:
            showCashWithdrawl(&balence, &totalTransactions, &dailyWithdrawlLimit);
            break;
        case 3:
            showCashDeposit(&balence, &totalTransactions, &dailyDepositLimit);
            break;
        case 4:
            finish(&balence, &totalTransactions);
        default:
            puts("\n> Invalid menu option, please try again!");
            break;
        }
        menuOption = 0;
        
        // if (menuOption > 0 && menuOption <= 4) {
        //     if (menuOption == 1) {
        //         showBalence(&balence);
        //         menuOption = 0;
        //     }
        //     else if (menuOption == 2)
        //     {
        //         showCashWithdrawl(&balence);
        //         totalTransactions += 1;
        //         menuOption = 0;
        //     }
        //     else if (menuOption == 3)
        //     {
        //         balence = showCashDeposit(balence);
        //         totalTransactions += 1;
        //         menuOption = 0;
        //     }
        //     else if (menuOption == 4)
        //     {
        //         finish(balence, totalTransactions);
        //     }
        // }
        // else {
        //     printf("Invalid menu option, please try again: ");
        //     menuOption = 0;
        // }

    }


}