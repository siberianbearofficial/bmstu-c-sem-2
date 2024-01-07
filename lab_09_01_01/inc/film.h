#ifndef FILM_H
#define FILM_H

#include <stdio.h>
#include <stdlib.h>

#define MIN_NAME_LEN 1
#define MIN_TITLE_LEN 1
#define MIN_YEAR_LEN 1

#define UNKNOWN_FIELD_ERROR 4

#define SHORT_TITLE_ERROR 5
#define SHORT_NAME_ERROR 7
#define SHORT_YEAR_ERROR 9

#define INVALID_YEAR_ERROR 11

#define MEMORY_ERROR 19

#define TITLE_FIELD_STR "title"
#define NAME_FIELD_STR "name"
#define YEAR_FIELD_STR "year"

enum fields
{
    TITLE = 1,
    NAME,
    YEAR
};

typedef struct film
{
    char *title;
    char *name;
    int year;
} *film_t;

int malloc_film(film_t *film);

int free_film(film_t film);

int input_film(FILE *file, film_t *film);

int print_film(film_t film);

int field_name_to_field(char *field_name, int *field);

int film_cmp_key_func(int (**cmp)(film_t, const char *, int *), int field);

int film_cmp_film_func(int (**cmp)(film_t, film_t), int field);

#endif //FILM_H
