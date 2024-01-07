#include "array.h"

int read_array(FILE *file, int *pb, int *count)
{
    // Counting elements
    int buf;
    int buf_count;
    for (buf_count = 0; fscanf(file, "%d", &buf) > 0; buf_count++);
    if (!feof(file))
        return INVALID_INPUT_ERROR;
    if (!buf_count)
        return EMPTY_ARRAY_ERROR;
    rewind(file);

    if (*count >= buf_count)
    {
        // Reading elements
        int *pe = pb + buf_count;
        for (int *ip = pb; ip < pe; ip++)
            fscanf(file, "%d", ip);
    }
    *count = buf_count;

    return EXIT_SUCCESS;
}

int write_array(FILE *file, const int *pb, const int *pe)
{
    int exit_code = EXIT_SUCCESS;
    for (const int *ip = pb; !exit_code && ip < pe; ip++)
        exit_code = fprintf(file, "%d ", *ip) <= 0;
    return exit_code ? INVALID_OUTPUT_ERROR : EXIT_SUCCESS;
}

int sum_array(const int *pb, const int *pe)
{
    int sum = 0;
    for (const int *ip = pb; ip < pe; ip++)
        sum += *ip;
    return sum;
}

int key_count(const int *pb, const int *pe)
{
    int count = 0;
    for (const int *ip = pb; ip < pe - 1; count += (*ip > sum_array(ip + 1, pe)), ip++);
    return count;
}

int key(const int *pb_src, const int *pe_src, int *pb_dst, int *count)
{
    if (!pb_src || !pe_src || !count)
        return NULL_POINTERS_ERROR;

    if (pb_src == pe_src)
        return EMPTY_ARRAY_ERROR;

    if (pe_src < pb_src)
        return INVALID_POINTERS_ERROR;

    int buf_count = key_count(pb_src, pe_src);
    if (!buf_count)
        return EMPTY_DST_ARRAY_ERROR;

    if (*count >= buf_count)
    {
        int *ip_dst = pb_dst;
        for (const int *ip = pb_src; ip < pe_src - 1; ip++)
            if (*ip > sum_array(ip + 1, pe_src))
                *(ip_dst++) = *ip;
    }
    *count = buf_count;

    return EXIT_SUCCESS;
}

int intcmp(const void *a, const void *b)
{
    if (*((const int *)a) > (*(const int *)b))
        return 1;
    if (*((const int *)a) < (*(const int *)b))
        return -1;
    return 0;
}

int swap(void *p1, void *p2, size_t size)
{
    char *cp1 = p1;
    char *cp2 = p2;
    char buf[size];
    memcpy(buf, cp2, size);
    memcpy(cp2, cp1, size);
    memcpy(cp1, buf, size);
    return EXIT_SUCCESS;
}

void mysort(void *base, size_t count, size_t size, int (*cmp)(const void*, const void*))
{
    char *pb = base;
    char *pe = pb + count * size;

    for (char *ip = pb + size; ip < pe; ip += size)
        for (char *jp = pb; jp < ip; jp += size)
            if (cmp(ip, jp) < 0)
                swap(ip, jp, size);
}
