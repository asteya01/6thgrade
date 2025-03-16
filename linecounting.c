#include <stdio.h> 

int main ()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF) //EOF is applied with Ctrl D
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);

    return 0;
}