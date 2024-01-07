#include <stdio.h>
#include <stdlib.h>

#include "film.h"
#include "films.h"

#define NOT_ENOUGH_ARGS_ERROR 2
#define TOO_MANY_ARGS_ERROR 3

#define INPUT_FILE_MODE "r"

int main(int argc, char **argv)
{
    films_t films = NULL;

    if (argc < 3)
        return NOT_ENOUGH_ARGS_ERROR;
    if (argc > 4)
        return TOO_MANY_ARGS_ERROR;

    int exit_code;

    int field;
    if ((exit_code = field_name_to_field(argv[2], &field)))
        return exit_code;

    FILE *file = fopen(argv[1], INPUT_FILE_MODE);
    if (!file)
        return EXIT_FAILURE;

    size_t count = 0;
    exit_code = input_films_sorted(file, field, &films, &count);

    fclose(file);
    if (exit_code)
    {
        free_films(films, count);
        return exit_code;
    }

    if (argc == 4)
    {
        int find_film_return_code;
        size_t index;
        switch ((find_film_return_code = find_film(field, argv[3], &index, films, count)))
        {
            case NOT_FOUND_ERROR_CODE:
                printf("%s\n", NOT_FOUND_ERROR_MSG);
                break;
            case EXIT_SUCCESS:
                print_film(films[index]);
                break;
            default:
                exit_code = find_film_return_code;
                break;
        }
    }
    else
        print_films(films, count);

    free_films(films, count);

    return exit_code;
}
