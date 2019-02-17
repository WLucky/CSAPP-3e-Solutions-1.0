#include <assert.h>


/* 实现循环左移 */
unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(unsigned) << 3;
    unsigned x_right = x >> (w - n - 1) >> 1;
    unsigned x_left = x << n;

    return (x_left | x_right);
}

int main(int argc , char *argv[])
{
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);

    return 0;
}