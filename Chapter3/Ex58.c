#include <assert.h>

long decode2(long x, long y, long z)
{
    long temp = y - z;
    return (temp << 63 >> 63) ^ (temp * x);
}
