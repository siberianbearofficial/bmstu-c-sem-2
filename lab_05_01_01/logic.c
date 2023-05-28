#include "logic.h"

int process(FILE *f, int *max_1, int *max_2)
{
    int exit_code = EXIT_SUCCESS;
    int i, num;
    if (fscanf(f, "%d", &num) == 1)
    {
        *max_1 = num;
        if (fscanf(f, "%d", &num) == 1)
        {
            if (num > *max_1)
            {
                *max_2 = *max_1;
                *max_1 = num;
            }
            else
                *max_2 = num;
            for (i = 2; fscanf(f, "%d", &num) > 0 && !exit_code; i++)
            {
                if (num >= *max_1)
                {
                    *max_2 = *max_1;
                    *max_1 = num;
                }
                else if (num > *max_2)
                {
                    *max_2 = num;
                }
                if (i == MAX_N)
                    exit_code = LONG_FILE;
            }
        }
        else
            exit_code = ONLY_ONE_NUM;
    }
    else
        exit_code = EMPTY_FILE;
    return exit_code;
}
