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