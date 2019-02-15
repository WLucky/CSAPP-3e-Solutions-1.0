#include <stdio.h>
#include <assert.h>

/* 用算术右移完成逻辑右移 */
unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    /*
    0000 0111 -> 0000 0000 0111  => no change
    1000 0111 -> 1111 1000 0111  => 0000 1000 0111
    */

    int w = 8 * sizeof(int); /* int的总位数 */
    int mask = -1 << (w-k); /* k个1 + w-k个 0*/

    return xsra & ~mask;
}

/* 用逻辑右移来完成算术右移 */
int sra(int x, int k)
{
    int xsrl = (unsigned) x >> k;

    int w = 8 * sizeof(int); /* int的总位数 */
    int mask = -1 << (w-k);

    int m = 1 << (w - 1);

    /* 如果x最高位为 1  则mask&-1 保持不变 否则 mask&0 变为全0*/
    mask &= !(x & m) - 1;

    return xsrl | mask;
}

int main()
{
    unsigned test_unsigned = 0x12345678;
    int test_int = 0x12345678;

    assert(srl(test_unsigned, 3) == test_unsigned >> 3);
    assert(sra(test_int, 3) == test_int >> 3);

    return 0;
}

