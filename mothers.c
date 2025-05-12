#include <stdio.h>
#include <unistd.h>   // For sleep()
#include <stdlib.h>

// ANSI color codes for styling
#define RED     "\033[1;31m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

void clearScreen() {
    printf("\033[2J\033[H");
}

// Print your balloon art
void printBalloons() {
    printf(RED);
    printf("       ,,,,,,,,,,,,,\n");
    printf("      .;;;;;;;;;;;;;;;;;;;,.\n");
    printf("    .;;;;;;;;;;;;;;;;;;;;;;;;,\n");
    printf("  .;;;;;;;;;;;;;;;;;;;;;;;;;;;;.\n");
    printf("  ;;;;;@;;;;;;;;;;;;;;;;;;;;;;;;' .............\n");
    printf("  ;;;;@@;;;;;;;;;;;;;;;;;;;;;;;;'................\n");
    printf("  ;;;;@@;;;;;;;;;;;;;;;;;;;;;;;;'...................\n");
    printf("  `;;;;@;;;;;;;;;;;;;;;@;;;;;;;'.....................\n");
    printf("   `;;;;;;;;;;;;;;;;;;;@@;;;;;'..................;....\n");
    printf("     `;;;;;;;;;;;;;;;;@@;;;;'....................;;...\n");
    printf("       `;;;;;;;;;;;;;@;;;;'...;.................;;....\n");
    printf("          `;;;;;;;;;;;;'   ...;;...............;.....\n");
    printf("             `;;;;;;'        ...;;..................\n");
    printf("                ;;              ..;...............\n");
    printf("                `                  ............\n");
    printf("               `                      ......\n");
    printf("              `                         ..\n");
    printf("             `                           '\n");
    printf("            `                           '\n");
    printf("           `                           '\n");
    printf("          `                           `\n");
    printf("          `                           `,\n");
    printf("          `\n");
    printf("           `.\n");
    printf(RESET);
}

int main() {
    clearScreen();

    printf(CYAN "\n\n\t💐💐 Happy Mother's Day 💐💐\n\n" RESET);
    sleep(2);

    printBalloons();
    sleep(1);

    printf(CYAN "\nThank you for everything, Mom! ❤️\n\n" RESET);

    return 0;
}
