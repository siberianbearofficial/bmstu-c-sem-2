#ifndef NUMBER_H
#define NUMBER_H

#include <stdlib.h>

#define MEMORY_ERROR 2
#define ZERO_ERROR 3

typedef struct element
{
    int multiplier;
    int degree;
} *element_t;

typedef struct node
{
    element_t data;
    struct node *next;
} *node_t;

typedef struct number
{
    node_t head;
} *number_t;

int create_number(number_t *number, int n);

void delete_number(number_t number);

void output_number(number_t number);

int to_int_number(number_t number);

int from_int_number(number_t number, int n);

int multiply_number(number_t a, number_t b, number_t answer);

int sqr_number(number_t a, number_t answer);

int div_number(number_t a, number_t b, number_t answer);

#endif //NUMBER_H
