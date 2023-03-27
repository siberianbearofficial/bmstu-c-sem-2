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

char is_nes_element(int);

int main()
{
    char exit_code = EXIT_FAILURE;

    int n;
    if (!input_array_length(&n))
    {
        int arr[MAX_LENGTH];
        if (!input_array((int *) &arr, n))
        {
            int m;
            int filtered_arr[MAX_LENGTH];
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

char is_nes_element(int element)
{
    element = abs(element);
    if (element < 10)
    {
        return 1;
    }

    char last_digit = (char) (element % 10);
    while (element > 10)
        element /= 10;
    return (char) (last_digit == element);
}

char get_filtered_arr(int *filtered_arr, int *m, const int *arr, int n)
{
    char exit_code = EXIT_FAILURE;

    for (int i = 0; i < n; i++)
    {
        int element = arr[i];

        if (is_nes_element(element))
        {
            filtered_arr[*m] = element;
            (*m)++;
            exit_code = EXIT_SUCCESS;
        }
    }

    return exit_code;
}