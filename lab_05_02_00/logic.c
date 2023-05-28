#include "logic.h"

int process(int argc, char **argv, double *nearest_value)
{
    int exit_code = EXIT_FAILURE;
    if (argc == 2)
    {
        FILE *fin = fopen(argv[1], "r");
        if (fin)
        {
            double av;
            exit_code = average(fin, &av) || nearest(fin, av, nearest_value) || fclose(fin);
        }
    }
    return exit_code;
}

int average(FILE *fin, double *av)
{
    int exit_code = EXIT_FAILURE;
    double current;
    double sum = 0;
    int count;
    for (count = 0; fscanf(fin, "%lf", &current) == 1; count++, sum += current);
    if (count > 0)
    {
        *av = sum / count;
        exit_code = EXIT_SUCCESS;
    }
    fseek(fin, 0, SEEK_SET);
    return exit_code;
}

int nearest(FILE *fin, double value, double *nearest_value)
{
    int exit_code = EXIT_FAILURE;
    double current;
    if (fscanf(fin, "%lf", &current) == 1)
    {
        double min_diff = fabs(current - value);
        *nearest_value = current;
        exit_code = EXIT_SUCCESS;
        int count = 1;
        double first = current;
        while (fscanf(fin, "%lf", &current) == 1)
        {
            double current_diff = fabs(current - value);
            if (current_diff < min_diff)
            {
                min_diff = current_diff;
                *nearest_value = current;
            }
            count++;
        }
        if (count == 2)
            exit_code = fabs(first - current) >= EPS;
    }
    fseek(fin, 0, SEEK_SET);
    return exit_code;
}
