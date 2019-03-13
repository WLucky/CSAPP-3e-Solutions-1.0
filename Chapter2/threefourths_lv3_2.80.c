#include <assert.h>
#include <limits.h>

int another_divide_power2(int x, int k)
{
    /* 大于0 则向上舍入。小于0 则向下舍入 */
    /* 如何解决偏移量正溢出问题 

        使用sign_mask还原正数的符号位，保留负数的符号位。
    */

    int w = sizeof(int) << 3;
    int mask = x >> (w - 1);
    int sign_mask = (mask << (w -1) >> k) | ((unsigned)(-1) >> k);

    int offset = (1<<k)-1;

    return ((x + (offset & ~mask)) >> k) & sign_mask;
}

int threefourths(int x)
{
    return (x - another_divide_power2(x, 2));
}

int another_threefourths(int x)
{
    __int64 val = x;
    val = val * 3 /4;

    return (int)val;
}

int main(int argc, char *argv[])
{
    assert(threefourths(7) == another_threefourths(7));
    assert(threefourths(-7) == another_threefourths(-7));
    assert(threefourths(INT_MAX) == another_threefourths(INT_MAX));

    return 0;
}