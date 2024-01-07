#ifndef FILMS_H
#define FILMS_H

#include <stdio.h>
#include <stdlib.h>

#include "film.h"

#define MIN_FILMS_COUNT 1

#define NOT_FOUND_ERROR_CODE 404
#define NOT_FOUND_ERROR_MSG "Not found"

#define NOT_ENOUGH_FILMS_ERROR 100

typedef film_t *films_t;

int free_films(films_t films, size_t count);

int insert_film_sorted(film_t film, films_t *films, size_t *count, int (*cmp)(film_t, film_t));

int input_films_sorted(FILE *file, int field, films_t *films, size_t *count);

int print_films(films_t films, size_t count);

int find_film(int field, const char *key, size_t *position, films_t films, size_t count);

#endif //FILMS_H
