#include <assert.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if((exp == 0xFF)&&(frac != 0))
    {
        return f;
    }

    /* sign default value = 0 */
    return (exp << 23) | frac;
}

int main(int argc, char *argv[])
{
    float x;
    float abs_x;
    for(unsigned i = 0; i < (unsigned)(-1); i++)
    {
        x = *(float *)&i;
        abs_x = (x < 0)? -x : x;
        /* abs_x == -0  --->  abs_x == +0*/
        abs_x = (abs_x == 0)? 0 : abs_x;

        /* for a float f, f != f will be true only if f is NaN. */
        if(x == x)
        {
            assert(float_absval(i) == *(float_bits *)&abs_x);
        }
    }
    
    return 0;
}