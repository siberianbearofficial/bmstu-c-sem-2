/*
 Упорядочить массив по возрастанию с помощью сортировки вставками и вывести на экран.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10
#define OVERFLOW 100


char input_array(int *, int *);

char sort_arr(int *, int);

char print_arr(const int *, int);

int main()
{
    int n;
    int arr[MAX_LENGTH];
    char exit_code = input_array((int *) &arr, &n);
    if (!exit_code || exit_code == OVERFLOW)
    {
        sort_arr((int *) &arr, n);
        print_arr((const int *) &arr, n);
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

char input_array(int *arr, int *n)
{
    char exit_code = EXIT_FAILURE;
    char exit = EXIT_SUCCESS;
    printf("Input array elements: ");
    *n = 0;
    int element;
    while (exit_code == EXIT_FAILURE && !exit)
    {
        if (scanf("%d", &element) == 1)
        {
            if (*n == MAX_LENGTH)
            {
                exit_code = OVERFLOW;
            }
            else
            {
                arr[*n] = element;
                (*n)++;
            }
        }
        else if (*n > 0)
        {
            exit_code = EXIT_SUCCESS;
        }
        else
        {
            exit = EXIT_FAILURE;
        }
    }
    return exit_code;
}

char sort_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return EXIT_SUCCESS;
}