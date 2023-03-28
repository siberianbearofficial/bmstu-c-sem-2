/*
 Вычислить и вывести на экран значение по формуле
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10
#define MIN_LENGTH 1

char input_array_length(int *);

char input_array(int *, int);

char get_result(int *, int *, int *);

char max(int *, int);

int main()
{
    char exit_code = EXIT_FAILURE;

    int n;
    if (!input_array_length(&n))
    {
        int arr[MAX_LENGTH];
        if (!input_array((int *) &arr, n))
        {
            int result;
            get_result(&result, arr, arr + n - 1);
            printf("Result: %d", result);
            exit_code = EXIT_SUCCESS;
        }
    }

    return exit_code;
}

char input_array_length(int *n)
{
    char exit_code = EXIT_SUCCESS;
    printf("Input array length: ");

    if (scanf("%d", n) == 1)
    {
        if (*n < MIN_LENGTH || *n > MAX_LENGTH)
        {
            printf("Error with array length");
            exit_code = EXIT_FAILURE;
        }
    }
    else
    {
        printf("Error with length type");
        exit_code = EXIT_FAILURE;
    }

    return exit_code;
}

char input_array(int *arr, int n)
{
    char exit_code = EXIT_SUCCESS;
    printf("Input array elements: ");
    for (int i = 0; i < n && !exit_code; i++)
    {
        if (scanf("%d", arr + i) != 1)
        {
            printf("Error with array element");
            exit_code = EXIT_FAILURE;
        }
    }
    return exit_code;
}

char get_result(int *result, int *start, int *finish)
{
    *result = -1;
    while (start <= finish)
    {
        max(result, *start + *finish);
        start++;
        finish--;
    }
    return EXIT_SUCCESS;
}

char max(int *a, int b)
{
    if (*a < b)
        *a = b;
    return EXIT_SUCCESS;
}