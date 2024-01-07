#include "array.h"

int read_array(FILE *file, int **pb, int **pe)
{
    // Counting elements
    int buf;
    size_t count;
    for (count = 0; fscanf(file, "%d", &buf) > 0; (count)++);
    if (!feof(file))
        return INVALID_INPUT_ERROR;
    if (!count)
        return EMPTY_ARRAY_ERROR;
    rewind(file);

    // Allocating memory
    *pb = (int *) malloc(count * sizeof(int));
    if (!*pb)
        return MEMORY_ERROR;
    *pe = *pb + count;

    // Reading elements
    for (int *ip = *pb; ip < *pe; ip++)
        if (fscanf(file, "%d", ip) < 1)
            return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int write_array(FILE *file, const int *pb, const int *pe)
{
    int exit_code = EXIT_SUCCESS;
    for (const int *ip = pb; !exit_code && ip < pe; ip++)
        exit_code = fprintf(file, "%d ", *ip) <= 0;
    return exit_code ? INVALID_OUTPUT_ERROR : EXIT_SUCCESS;
}

int delete_array(int *array)
{
    if (array)
        free(array);
    return EXIT_SUCCESS;
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

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (!pb_src || !pe_src)
        return NULL_POINTERS_ERROR;

    if (pb_src == pe_src)
        return EMPTY_ARRAY_ERROR;

    if (pe_src < pb_src)
        return INVALID_POINTERS_ERROR;

    int count = key_count(pb_src, pe_src);
    if (!count)
        return EMPTY_DST_ARRAY_ERROR;

    *pb_dst = calloc((size_t) count, sizeof(int));
    *pe_dst = *pb_dst + count;

    int *ip_dst = *pb_dst;
    for (const int *ip = pb_src; ip < pe_src - 1; ip++)
        if (*ip > sum_array(ip + 1, pe_src))
            *(ip_dst++) = *ip;

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
