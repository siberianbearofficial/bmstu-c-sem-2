/*
 Сформировать и вывести на экран новый массив, в который скопировать элементы исходного массива,
 которые начинаются и заканчиваются на одну и ту же цифру.

 Число начинается и заканчивается на одну и ту же цифру
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10
#define MIN_LENGTH 1

char input_array_length(int *);

char input_array(int *, int);

char get_filtered_arr(int *, int *, const int *, int);

char print_arr(const int *, int);

int main()
{
    char exit_code = EXIT_FAILURE;

    int n;
    if (!input_array_length(&n))
    {
        int arr[n];
        if (!input_array((int *) &arr, n))
        {
            int m;
            int filtered_arr[n];
            if (!get_filtered_arr((int *) &filtered_arr, &m, (const int *) &arr, n))
            {
                print_arr((const int *) &filtered_arr, m);
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
    if (element > -10 && element < 10)
    {
        *is_element_nes = 1;
    }
    else
    {
        int first_digit = element;
        while (first_digit > 10 || first_digit < -10)
            first_digit /= 10;
        int last_digit = element % 10;

        *is_element_nes = abs(first_digit) == abs(last_digit);
    }

    return EXIT_SUCCESS;
}

char get_filtered_arr(int *filtered_arr, int *m, const int *arr, int n)
{
    char exit_code = EXIT_FAILURE;

    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        int is_element_nes;
        is_nes_element(element, &is_element_nes);

        if (is_element_nes) {
            filtered_arr[*m] = element;
            (*m)++;
            exit_code = EXIT_SUCCESS;
        }
    }

    return exit_code;
}