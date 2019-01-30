#include <stdio.h>


int int_shifts_are_arithmetic()
{
    int x = ~0; /* 位级全1整型 */
    int y = x >> 1; /* 右移一位 如果值不变 则是算术右移 否则 逻辑右移*/

    return !(x^y);
}


int main()
{
    int val;

    val = int_shifts_are_arithmetic();

    printf("the result is %d\n", val);

    return 0;
}
