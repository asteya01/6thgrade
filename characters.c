#include <stdio.h>

int main () 
{
    int nc = 0;
    char input;

    while ( (input = getchar()) != EOF)
    {
        nc = nc + 1;
        if((int)input != 10) 
        {
             printf("%d %d\n", (int)input, nc);
        }
        
    }
        
    return 0;
}
