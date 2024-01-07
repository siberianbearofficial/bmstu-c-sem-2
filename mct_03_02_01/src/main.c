#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int main(void)
{
    size_t n;
    array_t array;
    int exit_code = input_array(&n, &array);
    if (exit_code)
        return exit_code;

    filter_array(&n, array);

    print_array(n, array);

    free(array);

    return EXIT_SUCCESS;
}
