#include <assert.h>


int bit_mode1(int k)
{
    int w = sizeof(int) << 3;
    
    return ((1 << (w - 1)) >> (w - k- 1));
}

int bit_mode2(int k, int j)
{
    int w = sizeof(int) << 3;

    return ((unsigned)bit_mode1(w - k) >> (w - k - j));
}

int main(int argc, char *argv[])
{
    assert(bit_mode1(8) == 0xFFFFFF00);
    assert(bit_mode2(12, 8) == 0x000FFF00);

    return 0;
}