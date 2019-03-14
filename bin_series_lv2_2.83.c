#include <assert.h>
#include <stdio.h>

/*
A.Y / (2^k - 1)

*/

typedef struct bin_series_elem
{
    unsigned Y;
    int k;
}bin_series_elem;


double bin_series(unsigned y, int k)
{
    return (double)y/((1 << k) - 1);
}

int main(int argc, char *argv[])
{
    bin_series_elem array_y[] = { {5, 3}, {6, 4}, {19, 6}};
    int ele_num = sizeof(array_y)/sizeof(bin_series_elem);

    for (int i = 0; i < ele_num; i++)
    {
        printf("%.2u:%.6lf\n", array_y[i].Y, bin_series(array_y[i].Y, array_y[i].k));
    }

    return 0;
}