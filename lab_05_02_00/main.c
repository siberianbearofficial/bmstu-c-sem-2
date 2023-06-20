// найти число, наиболее близкое по значению к среднему значению всех чисел

#include "main.h"

int main(int argc, char **argv)
{
    int exit_code = EXIT_FAILURE;
    double nearest_value;
    if (!process(argc, argv, &nearest_value))
    {
        printf("%lf", nearest_value);
        exit_code = EXIT_SUCCESS;
    }
    return exit_code;
}
