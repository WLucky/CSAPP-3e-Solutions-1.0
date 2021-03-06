#include <assert.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if((exp == 0xFF)&&(frac != 0))
    {
        return f;
    }

    return ((1^sign) << 31) | (exp << 23) | frac;
}

int main(int argc, char *argv[])
{
    float x;
    float negate_x;
    for(unsigned i = 0; i < (unsigned)(-1); i++)
    {
        x = *(float *)&i;
        negate_x = -x;

        /* for a float f, f != f will be true only if f is NaN. */
        if(x == x)
        {
            assert(float_negate(i) == *(float_bits *)&negate_x);
        }
    }
    
    return 0;
}