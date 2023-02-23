/**
 Приняв с клавиатуры x и eps, 0 < eps <= 1, вывести на экран вычисленное с точностью eps приближённое
 значение s(x) и точное значение f(x) функции f, абсолютную и относительную погрешности
*/

#include <stdio.h>
#include <math.h>

double f(double);
double s(double, double);
double get_abs_error(double, double);
double get_rel_error(double, double);

int main()
{
    short exit_code = 0;

    // Input
    double x, eps;
    printf("Input x & eps: ");
    short rc = scanf("%lf%lf", &x, &eps);

    if (rc == 2 && eps > 0 && eps <= 1 && fabs(x) < 1)
    {
        // Calculations
        double sx = s(x, eps);
        double fx = f(x);
        double abs_error = get_abs_error(fx, sx);
        double rel_error = get_rel_error(abs_error, fx);

        if (rel_error != -1.)
        {
            // Output
            printf("S(x): %.6f F(x): %.6f Absolute error: %.6f Relative error: %.6f", sx, fx, abs_error, rel_error);
        }
        else
        {
            exit_code = 1;
        }
    }
    else
    {
        exit_code = 1;
    }

    return exit_code;
}

double f(double x)
{
    double fx = 1 / pow(1 + x, 3);
    return fx;
}

double s(double x, double eps)
{
    double sx = 1;
    int num = 2;
    while (1)
    {
        double current = num * (num + 1) * pow(-x, num - 1) / 2;
        if (fabs(current) < eps)
            break;
        num++;
        sx += current;
    }
    return sx;
}

double get_abs_error(double val1, double val2)
{
    double abs_error = fabs(val1 - val2);
    return abs_error;
}

double get_rel_error(double abs_error, double val1)
{
    double rel_error;
    double fabs_val1 = fabs(val1);

    if (fabs_val1 != 0)
        rel_error = abs_error / fabs_val1;
    else
        rel_error = -1.;

    return rel_error;
}