#include <stdio.h>
#include <stdlib.h>  // for atof()

#define MAXLINE 100

int get_line(char line[], int max);  // renamed to avoid conflict

int main()
{
    double sum;
    char line[MAXLINE];

    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}

// Simple implementation of get_line
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
