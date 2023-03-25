/*
 Удалить из исходного массива все элементы, которые являются полными квадратами.
 Ситуацию, когда массив после операции не изменился, ошибочной не считать.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 10
#define MIN_LENGTH 1

char input_array_length(int *);

char input_array(int *, int);

char filter_arr(int *, int *);

char print_arr(const int *, int);

char is_nes_element(int, int *);

int main()
{
    char exit_code = EXIT_FAILURE;

    int n;
    if (!input_array_length(&n))
    {
        int arr[n];
        if (!input_array((int *) &arr, n))
        {
            if (!filter_arr((int *) &arr, &n))
            {
                print_arr((const int *) &arr, n);
                exit_code = EXIT_SUCCESS;
            }
        }
    }

    return exit_code;
}

char print_arr(const int *arr, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return EXIT_SUCCESS;
}

char input_array_length(int *n)
{
    char exit_code = EXIT_SUCCESS;
    printf("Input array length: ");

    // May be to check whether n is a float or an int
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
    for (int i = 0; i < n; i++)
    {
        // May be to check whether element is a float or an int
        if (scanf("%d", arr + i) != 1)
        {
            printf("Error with array element");
            exit_code = EXIT_FAILURE;
            break;
        }
    }
    return exit_code;
}

char is_nes_element(int element, int *is_element_nes)
{
    *is_element_nes = 0;
    for (int i = 0; i < (sqrt(element) + 1); i++)
    {
        if (pow(i, 2) == element)
        {
            *is_element_nes = 1;
            break;
        }
    }
    return EXIT_SUCCESS;
}

char filter_arr(int *arr, int *n)
{
    char exit_code = EXIT_FAILURE;

    int j = 0;
    for (int i = 0; i < *n; i++)
    {
        int element = arr[i];
        int is_element_nes;
        is_nes_element(element, &is_element_nes);

        if (!is_element_nes) {
            arr[j] = element;
            j++;
            exit_code = EXIT_SUCCESS;
        }
    }
    *n = j;

    return exit_code;
}