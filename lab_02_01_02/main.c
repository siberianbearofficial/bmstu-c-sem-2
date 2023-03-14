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

void input_array(int *, char);

float get_average(const int *, char);

int get_sum(const int *, char);

int main()
{
    char exit_code = EXIT_SUCCESS;
    int n;
    printf("Input array size: ");

    // May be to check whether n is a float or an int
    if (scanf("%d", &n) == 1)
    {
        if (n > 0 && n <= 10)
        {
            int arr[n];
            input_array((int *) &arr, (char) n);

            float average = get_average((const int *) &arr, (char) n);

            printf("Average: %f", average);
        }
        else
        {
            printf("Error: inappropriate array length\n");
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

void input_array(int *arr, char n)
{
    printf("Input array elements: ");
    for (char i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

float get_average(const int *arr, char n)
{
    int sum = get_sum(arr, n);
    float average = (float) sum / (float) n;
    return average;
}

int get_sum(const int *arr, char n)
{
    int sum = 0;
    for (char i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}