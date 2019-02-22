#include <assert.h>
#include <string.h>

/*
A: size_t 是unsigned的类型，maxbytes会转换为无符号数进行减法，结果也是无符号数，恒为非负数
*/

void copy_int(int val, void *buf, int maxbytes)
{
    if(maxbytes - (int)sizeof(val) >= 0)
        memcpy(buf, (void *)&val, sizeof(val));
}

