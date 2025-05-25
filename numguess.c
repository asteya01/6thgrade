#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber;
    int guess;

    // Set up random number generator
    srand(time(0));

    // Pick a random number between 1 and 100
    secretNumber = (rand() % 100) + 1;

    // Ask the user to guess until they get it right
    printf("Guess the number between 1 and 100:\n");

    while (1) {
        printf("Your guess: ");
        scanf("%d", &guess);

        if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        }
        else if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        }
        else {
            printf("🎉 You got it! The number was %d.\n", secretNumber);
            break;  // exit the loop
        }
    }

    return 0;
}
