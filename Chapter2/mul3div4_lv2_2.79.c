#include <assert.h>
#include <limits.h>

int divide_power2(int x, int k)
{
    /*判断 x<0 ?*/
    int w = sizeof(int) << 3;
    int mask = x >> (w - 1);

    int offset = (1<<k)-1;

    return (x + (offset & mask)) >> k;
}

int mul3div4(int x)
{
    return divide_power2(((x << 2) - x), 2);
}

int another_mul3div4(int x)
{
    return 3*x/4;
}

int main(int argc, char *argv[])
{
    assert(mul3div4(7) == another_mul3div4(7));
    assert(mul3div4(-7) == another_mul3div4(-7));
    assert(mul3div4(INT_MAX) == another_mul3div4(INT_MAX));

    return 0;
}