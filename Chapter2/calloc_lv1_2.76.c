#include <assert.h>
#include <memory.h>
#include <stdlib.h>

void *calloc(size_t nmemb, size_t size)
{
    if(nmemb == 0 || size == 0)
    {
        return NULL;
    }

    size_t m = nmemb*size;
    void *ptr;

    if(m/size != nmemb)
    {
        return NULL;
    }

    ptr = malloc(m);
    ptr = memset(ptr, 0, m);

    return ptr;
}

/*
问题：如何判断加法溢出，如何判断乘法溢出。两者为何方法不同。
加法溢出：是否变号。
乘法溢出：如上程序中应用。

因为加法形成阿贝尔群，所以无法用减法判断加法是否溢出。
*/