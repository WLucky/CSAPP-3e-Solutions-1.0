#include <assert.h>

/*
A. 这是无符号扩展，不符合符号扩展的要求
*/
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    int s = (sizeof(int) << 3) - 8;
    return ((int)(word >> (bytenum << 3) & 0xFF) << s >> s);
}

int main(int argc, char *argv[])
{
    assert(xbyte(0x8421, 0) == 0x21);
    assert(xbyte(0x8421, 1) == 0xFFFFFF84);

    return 0;
}