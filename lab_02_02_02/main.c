/*
 Сформировать и вывести на экран новый массив, в который скопировать элементы исходного массива,
 которые начинаются и заканчиваются на одну и ту же цифру.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10
#define MIN_LENGTH 1

char input_array_length(int *);

char input_array(int *, int);

char get_filtered_arr(int *, char *, const int *, char);

char print_arr(const int *, char);

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
            char m;
            int filtered_arr[MAX_LENGTH];
            if (!get_filtered_arr((int *) &filtered_arr, &m, (const int *) &arr, (char) n))
            {
                print_arr((const int *) &filtered_arr, m);
                exit_code = EXIT_SUCCESS;
            }
        }
    }

    return exit_code;
}

char print_arr(const int *arr, char n)
{
    printf("Array: ");
    for (char i = 0; i < n; i++)
    {
        printf("%d ", arr[(int) i]);
    }
    return EXIT_SUCCESS;
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

char is_nes_element(int element)
{
    char last_digit = 1;
    element = abs(element);
    if (element >= 10)
    {
        last_digit = (char) (element % 10);
        while (element > 10)
            element /= 10;
        last_digit = (char) (last_digit == element);
    }
    return last_digit;
}

char get_filtered_arr(int *filtered_arr, char *m, const int *arr, char n)
{
    char exit_code = EXIT_FAILURE;
    *m = 0;
    for (char i = 0; i < n; i++)
    {
        if (is_nes_element(arr[(int) i]))
        {
            filtered_arr[(int) *m] = arr[(int) i];
            (*m)++;
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}