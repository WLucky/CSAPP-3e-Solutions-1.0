#include <stdio.h>

void bubble_a(long *data, long count)
{
    long i, last;
    for (last = count - 1; last > 0; last--)
    {
        for (i = 0; i < last; i++)
        {
            if (data[i + 1] > data[i])
            {
                long t = data[i + 1];
                data[i + 1] = data[i];
                data[i] = t;
            }
        }
    }
}

void bubble_b(long *data, long count)
{
    long *i, *end;
    for (end = data + (count - 1); end > data; end--)
    {
        for (i = data; i < end; i++)
        {
            if (*(i + 1) < *i)
            {
                long t = *(i + 1);
                *(i + 1) = *i;
                *i = t;
            }
        }
    }
}

int main()
{
    long data[7] = {1, 3, 2, 4, 7, 6, 5};
    bubble_b(data, 7);

    for(int i = 0; i < 7; i++)
    {
        printf("%ld ", data[i]);
    }
    printf("\n");

    return 0;
}