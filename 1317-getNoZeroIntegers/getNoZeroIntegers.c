#include <stdbool.h>
#include <stdlib.h>

bool have_zero(int i)
{
    if (i == 0)
        return true;

    while (i)
    {
        if (i % 10 == 0)
            return true;

        i /= 10;
    }

    return false;
}

int *getNoZeroIntegers(int n, int *returnSize)
{
    *returnSize = 2;
    int *r = (int *)malloc(sizeof(int) * 2);
    for (int i = 1;; ++i)
    {
        r[0] = i;
        r[1] = n - i;
        if (!have_zero(r[0]) && !have_zero(r[1]))
            return r;
    }
}