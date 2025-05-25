#include <stdio.h>
#include <stdlib.h>

int main() {
    double op1, op2, result;
    char operator;

    printf("Enter an expression (e.g., 3 + 4): ");

    // Read the input: operand operator operand
    while (scanf("%lf %c %lf", &op1, &operator, &op2) == 3) {
        switch (operator) {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                if (op2 != 0.0)
                    result = op1 / op2;
                else {
                    printf("Error: Division by zero\n");
                    continue;
                }
                break;
            default:
                printf("Error: Unsupported operator '%c'\n", operator);
                continue;
        }
        printf("Result: %.8g\n", result);
        printf("\nEnter another expression (e.g., 5 * 6): ");
    }

    printf("\nGoodbye!\n");
    return 0;
}
