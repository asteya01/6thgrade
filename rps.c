#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char userChoice[10];
    int userChoiceNum;
    
    printf("Rock, Paper, Scissors, Shoot!\n");
    printf("Enter your choice (rock, paper, or scissors): ");
    scanf("%s", userChoice);

    // Convert input to lowercase if needed
    // Convert user choice to a number
    if (strcmp(userChoice, "rock") == 0) {
        userChoiceNum = 1;
    } else if (strcmp(userChoice, "paper") == 0) {
        userChoiceNum = 2;
    } else if (strcmp(userChoice, "scissors") == 0) {
        userChoiceNum = 3;
    } else {
        printf("Invalid input. Please enter rock, paper, or scissors.\n");
        return 1;
    }

    srand(time(0));
    int computerChoice = (rand() % 3) + 1;

    // Print computer's choice
    if (computerChoice == 1) {
        printf("I choose rock!\n");
    } else if (computerChoice == 2) {
        printf("I choose paper!\n");
    } else {
        printf("I choose scissors!\n");
    }

    // Determine the winner
    if (userChoiceNum == computerChoice) {
        printf("It's a tie!\n");
    } else if ((userChoiceNum == 1 && computerChoice == 3) ||
               (userChoiceNum == 2 && computerChoice == 1) ||
               (userChoiceNum == 3 && computerChoice == 2)) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    return 0;
}
