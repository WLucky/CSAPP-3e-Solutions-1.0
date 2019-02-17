#include <assert.h>

/*
A.左移不能超过最大位数？ 引发不可知行为？ yes

*/

int int_size_is_32()
{
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int int_size_is_32_v2()
{
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int main(int argc, char *argv[])
{
    assert(int_size_is_32());
    assert(int_size_is_32_v2());

    return 0;
}