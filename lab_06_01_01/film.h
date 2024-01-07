#ifndef FILM_H
#define FILM_H

#include <stdio.h>
#include <stdlib.h>

#define MIN_NAME_LEN 1
#define MAX_NAME_LEN 25
#define MIN_TITLE_LEN 1
#define MAX_TITLE_LEN 25
#define MIN_YEAR_LEN 1
#define MAX_YEAR_LEN 25

#define UNKNOWN_FIELD_ERROR 4

#define SHORT_TITLE_ERROR 5
#define LONG_TITLE_ERROR 6

#define SHORT_NAME_ERROR 7
#define LONG_NAME_ERROR 8

#define SHORT_YEAR_ERROR 9
#define LONG_YEAR_ERROR 10

#define INVALID_YEAR_ERROR 11

#define TITLE_FIELD_STR "title"
#define NAME_FIELD_STR "name"
#define YEAR_FIELD_STR "year"

enum fields
{
    TITLE = 1,
    NAME,
    YEAR
};

typedef struct
{
    char title[MAX_TITLE_LEN];
    char name[MAX_NAME_LEN];
    int year;
} film_t;

int read_film(FILE *file, film_t *film);

int print_film(film_t *film);

int copy_film(film_t *dst, film_t *src);

int field_name_to_field(char *field_name, int *field);

int film_cmp_key_func(int (**cmp)(film_t *, const char *, int *), int field);

int film_cmp_film_func(int (**cmp)(film_t *, film_t *), int field);

#endif //FILM_H
