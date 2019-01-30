#include <stdio.h>
#include "tools.h"

int get_one(int x)
{
    int val;
    int mask0 = 0;
    int mask1 = ~mask0;
    int mask2 = 0xFF;

    int shift_val = (sizeof(int)-1)<<3;


    
    /*  A. x的任何位都等于1 
        x ^ mask1 = 0 */

    /*  B. x的任何位都等于0
        x ^ mask0 = 0 */

    /*  C. x的最低有效位都等于1
        (x & mask2) ^ mask2 = 0 */

    /*  D. x的最高有效位都等于0
        ((x>>shift_val) & mask2) ^ mask0 = 0 */
    val = (x>>shift_val);
    show_int(x);
    show_int(val);

    return !((x ^ mask1) && (x ^ mask0) && ((x & mask2) ^ mask2) && (((x>>shift_val) & mask2) ^ mask0));
}

int main()
{
    int x;
    int val;
    printf("please input a hex num:\n");
    scanf("%x", &x);

    val = get_one(x);

    printf("the result is %d\n", val);

    return 0;
}