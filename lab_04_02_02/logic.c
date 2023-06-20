#include "logic.h"

int prepare_arrays(int *contains, char *str1, char *str2, string_array arr1, int *n1, string_array arr2, int *n2)
{
    char exit_code = EXIT_FAILURE;
    if (!split_string(str1, arr1, n1) && !split_string(str2, arr2, n2))
    {
        remove_duplicates(arr1, n1);
        for (int i = 0; i < *n1; i++)
            contains[i] = string_array_contains(arr1[i], arr2, *n2);
        exit_code = EXIT_SUCCESS;
    }
    return exit_code;
}
