#include <stdio.h>
#include "tools.h"


unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    if (i >= sizeof(x) || i< 0)
    {
        return x;
    }

    unsigned mask = ~(0xFF << (i*8));
    unsigned val = (unsigned)b << (i*8);

    return (x & mask)|val;
}


int main()
{
    unsigned x;
    int i;
    unsigned char b;
    unsigned y;
    printf("Please input x, i ,b\n");
    scanf("%x%d%hhx", &x, &i, &b);
    y = replace_byte(x, i, b);

    show_unsigned(x);
    show_unsigned(y);

    return 0;
}
