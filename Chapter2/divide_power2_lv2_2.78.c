#include <assert.h>

int divide_power2(int x, int k)
{
    /*判断 x<0 ?*/
    int w = sizeof(int) << 3;
    int mask = x >> (w - 1);

    int offset = (1<<k)-1;

    return (x + (offset & mask)) >> k;
}


int main(int argc, char *argv[])
{
    assert(divide_power2(10, 2) == (10/4));
    assert(divide_power2(-10, 2) == (-10/4));

    return 0;
}