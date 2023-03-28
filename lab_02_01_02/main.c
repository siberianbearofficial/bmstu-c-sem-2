/*
 При решении каждой задачи реализуйте программу, которая принимает у
 пользователя целочисленный статический массив и выполняет его обработку в
 соответствии с вариантом. Максимальное количество элементов, которое может
 ввести пользователь, равно десяти.

 Найти и вывести на экран среднее арифметическое отрицательных элементов
 массива.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10
#define MIN_LENGTH 1

char input_array_length(int *);

char input_array(int *, int);

char get_average(float *, const int *, int);

char get_sum_and_count(int *, int *, const int *, int);

int main()
{
    char exit_code = EXIT_FAILURE;

    int n;
    if (!input_array_length(&n))
    {
        int arr[MAX_LENGTH];
        if (!input_array((int *) &arr, n))
        {
            float average;
            if (!get_average(&average, (const int *) &arr, n))
            {
                printf("Average: %f", average);
                exit_code = EXIT_SUCCESS;
            }
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

char get_average(float *average, const int *arr, int n)
{
    char exit_code = EXIT_SUCCESS;

    int sum;
    int count;
    if (!get_sum_and_count(&sum, &count, arr, n))
    {
        *average = (float) sum / (float) count;
    }
    else
    {
        exit_code = EXIT_FAILURE;
    }

    return exit_code;
}

char get_sum_and_count(int *sum, int *count, const int *arr, int n)
{
    *count = 0;
    *sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            *sum += arr[i];
            (*count)++;
        }
    }
    char exit_code = EXIT_FAILURE;
    if (*count > 0)
        exit_code = EXIT_SUCCESS;
    else
        printf("Error: no negative elements in array");
    return exit_code;
}