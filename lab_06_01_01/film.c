#include <string.h>

#include "film.h"

#define SHORT_LINE_ERROR 12
#define LONG_LINE_ERROR 13

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

int film_title_cmp_key_title(film_t *to_compare, const char *title, int *result)
{
    *result = title_cmp(to_compare->title, title);
    return EXIT_SUCCESS;
}

int film_name_cmp_key_name(film_t *to_compare, const char *name, int *result)
{
    *result = name_cmp(to_compare->name, name);
    return EXIT_SUCCESS;
}

int film_year_cmp_key_year(film_t *to_compare, const char *year_str, int *result)
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

int film_title_cmp_film_title(film_t *film1, film_t *film2)
{
    return title_cmp(film1->title, film2->title);
}

int film_name_cmp_film_name(film_t *film1, film_t *film2)
{
    return name_cmp(film1->name, film2->name);
}

int film_year_cmp_film_year(film_t *film1, film_t *film2)
{
    return year_cmp(film1->year, film2->year);
}

int film_cmp_key_func(int (**cmp)(film_t *, const char *, int *), int field)
{
    int return_code = EXIT_SUCCESS;
    switch (field)
    {
        case TITLE:
            {
                *cmp = film_title_cmp_key_title;
                break;
            }
        case NAME:
            {
                *cmp = film_name_cmp_key_name;
                break;
            }
        case YEAR:
            {
                *cmp = film_year_cmp_key_year;
                break;
            }
        default:
            {
                return_code = UNKNOWN_FIELD_ERROR;
            }
    }
    return return_code;
}

int film_cmp_film_func(int (**cmp)(film_t *, film_t *), int field)
{
    int return_code = EXIT_SUCCESS;
    switch (field)
    {
        case TITLE:
            {
                *cmp = film_title_cmp_film_title;
                break;
            }
        case NAME:
            {
                *cmp = film_name_cmp_film_name;
                break;
            }
        case YEAR:
            {
                *cmp = film_year_cmp_film_year;
                break;
            }
        default:
            {
                return_code = UNKNOWN_FIELD_ERROR;
            }
    }
    return return_code;
}

int full_line(const char *str, size_t length)
{
    char return_code = EXIT_FAILURE;
    if (str && *str)
    {
        if (length < 1)
            return_code = SHORT_LINE_ERROR;
        else if (str[length])
            return_code = LONG_LINE_ERROR;
        else
            return_code = EXIT_SUCCESS;
    }
    return return_code;
}

int input_line(FILE *file, char *str, size_t max_length)
{
    int return_code = EXIT_FAILURE;
    char line[max_length + 2];
    if (fgets(line, (int) max_length + 2, file))
    {
        size_t length = strlen(line);
        return_code = full_line(line, length);
        if (!return_code && line[length - 1] == '\n')
            line[length - 1] = '\0';
    }
    if (!return_code)
        strcpy(str, line);
    return return_code;
}

int read_title(FILE *file, char *title)
{
    int return_code = input_line(file, title, MAX_TITLE_LEN);
    switch (return_code)
    {
        case EXIT_SUCCESS:
            {
                size_t length = strlen(title);
                if (length < MIN_TITLE_LEN)
                    return_code = SHORT_TITLE_ERROR;
                else if (length > MAX_TITLE_LEN)
                    return_code = LONG_TITLE_ERROR;
                break;
            }
        case SHORT_LINE_ERROR:
            {
                return_code = SHORT_TITLE_ERROR;
                break;
            }
        case LONG_LINE_ERROR:
            {
                return_code = LONG_TITLE_ERROR;
                break;
            }
    }
    return return_code;
}

int read_name(FILE *file, char *name)
{
    int return_code = input_line(file, name, MAX_NAME_LEN);
    switch (return_code)
    {
        case EXIT_SUCCESS:
            {
                size_t length = strlen(name);
                if (length < MIN_NAME_LEN)
                    return_code = SHORT_NAME_ERROR;
                else if (length > MAX_NAME_LEN)
                    return_code = LONG_NAME_ERROR;
                break;
            }
        case SHORT_LINE_ERROR:
            {
                return_code = SHORT_NAME_ERROR;
                break;
            }
        case LONG_LINE_ERROR:
            {
                return_code = LONG_NAME_ERROR;
                break;
            }
    }
    return return_code;
}

int read_year(FILE *file, int *year)
{
    char year_str[MAX_YEAR_LEN + 2];
    int return_code = input_line(file, year_str, MAX_YEAR_LEN);
    switch (return_code)
    {
        case EXIT_SUCCESS:
            {
                size_t length = strlen(year_str);
                if (length < MIN_YEAR_LEN)
                    return_code = SHORT_YEAR_ERROR;
                else if (length > MAX_YEAR_LEN)
                    return_code = LONG_YEAR_ERROR;
                else
                {
                    char *end_ptr;
                    long long_year = strtol(year_str, &end_ptr, 10);
                    if (!*end_ptr && long_year >= 0)
                        *year = (int) long_year;
                    else
                        return_code = INVALID_YEAR_ERROR;
                }
                break;
            }
        case SHORT_LINE_ERROR:
            {
                return_code = SHORT_YEAR_ERROR;
                break;
            }
        case LONG_LINE_ERROR:
            {
                return_code = LONG_YEAR_ERROR;
                break;
            }
    }
    return return_code;
}

int read_film(FILE *file, film_t *film_to_read)
{
    int return_code = read_title(file, film_to_read->title);
    if (!return_code)
        return_code = read_name(file, film_to_read->name);
    if (!return_code)
        return_code = read_year(file, &film_to_read->year);
    return return_code;
}

int print_film(film_t *film_to_print)
{
    printf("%s\n%s\n%d\n", film_to_print->title, film_to_print->name, film_to_print->year);
    return EXIT_SUCCESS;
}

int copy_film(film_t *dst, film_t *src)
{
    strcpy(dst->title, src->title);
    strcpy(dst->name, src->name);
    dst->year = src->year;
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
