#ifndef FILMS_H
#define FILMS_H

#include <stdio.h>
#include <stdlib.h>

#include "film.h"

#define MIN_FILMS_COUNT 1
#define MAX_FILMS_COUNT 15

#define NOT_FOUND_ERROR_CODE 404
#define NOT_FOUND_ERROR_MSG "Not found"

#define NOT_ENOUGH_FILMS_ERROR 100
#define TOO_MANY_FILMS_ERROR 110

int print_films(film_t *films, size_t count);

int find_film(int field, const char *key, size_t *position, film_t *films, size_t count);

int insert_film_sorted(film_t *film, film_t *films, size_t *count, int (*cmp)(film_t *, film_t *));

int read_films_sorted(FILE *file, int field, film_t *films, size_t *count, film_t *buffer);

#endif //FILMS_H
