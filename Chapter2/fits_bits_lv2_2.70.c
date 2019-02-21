#include <assert.h>

int fits_bits(int x, int n)
{
    /*
    int upperBound = 1 << (n - 1) - 1;
    int lowerBound = -1 << (n - 1);
    不可行，因为编码规则不可用比较符号
    */

   int w = sizeof(w) << 3;
   int val = x >> n;

   return !((val ^ 0) && (val ^ -1));   
}


int main(int argc, char *argv[])
{
    assert(fits_bits(0x8765, 17) == 1);
    assert(fits_bits(0x8765, 16) == 1);
    assert(fits_bits(0x8765, 15) == 0);

    return 0;
}