#include "films.h"

int print_films(film_t *films, size_t films_count)
{
    for (size_t i = 0; i < films_count; i++)
        print_film(films + i);
    return EXIT_SUCCESS;
}

int find_film(int field, const char *key, size_t *position, film_t *films, size_t count)
{
    // Getting film_t cmp key function
    int (*cmp)(film_t *, const char *, int *);
    int return_code = film_cmp_key_func(&cmp, field);
    if (return_code)
        return return_code;

    int result;

    // Looking for a film_t position (binary search)
    size_t left_position = 0;
    size_t right_position = count - 1;
    *position = count / 2;
    while ((right_position - left_position > 1) && !return_code)
    {
        return_code = cmp(films + *position, key, &result);
        if (!return_code && result > 0)
            right_position = *position;
        else if (!return_code)
            left_position = *position;
        *position = (right_position + left_position) / 2;
    }
    if (return_code)
        return return_code;

    // Checking left position to contain required film_t
    *position = left_position;
    return_code = cmp(films + *position, key, &result);
    if (return_code || !result)
        return return_code;

    // Checking right position to contain required film_t
    *position = right_position;
    return_code = cmp(films + *position, key, &result);
    if (return_code || !result)
        return return_code;

    return NOT_FOUND_ERROR_CODE;
}

int insert_film_sorted(film_t *film, film_t *films, size_t *count, int (*cmp)(film_t *, film_t *))
{
    size_t i;
    for (i = *count; (i > 0) && (cmp(films + i - 1, film) > 0); i--)
        copy_film(films + i, films + i - 1);
    copy_film(films + i, film);
    (*count)++;
    return EXIT_SUCCESS;
}

int read_films_sorted(FILE *file, int field, film_t *films, size_t *count, film_t *buffer)
{
    *count = 0;

    // Reading first film
    int return_code = read_film(file, films);
    switch (return_code)
    {
        case EXIT_SUCCESS:
            {
                *count = 1;

                int (*cmp)(film_t *, film_t *);
                film_cmp_film_func(&cmp, field);

                // Reading other films in a sorted way
                int read_film_return_code;
                while (!(read_film_return_code = read_film(file, buffer)) && (*count <= MAX_FILMS_COUNT))
                    insert_film_sorted(buffer, films, count, cmp);

                if (read_film_return_code && (read_film_return_code != EXIT_FAILURE))
                    return_code = read_film_return_code;
                else if (*count < MIN_FILMS_COUNT)
                    return_code = NOT_ENOUGH_FILMS_ERROR;
                else if (*count > MAX_FILMS_COUNT)
                    return_code = TOO_MANY_FILMS_ERROR;
                break;
            }
        case EXIT_FAILURE:
            {
                return_code = NOT_ENOUGH_FILMS_ERROR;
                break;
            }
    }

    return return_code;
}
