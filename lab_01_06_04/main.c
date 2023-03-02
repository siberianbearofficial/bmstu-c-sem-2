/**
 С клавиатуры задаются координаты точек xq, yq, xr, yr отрезка qr
 и координаты произвольной точки xp, yp. Определить, не принадлежит
 или принадлежит точка отрезку, и вывести на экран 0 или 1 соответственно.
*/

#include <stdio.h>
#include <math.h>

char point_belongs_segment(double, double, double, double, double, double);
double max(double, double);
double min(double, double);
char doubles_are_equal(double, double);
char point_belongs_math_segment(double, double, double);

int main()
{
    char exit_code = 0;

    // Input
    double xq, yq, xr, yr, xp, yp;
    printf("Enter coordinates: ");
    short rc = scanf("%lf%lf%lf%lf%lf%lf", &xq, &yq, &xr, &yr, &xp, &yp);

    if (rc == 6)
    {
        // Calculations
        char belongs = point_belongs_segment(xq, yq, xr, yr, xp, yp);

        if (belongs != -1)
        {
            // Output
            printf("Point belongs to segment: %d", belongs);
        }
        else
            exit_code = 1;
    }
    else
    {
        exit_code = 1;
    }

    return exit_code;
}

double max(double a, double b)
{
    double max_a_b = a;
    if (b > a)
        max_a_b = b;
    return max_a_b;
}

double min(double a, double b)
{
    double min_a_b = a;
    if (b < a)
        min_a_b = b;
    return min_a_b;
}

char doubles_are_equal(double a, double b)
{
    double eps = 0.000001;
    return (char) (fabs(a - b) < eps);
}

char point_belongs_math_segment(double a, double b, double x)
{
    char between_points = (char) (min(a, b) < x && x < max(a, b));
    char on_point = (char) (doubles_are_equal(min(a, b) - x, 0) || doubles_are_equal(x - max(a, b), 0));
    return (char) (between_points || on_point);
}

char point_belongs_segment(double xq, double yq, double xr, double yr, double xp, double yp)
{
    char belongs = 0;

    char is_rq_vertical_line = doubles_are_equal(xr, xq);
    char is_pq_vertical_line = doubles_are_equal(xp, xq);

    char appropriate_line;
    char appropriate_x_value;
    char appropriate_y_value;

    if (is_rq_vertical_line)
    {
        if (doubles_are_equal(yr, yq))
        {
            if (doubles_are_equal(xr, xp) && doubles_are_equal(yr, yp))
                belongs = 1;
            else
                belongs = -1;
        }
        else
        {
            appropriate_line = doubles_are_equal(xr, xp);
            appropriate_y_value = point_belongs_math_segment(yq, yr, yp);
            belongs = (char) (appropriate_line && appropriate_y_value);
        }
    }
    else if (!is_pq_vertical_line)
    {
        appropriate_line = doubles_are_equal(((yr - yq) / (xr - xq)), ((yp - yq) / (xp - xq)));
        appropriate_x_value = point_belongs_math_segment(xq, xr, xp);
        appropriate_y_value = point_belongs_math_segment(yq, yr, yp);
        belongs = (char) (appropriate_line && appropriate_x_value && appropriate_y_value);
    }

    return belongs;
}