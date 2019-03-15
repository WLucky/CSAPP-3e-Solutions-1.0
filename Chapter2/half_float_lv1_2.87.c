
/*
-0:
    1 00000 00...000
    Hex = 0x8000
    M = 0
    E = -14

最小的>2的值
    0 10000 00000...01
    Hex = 0x4001
    M = 1.00....1 = 1 + 2 ^ (-10) = 1025/1024
    E = 1 ==> e = 16
    V = 2 + 2 ^(-9)
    D = 2.001953

512
    0 11000 0000..00
    Hex = 0x6000
    M = 1.000... = 1
    E = 9 => e = 24

最大的非规格化数：
    0 00000 1111...1
    Hex = 0x03FF
    M = 0.111..11 = 1 - 2 ^ (-10) = 1023/1024
    E = 1 - bias = - 14
    V = 1023 * (2 ^ (-24))
    D = 0.000061

-infinite
    0 11111 0000...00
    Hex = 0x7C00

the number whos hex = 3BB0
    0 01110 1110110000
    M = 1.1110110000 = 1 + 1 - 1/64 - 1/16 = 1 + 59/64 = 123/64
    E = 14 - 15 = -1
    V = 123 * (2 ^ (-7))
    D = 0.960938
*/
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
    double number1 = 2 + pow(2, -9);
    double number2 = 1023 * pow(2, -24);
    double number3 = 123 * pow(2, -7);

    printf("result:\n");
    printf("%f\n%f\n%f\n", number1, number2, number3);

    return 0;
}