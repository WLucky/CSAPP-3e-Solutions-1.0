#include <assert.h>

/*
A. no,  x=int_min,则-x=int_min;
B. yes, 移位操作等价
C. yes, ~x + 1 + ~y +1 = (-x) + (-y) = -(x+y) = ~(x+y) + 1 ==> 原等式       
D. yes, -(unsigned)(y-x) = -(y-x) = x-y;无符号数和补码加减法的位级操作等价  
E. yes, (x>>2)<<2 = x - bias; 0<= bias <= 3;
*/