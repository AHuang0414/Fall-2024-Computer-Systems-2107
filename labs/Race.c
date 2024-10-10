/*
Name: Andrew Huang
Date: 10/7/2024
Course: CIS 2107 
Lab 07: Race

//The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
//generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
//controlled using the sleep() function. Sometimes it takes a while due to slippage.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>

#define RAND_MIN 1
#define RAND_MAX 10

int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int *hPos,int *tPos);
// int minPos(int hMin, int tMin);

int main(){
    srand((unsigned)time(NULL));

    int hPos = 1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1

    // for (int i = 0; i < 100; i++) { //just checking the rando works
    //     printf("%d  ",randomNumberGenerator());
    // }

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    while(hPos != 70 && tPos !=70){
        // sleep(1);						//slows down the race
        Sleep(10);
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(&hPos,&tPos);
        puts("\n");
    }

}

//Finds minimum of hare or tortoise position to decide which position to print first
// int minPos(int hMin, int tMin){ //Not too sure what I was suppose to use this for
// }

//Prints the position of the H and T
void printRace(int *hPos,int *tPos){
    if (*hPos < 1) *hPos = 1; //in case of over or under limits
    else if (*hPos >= 70) *hPos = 70;

    if (*tPos < 1) *tPos = 1;
    else if (*tPos >= 70) *tPos = 70;

    // printf("Hare Pos: %d\n", *hPos); //just making sure they moving
    // printf("Turtle Pos: %d\n", *tPos);

    for (int i = 1; i <= 70; i++) {
        if (i == *tPos && i == *hPos) {
            printf("OUCH!!!");
        }
        else if (i == *tPos) {
            printf("T");
        }
        else if (i == *hPos) {
            printf("H");
        }
        else {
            printf(" ");
        }
    }

    if (*tPos == 70 && *hPos == 70) printf("%s", "\n> Underdog turtle deserves the win!");
    else if (*tPos == 70) printf("%s", "\n> TORTOISE WINS!!! YAY!!");
    else if (*hPos == 70) printf("%s", "\n> Hare wins. Yuch.");

}

//Controls the tortoise movement
void tortMove(int *tPtr){
    // 1 - 5: fast pold (+3)
    // 6 - 7: slip (-6)
    // 8 - 10: slow plod (+1)

    int movement = randomNumberGenerator();
    switch (movement)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        // puts("Turtle: Fast plod");
        *tPtr += 3;
        break;
    case 6:
    case 7:
        // printf("Turtle: Slip");
        *tPtr -= 6;
        break;
    case 8:
    case 9:
    case 10:
        // puts("Turtle: Slow plod");
        // printf("Before: %d", *tPtr);
        *tPtr += 1;
        break;
    default:
        puts("Somehow it got to default?");
        break;
    }
}

//Controls the hare movement
void hareMove(int *hPtr){
    // 1 - 2: sleep (no movement)

    // 3 - 4: Big Hop (+9)
    // 5: Big slip (-12)

    // 6 - 8: Small hop (+1)
    // 9 - 10: Small slip (-2)

    int movement = randomNumberGenerator();
    switch (movement)
    {
    case 1:
    case 2:
        // puts("sleep");
        break;
    case 3:
    case 4:
        // puts("Big hop");
        *hPtr += 9;
        break;
    case 5:
        // puts("Big slip");
        *hPtr -= 12;
        break;
    case 6:
    case 7:
    case 8:
        // puts("Small hop");
        *hPtr += 1;
        break;
    case 9:
    case 10:
        // puts("Small slip");
        *hPtr -= 2;
        break;
    default:
        puts("Somehow it got to default?");
        break;
    }
}

//Generates random number from 1-10
int randomNumberGenerator(){
    return rand() % RAND_MAX + RAND_MIN;
}
