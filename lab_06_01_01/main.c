#include <stdio.h>
#include <stdlib.h>

#include "film.h"
#include "films.h"

#define NOT_ENOUGH_ARGS_ERROR 2
#define TOO_MANY_ARGS_ERROR 3

int main(int argc, char **argv)
{
    film_t films[MAX_FILMS_COUNT + 1], buffer;

    // Checking arguments count
    if (argc < 3)
        return NOT_ENOUGH_ARGS_ERROR;
    if (argc > 4)
        return TOO_MANY_ARGS_ERROR;

    int exit_code;

    // Getting field
    int field;
    if ((exit_code = field_name_to_field(argv[2], &field)))
        return exit_code;

    // Reading file
    FILE *file = fopen(argv[1], "r");
    if (!file)
        return EXIT_FAILURE;

    // Reading films
    size_t count;
    exit_code = read_films_sorted(file, field, films, &count, &buffer);

    // Closing file
    fclose(file);
    if (exit_code)
        return exit_code;

    if (argc == 4)
    {
        // Looking for a film_t
        int find_film_return_code;
        size_t index;
        switch ((find_film_return_code = find_film(field, argv[3], &index, films, count)))
        {
            case NOT_FOUND_ERROR_CODE:
                {
                    printf("%s\n", NOT_FOUND_ERROR_MSG);
                    break;
                }
            case EXIT_SUCCESS:
                {
                    print_film(films + index);
                    break;
                }
            default:
                {
                    exit_code = find_film_return_code;
                    break;
                }
        }
    }
    else
    {
        // Printing films
        print_films(films, count);
    }

    return exit_code;
}
