#include <assert.h>
#include <stdio.h>
#include "tools.h"

typedef unsigned float_bits;

float_bits float_twice(float_bits f)
{

}


int main(int argc, char *argv[])
{
    /* 0 100000.. 1100.... ==> 40 60 00 00*/
    unsigned x = 0x406000;
    float y = *(float *)&x;

    float twice_y = 2.0 * y;

    printf("y: %f\n2y: %f\n", y, twice_y);
    show_unsigned((unsigned *)&twice_y);

    return 0;
}
