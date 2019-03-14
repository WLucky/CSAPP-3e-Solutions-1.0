#include <assert.h>

unsigned f2u(float x)
{
    return *(unsigned*)&x;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (ux << 1 == 0 && uy << 1 == 0) /* both zero */
        ||(ux == uy)                      /* x is equal to y*/  
        ||((sx || sy) ^ (ux < uy));       /* other case: if exit negative， reverse the compare result */  
}

int main(int argc, char* argv[])
{
    assert(float_le(-0,0));
    assert(float_le(0,-0));
    assert(float_le(1,4));
    assert(float_le(4,4));
    assert(float_le(-4,-1));
    assert(float_le(-4,1));

    return 0;
}