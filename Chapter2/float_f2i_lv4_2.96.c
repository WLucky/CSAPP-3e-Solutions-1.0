#include <assert.h>
#include <stdio.h>
#include "tools.h"

typedef unsigned float_bits;
/*
int的范围：
-2^31, 2^31 - 1
*/
int float_f2i(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    int int_min = 1 << 31;
    int int_max = int_min - 1;
    int val;
    int bias = 127;
    int shift;
    int E;
    int add_f;

    /* 无穷或者NaN */
    if (exp == 0xFF)
    {
        return int_min;
    }

    if (exp < 127)
    {
        /* E < 0 include denormalized*/
        val = 0;
    }
    else if (exp < 158)
    {
        /* 0 <= E < 31 */
        E = exp - bias;
        shift = 23 - E;

        if (shift > 0)
        {
            /*  f现在为整数 恒为向0舍入 求和时考虑正负号 */
            add_f = frac >> shift;
        }
        else
        {
            add_f = frac << (-shift);
        }

        val = (1 << E) + add_f;
        if (sign == 1)
        {
            val = (~val) + 1;
        }
    }
    else if ((sign == 1) && (exp == 158) && (frac == 0))
    {
        /* 可以和最后一个选项合并 单独摘出仅因为这种情况是真的等于 int_min */
        /* E = 31 */
        val = int_min;
    }
    else
    {
        /* 超出范围 */
        val = int_min;
    }

    return val;
}

int main(int argc, char *argv[])
{
    float x;
    int f2i_x;
    int count = 0;

    for (unsigned i = 0; i < (unsigned)(-1); i++)
    {
        x = *(float *)&i;
        f2i_x = (int)x;

        if (float_f2i(i) != f2i_x)
        {
            printf("\nNo.%d\n", count++);

            int y = float_f2i(i);

            show_unsigned(i);
            show_unsigned(y);
            show_unsigned(f2i_x);

            if (count == 10)
            {
                return 0;
            }
        }

        /*assert(float_f2i(i) == *(float_bits *)&half_x);*/
    }

    return 0;
}