#include <string.h>

#include "film.h"

#define SHORT_LINE_ERROR 12
#define LONG_LINE_ERROR 13

int malloc_film(film_t *film)
{
    *film = (film_t) malloc(sizeof(struct film));
    if (!(*film))
        return MEMORY_ERROR;

    (*film)->name = malloc(sizeof(char) * (MIN_NAME_LEN + 1));
    if (!(*film)->name)
    {
        free(*film);
        return MEMORY_ERROR;
    }

    (*film)->title = malloc(sizeof(char) * (MIN_TITLE_LEN + 1));
    if (!(*film)->title)
    {
        free((*film)->name);
        free(*film);
        return MEMORY_ERROR;
    }

    return EXIT_SUCCESS;
}

int free_film(film_t film)
{
    free(film->name);
    free(film->title);
    free(film);
    return EXIT_SUCCESS;
}

int title_cmp(const char *title1, const char *title2)
{
    return strcmp(title1, title2);
}

int name_cmp(const char *name1, const char *name2)
{
    return strcmp(name1, name2);
}

int year_cmp(int year1, int year2)
{
    return year1 - year2;
}

int film_title_cmp_key_title(film_t to_compare, const char *title, int *result)
{
    *result = title_cmp(to_compare->title, title);
    return EXIT_SUCCESS;
}

int film_name_cmp_key_name(film_t to_compare, const char *name, int *result)
{
    *result = name_cmp(to_compare->name, name);
    return EXIT_SUCCESS;
}

int film_year_cmp_key_year(film_t to_compare, const char *year_str, int *result)
{
    int return_code = INVALID_YEAR_ERROR;
    char *end_ptr;
    long year = strtol(year_str, &end_ptr, 10);
    if (!*end_ptr && year >= 0)
    {
        *result = year_cmp(to_compare->year, (int) year);
        return_code = EXIT_SUCCESS;
    }
    return return_code;
}

int film_title_cmp_film_title(film_t film1, film_t film2)
{
    return title_cmp(film1->title, film2->title);
}

int film_name_cmp_film_name(film_t film1, film_t film2)
{
    return name_cmp(film1->name, film2->name);
}

int film_year_cmp_film_year(film_t film1, film_t film2)
{
    return year_cmp(film1->year, film2->year);
}

int film_cmp_key_func(int (**cmp)(film_t, const char *, int *), int field)
{
    int return_code = EXIT_SUCCESS;
    switch (field)
    {
        case TITLE:
            *cmp = film_title_cmp_key_title;
            break;
        case NAME:
            *cmp = film_name_cmp_key_name;
            break;
        case YEAR:
            *cmp = film_year_cmp_key_year;
            break;
        default:
            return_code = UNKNOWN_FIELD_ERROR;
            break;
    }
    return return_code;
}

int film_cmp_film_func(int (**cmp)(film_t, film_t), int field)
{
    int return_code = EXIT_SUCCESS;
    switch (field)
    {
        case TITLE:
            *cmp = film_title_cmp_film_title;
            break;
        case NAME:
            *cmp = film_name_cmp_film_name;
            break;
        case YEAR:
            *cmp = film_year_cmp_film_year;
            break;
        default:
            return_code = UNKNOWN_FIELD_ERROR;
            break;
    }
    return return_code;
}

int full_line(const char *str, size_t length, size_t max_length)
{
    char return_code = EXIT_FAILURE;
    if (str && *str)
    {
        if (length < 1)
            return_code = SHORT_LINE_ERROR;
        else if (length > max_length && str[length - 1] != '\n')
            return_code = LONG_LINE_ERROR;
        else
            return_code = EXIT_SUCCESS;
    }
    return return_code;
}

int input_line(FILE *file, char **str, size_t *length, size_t max_length)
{
    char *line = malloc(sizeof(char) * (max_length + 2));
    if (!line)
        return MEMORY_ERROR;

    int return_code = EXIT_FAILURE;
    if (fgets(line, (int) max_length + 2, file))
    {
        *length = strlen(line);
        return_code = full_line(line, *length, max_length);

        if (!return_code)
        {
            if (line[*length - 1] == '\n')
                line[--(*length)] = '\0';
            char *buffer = realloc(*str, sizeof(char) * (*length + 1));
            if (buffer)
            {
                *str = buffer;
                strcpy(*str, line);
            }
            else
                return_code = MEMORY_ERROR;
        }
    }

    free(line);

    return return_code;
}

int input_title(FILE *file, char **title)
{
    size_t length, max_length = 25;

    int return_code = EXIT_SUCCESS;
    do
    {
        return_code = input_line(file, title, &length, max_length);
        if (return_code == SHORT_LINE_ERROR || (!return_code && length < MIN_TITLE_LEN))
            return_code = SHORT_TITLE_ERROR;
        max_length += 25;
    }
    while (return_code == LONG_LINE_ERROR);

    return return_code;
}

int input_name(FILE *file, char **name)
{
    size_t length, max_length = 25;

    int return_code = EXIT_SUCCESS;
    do
    {
        return_code = input_line(file, name, &length, max_length);
        if (return_code == SHORT_LINE_ERROR || (!return_code && length < MIN_NAME_LEN))
            return_code = SHORT_NAME_ERROR;
        max_length += 25;
    }
    while (return_code == LONG_LINE_ERROR);

    return return_code;
}

int input_year(FILE *file, int *year)
{
    size_t length, max_length = 25;
    char *year_str = malloc(sizeof(char) * (MIN_YEAR_LEN + 1));
    if (!year_str)
        return MEMORY_ERROR;

    int return_code = EXIT_SUCCESS;
    do
    {
        return_code = input_line(file, &year_str, &length, max_length);
        if (return_code == SHORT_LINE_ERROR || (!return_code && length < MIN_YEAR_LEN))
            return_code = SHORT_YEAR_ERROR;
        max_length += 25;
    }
    while (return_code == LONG_LINE_ERROR);

    if (!return_code)
    {
        char *end_ptr;
        long long_year = strtol(year_str, &end_ptr, 10);
        if (long_year > 0)
            *year = (int) long_year;
        else
            return_code = INVALID_YEAR_ERROR;
    }

    free(year_str);
    return return_code;
}

int input_film(FILE *file, film_t *film)
{
    int return_code = malloc_film(film);
    if (return_code)
        return return_code;

    return_code = input_title(file, &((*film)->title));
    if (!return_code)
    {
        return_code = input_name(file, &((*film)->name));
        if (!return_code)
            return_code = input_year(file, &((*film)->year));
    }

    if (return_code)
        free_film(*film);

    return return_code;
}

int print_film(film_t film)
{
    printf("%s\n%s\n%d\n", film->title, film->name, film->year);
    return EXIT_SUCCESS;
}

int field_name_to_field(char *field_name, int *field)
{
    int return_code = EXIT_SUCCESS;
    if (!strcmp(field_name, TITLE_FIELD_STR))
        *field = TITLE;
    else if (!strcmp(field_name, NAME_FIELD_STR))
        *field = NAME;
    else if (!strcmp(field_name, YEAR_FIELD_STR))
        *field = YEAR;
    else
        return_code = UNKNOWN_FIELD_ERROR;
    return return_code;
}
