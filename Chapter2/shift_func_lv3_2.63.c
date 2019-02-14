#include <stdio.h>
#include <math.h>
#include "tools.h"

/* 用算术右移完成逻辑右移 */
unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    /*
    0000 0111 -> 0000 0000 0111  => no change
    1000 0111 -> 1111 1000 0111  => 0000 1000 0111
    */

    int w = 8 * sizeof(int); /* int的总位数 */
    int m = pow(2, w-k);

    /* 最高位不是1 则不需要转换 */
    if(x < pow(2,w-1))
    {
        return xsra;
    }
    else
    {
        /* 利用溢出 归零多余的位 */
        return (xsra + m);
    }

}

/* 用逻辑右移来完成算术右移 */
int sra(int x, int k)
{
    int xsrl = (unsigned) x >> k;

    int w = 8 * sizeof(int); /* int的总位数 */
    int m = pow(2, w-k);

    if(x * xsrl >= 0)
    {
        return xsrl;
    }
    else
    {
        /* 加上少加的位 即-m*/
        return (xsrl - m);
    }
}

int main()
{
    int x;
    int k;
    unsigned val1;
    int val2;
    printf("Please input x, k\n");
    scanf("%d%d", &x, &k);
    val1 = srl((unsigned)x, k);
    val2 = sra(x, k);

    show_int(x);
    show_unsigned(val1);
    show_int(val2);

    return 0;
}

