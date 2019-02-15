#include <assert.h>


int any_odd_one(unsigned x)
{
    /* 如题 假设int有32位 */
    int mask = 0xAAAAAAAA;

    return !!(x & mask);
}

int main(int argc, char* argv[])
{
    unsigned test_odd = 0x2;
    unsigned test_no_odd = 0x1;

    assert(any_odd_one(test_odd) == 1);
    assert(any_odd_one(test_no_odd) == 0);

    return 0; 
}