#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include "tools.h"

typedef unsigned float_bits;

int get_E(unsigned abs_i)
{
    int n = 0;
    int n_start = 0;
    int n_end = 31;
    int mid;

    while(n_start < (n_end - 1))
    {
        mid = (n_start + n_end) >> 1;
        
        if(abs_i > (1 << mid))
        {
            n_start = mid;
        }
        else if(abs_i < (1 << mid))
        {
            n_end = mid;
        }
        else
        {
            return mid;
        }       
    }
    
    return n_start;
}

float_bits float_i2f(int i)
{
    unsigned sign;
    unsigned exp;
    unsigned frac;
    int int_min = 1 << 31;
    unsigned abs_i;
    int E;
    unsigned bais = 127;
    unsigned M;

    sign = i >> 31;

    if (i == 0)
    {
        exp = 0;
        frac = 0;
    }
    else if (i == int_min)
    {
        exp = 31 + bais;
        frac = 0;
    }
    else
    {
        abs_i = (sign == 0) ? i : (~i + 1);
        E = get_E(abs_i);
        exp = E + bais;
        M = abs_i - (1 << E);

        if((E - 23) <= 0)
        {
            frac = M << (23 - E);
        }
        else
        {
            int offset = E - 23;
            int round_part = M & ((1 << offset) - 1);
            int round_mid = 1<<(offset - 1);
            frac = M >> offset; 

            /* 向偶数对齐 如果是中间值 且frac末位为1 则+1 */
            if(round_part > round_mid)
            {
                frac += 1;
            }
            else if(round_part == round_mid)
            {
                if((frac & 0x1) == 1)
                {
                    frac += 1;                   
                }
            }

            /* 如果frac+1后溢出 则exp +1, frac = 0*/
            if((frac >> 23) == 1)
            {
                exp += 1;
                frac = 0;
            }
        }
    }

    return (sign << 31) | (exp << 23) | frac;
}

int main(int argc, char *argv[])
{
    float x;
    float i2f_x;
    int count = 0;

    for (int i = INT_MIN; i < INT_MAX; i++)
    {
        i2f_x = (float)i;

        assert(float_i2f(i) == *(float_bits *)&i2f_x);
    }

    return 0;
}