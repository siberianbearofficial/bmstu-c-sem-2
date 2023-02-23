/**
 Приняв с клавиатуры по концевому признаку (до первого отрицательного числа) элементы непустой последовательности
 неотрицательных чисел x, вычислить и вывести на экран значение g(x).
*/

#include <stdio.h>
#include <math.h>

float input_seq_and_calc_res();

int main()
{
    short exit_code = 0;

    // Input & Calculations
    float res = input_seq_and_calc_res();

    if (res != -1.)
    {
        // Output
        printf("Result: %.6f", res);
    }
    else
    {
        exit_code = 1;
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

    short loop = 1;
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
                sum += sqrt(n + x);
            }
        }
        else
        {
            res = -1.;
            loop = 0;
        }
    }

    if (res != -1. && n == 0)
        res = 0;
    else if (res != -1.)
        res = 1. / n * sum;

    return res;
}