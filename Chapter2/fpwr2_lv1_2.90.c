#include <assert.h>
#include <math.h>
#include <stdio.h>

/*
    k = 8
    n = 23

    min = 
    0 00000000 0000000...01

    bias = 2^7 -1 = 127

min:
    E = 2 - 2^7 = 2 - 128 = -126

    M = 2^(-23)

    V = 2^(-23) * 2 ^(-126) = 2 ^ (-149)

Denormalized Bigest:
    0 0000.. 1000000
    E = 1 - Bias = 2 - 2^7 = -126
    M = 0.1 = 2 ^ (-1)
    V = 2 ^ (-1) * 2 ^ (-126) = 2 ^ (-127)
   -m + -126 = x; m = -x - 126
   23 - m =  x + 149
Normalized Bigest:
    0 111..10 00000000
    E = bias = 127
    M = 1.0 = 1
    V = 2^127 

    E = e - bias = x;
    e = x + bias

*/

float u2f(unsigned u)
{
    return *(float *)&u;
}

float fpwr2(int x)
{
    unsigned exp, frac;
    unsigned u;

    if(x < -149)
    {
        exp = 0;
        frac = 0;
    }
    else if(x < -126)
    {
        exp = 0;
        frac = 1 << (x + 149);
    }
    else if(x < 128)
    {
        exp = x + 127;
        frac = 0;
    }
    else
    {
        exp = (1 << 8) - 1;
        frac = 0;
    }

    u = exp << 23 | frac;

    return u2f(u);   
}

int main(int argc, char *argv[])
{   
    assert(fpwr2(-150) == (float)pow(2, -150));
    assert(fpwr2(-130) == (float)pow(2, -130));
    assert(fpwr2(120) == (float)pow(2, 120));
    assert(fpwr2(130) == (float)pow(2, 130));

    return 0;
}