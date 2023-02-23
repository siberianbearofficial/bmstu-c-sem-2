/**
 Приняв с клавиатуры по концевому признаку (до первого отрицательного числа) элементы непустой последовательности
 неотрицательных чисел x, вычислить и вывести на экран значение g(x).
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float input_seq_and_calc_res();

int main()
{
    bool exit_code = false;

    // Input & Calculations
    float res = input_seq_and_calc_res();

    if (res != -1.)
    {
        // Output
        printf("Result: %.6f", res);
    }
    else
    {
        exit_code = true;
    }

    return exit_code;
}

float input_seq_and_calc_res()
{
    int n = 0;

    short rc;
    float res;

    float sum = 0;
    float x;

    printf("Input seq elements: ");

    bool loop = true;
    while (loop)
    {
        rc = scanf("%f", &x);
        if (rc == 1)
        {
            if (x < 0)
            {
                loop = false;
            }
            else
            {
                n++;
                sum += sqrt(n + x);
            }
        }
        else
        {
            res = -1.;
            loop = false;
        }
    }

    if (n == 0)
        res = -1.;
    else if (res != -1.)
        res = 1. / n * sum;

    return res;
}