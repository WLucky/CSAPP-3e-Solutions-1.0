#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 5

void good_echo()
{
    char s[BUFFER_SIZE];

    while ((fgets(s, 2, stdin) != NULL) && (s[strlen(s) - 1] != '\n'))
    {
        printf(s);
    }

    return;
}

int main()
{
    good_echo();

    return 0;
}