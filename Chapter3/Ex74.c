#include <assert.h>
#include <stdio.h>

typedef enum {NEG, ZERO, POS, OTHER} range_t;

range_t find_range(float x)
{
    __asm__(
        "vxorps %xmm1, %xmm1, %xmm1\n\t"
        "vucomiss %xmm1, %xmm0\n\t"
        "movl $2, %edi\n\t"
        "cmova %edi, %eax\n\t"
        "movl $0, %edi\n\t"
        "cmovb %edi, %eax\n\t"
        "movl $1, %edi\n\t"
        "cmove %edi, %eax\n\t"
        "movl $3, %edi\n\t"
        "cmovp %edi, %eax\n\t"
    );
}

range_t find_range_C(float x)
{
    range_t result;
    if(x < 0)
    {
        result = NEG;
    }
    else if (x == 0)
    {
        result = ZERO;
    }else if (x > 0)
    {
        result = POS;
    }else
    {
        result = OTHER;
    }
    
    return result;
}

int main(int argc, char *argv[])
{
    long long count = 0;
    for(unsigned i = 0; i < (unsigned)(-1); i++)
    {
        count++;
        float f = *(float*)&i;
        if(find_range(f) != find_range_C(f))
		{
			printf("err float %f first %d second %d\n", f, find_range(f), find_range_C(f));
			break;
		}
    }

    printf("test count %lld sizeof long %d\n", count, sizeof(long long));
    return 0;
}
