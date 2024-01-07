#include <stdio.h>
#include <string.h>

#include "product.h"

#define SHORT_LINE_ERROR 20
#define LONG_LINE_ERROR 21

int cmp_price_product(const void *a, const void *b)
{
    double sub = *((const struct product *) a)->price - *((const struct product *) b)->price;
    if (sub > EPS)
        return 1;
    else if (sub < EPS && sub > -EPS)
        return 0;
    else
        return -1;
}

int cmp_title_product(const void *a, const void *b)
{
    size_t a_len = strlen(((const struct product *) a)->title);
    size_t b_len = strlen(((const struct product *) b)->title);
    if (a_len < b_len)
        return 1;
    else if (a_len > b_len)
        return -1;
    else
        return strcmp(((const struct product *) b)->title, ((const struct product *) a)->title);
}

int cmp_price_title_product(const void *a, const void *b)
{
    int cmp_result = cmp_price_product(a, b);
    if (!cmp_result)
        cmp_result = cmp_title_product(a, b);
    return cmp_result;
}

int create_product(product_t *product)
{
    *product = malloc(sizeof(struct product));
    if (!*product)
        return MEMORY_ERROR;

    (*product)->title = NULL;
    (*product)->price = NULL;

    return EXIT_SUCCESS;
}

void delete_product(product_t product)
{
    if (product)
    {
        if (product->title)
            free(product->title);
        if (product->price)
            free(product->price);
        free(product);
    }
}

void delete_products(node_t **list)
{
    while (*list)
        delete_product(pop_front(list));
    delete_list(*list);
    *list = NULL;
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

int read_line(FILE *file, char **str, size_t *length, size_t max_length)
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

int read_title(FILE *file, char **title)
{
    size_t length, max_length = 25;

    int return_code = EXIT_SUCCESS;
    do
    {
        return_code = read_line(file, title, &length, max_length);
        if (return_code == SHORT_LINE_ERROR || (!return_code && length < MIN_TITLE_LEN))
            return_code = SHORT_TITLE_ERROR;
        max_length += 25;
    }
    while (return_code == LONG_LINE_ERROR);

    return return_code;
}

int read_price(FILE *file, double **price)
{
    size_t length, max_length = 25;
    char *price_str = malloc(sizeof(char) * (MIN_PRICE_LEN + 1));
    if (!price_str)
        return MEMORY_ERROR;

    int return_code = EXIT_SUCCESS;
    do
    {
        return_code = read_line(file, &price_str, &length, max_length);
        if (return_code == SHORT_LINE_ERROR || (!return_code && length < MIN_PRICE_LEN))
            return_code = SHORT_PRICE_ERROR;
        max_length += 25;
    }
    while (return_code == LONG_LINE_ERROR);

    if (!return_code)
    {
        char *end_ptr;
        double long_price = strtod(price_str, &end_ptr);
        if (long_price > EPS)
        {
            double *tmp = realloc(*price, sizeof(double));
            if (tmp)
            {
                *price = tmp;
                **price = long_price;
            }
            else
                return_code = MEMORY_ERROR;
        }
        else
            return_code = INVALID_PRICE_ERROR;
    }

    free(price_str);
    return return_code;
}

int read_product(FILE *file, product_t *product)
{
    int return_code = create_product(product);
    if (!return_code)
    {
        return_code = read_title(file, &(*product)->title);
        if (!return_code)
            return_code = read_price(file, &(*product)->price);

        if (return_code)
            delete_product(*product);
    }
    return return_code;
}

int read_products(FILE *file, node_t **list)
{
    int return_code = EXIT_SUCCESS;
    while (!return_code)
    {
        product_t product;
        return_code = read_product(file, &product);
        if (!return_code)
        {
            node_t *node;
            create_node(&node);
            node->data = product;
            push_back(list, node);
        }
    }
    if (return_code == EXIT_FAILURE)
        return_code = EXIT_SUCCESS;
    else
        delete_products(list);
    return return_code;
}

void sort_unique_price_products(node_t **list)
{
    *list = sort(*list, cmp_price_title_product);
    remove_duplicates(list, cmp_price_product);
}

int pop_print_last_products(node_t **list, int count)
{
    int i = 0;
    for (node_t *node = *list; node && i <= count; node = node->next)
        i++;
    if (i < count)
        return EXIT_FAILURE;

    for (i = 0; i < count; i++)
    {
        product_t product = (product_t) pop_back(list);
        if (product && product->title)
            printf("%s\n", product->title);
    }
    return EXIT_SUCCESS;
}
