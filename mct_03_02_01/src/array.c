#include "array.h"

int malloc_array(size_t n, array_t *array)
{
    *array = malloc(n * sizeof(array_element_t));
    if (!*array)
        return MEMORY_ERROR;
    return EXIT_SUCCESS;
}

int input_array(size_t *n, array_t *array)
{
    int exit_code = scanf("%zu", n) != 1;
    if (exit_code)
        return exit_code;

    exit_code = malloc_array(*n, array);

    for (size_t i = 0; !exit_code && i < *n; i++)
        exit_code = scanf("%lld", &((*array)[i])) != 1;

    return exit_code;
}

int print_array(size_t n, array_t array)
{
    for (size_t i = 0; i < n; i++)
        printf("%lld ", array[i]);
    return EXIT_SUCCESS;
}

int filter_array(size_t *n, array_t array)
{
    size_t j = 0;
    for (size_t i = 0; i < *n; i++)
        if (array[i] % 3)
            array[j++] = array[i];
    *n = j;
    return EXIT_SUCCESS;
}
