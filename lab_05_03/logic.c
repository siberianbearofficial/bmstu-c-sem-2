#include "logic.h"

int rand_int(long seed);

int rand_int(long seed)
{
    srand(time(0) + seed);
    return rand() % MAX_NUM;
}

int generate_random_file(FILE *f)
{
    int exit_code = EXIT_SUCCESS;
    for (int i = 0; !exit_code && i < rand_int(SEED) + 1; i++)
        exit_code = put_number_by_pos(f, i, rand_int(i));
    return exit_code;
}

int sort_file(FILE *f, int n)
{
    int exit_code = EXIT_SUCCESS;
    for (int i = 0; i < n - 1 && !exit_code; i++)
    {
        for (int j = i + 1; j < n && !exit_code; j++)
        {
            int num1, num2;
            if (!get_number_by_pos(f, i, &num1) && !get_number_by_pos(f, j, &num2))
                exit_code = (num1 > num2) && (put_number_by_pos(f, i, num2) || put_number_by_pos(f, j, num1));
            else
                exit_code = EXIT_FAILURE;
        }
    }
    return exit_code;
}

int read_file(FILE *f, int n)
{
    int exit_code = EXIT_SUCCESS;
    for (int i = 0; i < n && !exit_code; i++)
    {
        int num;
        if (!get_number_by_pos(f, i, &num))
            printf("%d ", num);
        else
            exit_code = EXIT_FAILURE;
    }
    printf("\n");
    return exit_code;
}
