#include <stdio.h>
#include <string.h>

int main() {
    char name[100];

    printf("Enter your name: \n");
    scanf("%s", name);

    // Getting length of string.
    int length = strlen(name);

    // Reversing the string.
    for (int i = 0; i < length / 2; i++) {
        char temp = name[i];
        name[i] = name[length - i - 1];
        name[length - i - 1] = temp;
    }
//SET UP For Success!!!
    printf("Reversed name: %s\n", name);

    return 0;
}
