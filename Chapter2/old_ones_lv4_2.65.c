#include <assert.h>



int odd_ones(unsigned x)
{
    /*assume w=32 */
    /* 难点：
    0.读题不清，理解成只有一个奇数位的1 
    1.逻辑右移
    2.对异或的使用：抵消偶数个1，最后剩下一个则为奇数*/

    x ^= x >> 16; 
    x ^= x >> 8; 
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    x &= 0x1;/* 画龙点睛之笔 不用考虑高位 只考虑最低位 */

    return x;
}


int main(int argc, char* argv[])
{
    unsigned x_odd = 0x010101;
    unsigned x_even = 0x010001;

    assert(odd_ones(x_odd));
    assert(!odd_ones(x_even));

    return 0;
}