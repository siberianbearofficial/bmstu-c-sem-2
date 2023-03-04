/**
 Приняв с клавиатуры по концевому признаку (до первого отрицательного числа) элементы непустой последовательности
 неотрицательных чисел x, вычислить и вывести на экран значение g(x).
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_ERROR (-1.0)

float input_seq_and_calc_res();

int main()
{
    char exit_code = EXIT_SUCCESS;

    // Input & Calculations
    float res = input_seq_and_calc_res();

    if (res != INPUT_ERROR)
    {
        // Output
        printf("Result: %.6f", res);
    }
    else
    {
        exit_code = EXIT_FAILURE;
    }

    return exit_code;
}

float input_seq_and_calc_res()
{
    int n = 0;
    short rc;
    float res = 0;
    float x;
    char loop = 1;

    printf("Input seq elements: ");

    while (loop)
    {
        rc = scanf("%f", &x);
        if (rc == 1)
        {
            if (x < 0)
            {
                loop = 0;
            }
            else
            {
                n++;
                res += sqrtf((float) n + x);
            }
        }
        else
        {
            res = INPUT_ERROR;
            loop = 0;
        }
    }

    if (n == 0)
        res = INPUT_ERROR;
    else if (res != -1.)
        res /= (float) n;

    return res;
}