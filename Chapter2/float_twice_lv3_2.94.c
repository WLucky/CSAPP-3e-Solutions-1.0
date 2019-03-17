#include <assert.h>

typedef unsigned float_bits;

/*
exp == 0 非规格化：(E = 1 - bias = -126)
    (frac >> 22) == 0:
        frac << 1;
    esle:
        -->向规格化过度
        exp += 1; (E = 1 - bais = -126)
        frac = (frac << 1) & 0x7FFFFF;(相当于右移一位，形成1.a)
else exp < 0xFF  规格化：
        exp += 1;
        如果溢出 则修改为 infinite格式
        if(exp == 0xFF)
        {
            frac = 0;
        }
else exp == 0xFF
        infinite和NaN的情况保持不变
        return f;

*/
float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if(exp == 0)
    {
        if(frac >> 22 == 1)
        {
            exp += 1;
        }

        frac = (frac << 1) & 0x7FFFFF;
    }
    else if(exp < 0xFF)
    {
        exp += 1;
        if(exp == 0xFF)
        {
            frac = 0;
        }
    }
    else
    {
        return f;
    }

    return (sign << 31) | (exp << 23) | frac;
}


int main(int argc, char *argv[])
{
    float x;
    float twice_x;

    for(unsigned i = 0; i < (unsigned)(-1); i++)
    {
        x = *(float *)&i;
        twice_x = 2.0 * x;

        /* for a float f, f != f will be true only if f is NaN. */
        if(x == x)
        {
            assert(float_twice(i) == *(float_bits *)&twice_x);
        }
    }



    return 0;
}
