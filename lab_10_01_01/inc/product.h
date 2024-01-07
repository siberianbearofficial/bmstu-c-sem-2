#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdlib.h>

#include "list.h"

#define EPS 0.00001

#define MIN_TITLE_LEN 1
#define SHORT_TITLE_ERROR 22
#define MIN_PRICE_LEN 1
#define SHORT_PRICE_ERROR 23
#define INVALID_PRICE_ERROR 24

typedef struct product
{
    char *title;
    double *price;
} *product_t;

int read_products(FILE *file, node_t **list);

void delete_products(node_t **list);

void sort_unique_price_products(node_t **list);

int pop_print_last_products(node_t **list, int count);

#endif //PRODUCT_H
