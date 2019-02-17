#include <assert.h>


int leftmost_one(unsigned x)
{
    /* 扩散: 把最高位的1当做母体，往后扩散，直到最低位  其他位是0是1并不影响*/
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    /* 提纯：后面位进行归0处理 */
    return (x >> 1) + (x && 1);
}

int main(int argc, char *argv[])
{
    unsigned val1 = 0xFF00;
    unsigned val2 = 0x6600;

    assert(leftmost_one(val1) == 0x8000);
    assert(leftmost_one(val2) == 0x4000);

    return 0;
}