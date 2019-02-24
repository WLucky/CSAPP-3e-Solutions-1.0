#include <assert.h>
#include <limits.h>

int tsub_ok(int x, int y)
{
    int w = sizeof(int) << 3;
    int sub = x - y;
    int sub_sign = (sub >> (w - 1)) & 0x1;
    int x_sign = (x >> (w - 1)) & 0x1;

    return !(sub_sign ^ x_sign);
}

int main(int argc, char *argv[])
{
    assert(tsub_ok(INT_MAX, -0x1) == 0);
    assert(tsub_ok(INT_MIN, 0x1) == 0);
    assert(tsub_ok(0x1234, 0x2) == 1);

    return 0;
}