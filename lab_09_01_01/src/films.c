#include "films.h"

int free_films(films_t films, size_t count)
{
    for (size_t i = 0; i < count; i++)
        free_film(films[i]);
    free(films);
    return EXIT_SUCCESS;
}

int insert_film_sorted(film_t film, films_t *films, size_t *count, int (*cmp)(film_t, film_t))
{
    films_t buffer = realloc(*films, (*count + 1) * sizeof(film_t));
    if (!buffer)
        return MEMORY_ERROR;
    *films = buffer;

    size_t i;
    for (i = *count; (i > 0) && (cmp((*films)[i - 1], film) > 0); i--)
        (*films)[i] = (*films)[i - 1];
    (*films)[i] = film;

    (*count)++;

    return EXIT_SUCCESS;
}

int input_films_sorted(FILE *file, int field, films_t *films, size_t *count)
{
    *count = 0;

    int (*cmp)(film_t, film_t);
    film_cmp_film_func(&cmp, field);
    film_t buffer;
    int return_code;

    do
    {
        return_code = input_film(file, &buffer);
        if (!return_code)
            return_code = insert_film_sorted(buffer, films, count, cmp);
    }
    while (!return_code);

    if (return_code == EXIT_FAILURE)
    {
        return_code = EXIT_SUCCESS;
        if (*count < MIN_FILMS_COUNT)
            return_code = NOT_ENOUGH_FILMS_ERROR;
    }

    return return_code;
}

int print_films(films_t films, size_t count)
{
    for (size_t i = 0; i < count; i++)
        print_film(films[i]);
    return EXIT_SUCCESS;
}

int find_film(int field, const char *key, size_t *position, films_t films, size_t count)
{
    // Getting film_t cmp key function
    int (*cmp)(film_t, const char *, int *);
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
        return_code = cmp(films[*position], key, &result);
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
    return_code = cmp(films[*position], key, &result);
    if (return_code || !result)
        return return_code;

    // Checking right position to contain required film_t
    *position = right_position;
    return_code = cmp(films[*position], key, &result);
    if (return_code || !result)
        return return_code;

    return NOT_FOUND_ERROR_CODE;
}
