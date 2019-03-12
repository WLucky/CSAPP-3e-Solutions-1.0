#include <assert.h>

int signed_high_prod(int x, int y);


unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    unsigned high_prod;
    int w = sizeof(int) << 3;

    high_prod = signed_high_prod((int)x, (int)y) + (x >> (w-1))*y + (y >> (w-1))*x;

    return high_prod;
}