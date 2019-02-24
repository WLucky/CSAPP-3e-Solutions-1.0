#include <assert.h>
#include <limits.h>

/*
参考 https://dreamanddead.gitbooks.io/csapp-3e-solutions/chapter2/2.73.html
*/

int saturating_add(int x, int y)
{
    unsigned w = sizeof(int) << 3;
    int Tmin = 1 << (w - 1); /* 10000 ....*/
    int Tmax = Tmin - 1;     /* 0111111... */
    int val = x + y;

    /* 判断溢出 */
    int signVal = (val >> (w - 1)) & 0x1;
    int signX = (x >> (w - 1)) & 0x1;

    int pos_over = (signVal ^ signX) && signVal;
    int neg_over = (signVal ^ signX) && !signVal;

    (pos_over && (val = Tmax) || (neg_over && (val = Tmin)));

    return val;
}

int main(int argc, char *argv[])
{
    assert(saturating_add(INT_MIN, -0x123) == INT_MIN);
    assert(saturating_add(INT_MAX, 0x1234) == INT_MAX);
    assert(saturating_add(0x1234, 0x1) == 0x1235);

    return 0;
}