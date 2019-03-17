#include <assert.h>
#include <stdio.h>
#include "tools.h"

typedef unsigned float_bits;

/*
注意向偶数舍入(如果最低两位为全1，则加1)
frac & 0x3 == 0x3
    farc += 1;

exp == 0 非规格化：(E = 1 - bias = -126)
        frac >>= 1;
else exp < 0xFF  规格化：
        exp -= 1;
        if(exp == 0)
        {
            frac = (frac >> 1) | (1 << 22);
        }
else exp == 0xFF
        infinite和NaN的情况保持不变
        return f;

*/
float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    /* 
    右移一位向偶数舍入的情况：
    exp = 0或者1 且最低两位为11时，加1 
    */
    if (exp <= 1)
    {
        if ((frac & 0x3) == 0x3)
        {
            frac += 1;
        }
    }

    if (exp == 0)
    {
        frac >>= 1;
    }
    else if (exp == 1)
    {
        if ((frac >> 23) == 0)
        {
            /* frac未溢出 则转换为非规格化数 */
            exp -= 1;
            frac = (frac >> 1) | (1 << 22);
        }
        else
        {
            /* frac溢出 则保持规格化 同时frac归零 */
            exp = 1;
            frac = 0;
        }
    }
    else if (exp < 0xFF)
    {
        exp -= 1;
    }
    else
    {
        /* NaN或者oo 保持不变*/
        return f;
    }

    return (sign << 31) | (exp << 23) | frac;
}

int main(int argc, char *argv[])
{
    float x;
    float half_x;
    int count = 0;

    for (unsigned i = 0; i < (unsigned)(-1); i++)
    {
        x = *(float *)&i;
        half_x = 0.5 * x;

        /* for a float f, f != f will be true only if f is NaN. */
        if (x == x)
        {
            assert(float_half(i) == *(float_bits *)&half_x);
        }
    }

    return 0;
}
