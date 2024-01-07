#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "array.h"

#define EPS 0.00001

int filter_array(int *dst, int dst_len, int *src, int src_len)
{
    if (!src || !src_len)
        return 0;

    int *buffer = malloc(sizeof(int) * src_len);
    if (!buffer)
        return 0;

    int buffer_len = 0;
    for (int i = 0; i < src_len; i++)
        if (sqrt(src[i]) - (int) sqrt(src[i]) < EPS)
            buffer[buffer_len++] = src[i];

    if (dst && dst_len >= buffer_len)
        memmove(dst, buffer, sizeof(int) * buffer_len);

    free(buffer);

    return buffer_len;
}

void shift_array(int *arr, int arr_len, int k)
{
    if (!arr || !arr_len || !k)
        return;

    for (int i = 0; i < k % arr_len; i++)
    {
        int first = arr[0];
        memmove(arr, arr + 1, sizeof(int) * (arr_len - 1));
        arr[arr_len - 1] = first;
    }
}
