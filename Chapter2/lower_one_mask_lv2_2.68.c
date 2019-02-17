#include<assert.h>


int lower_one_mask(int n)
{
    int x = 1 << n - 1 << 1;

    return (x - 1);
}

int main(int argc, char *argv[])
{
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);

    return 0;
}