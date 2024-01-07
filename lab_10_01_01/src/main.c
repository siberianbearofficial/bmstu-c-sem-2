#include <stdio.h>

#include "list.h"
#include "product.h"

#define NOT_ENOUGH_ARGS_ERROR 12
#define TOO_MANY_ARGS_ERROR 13
#define FILE_ERROR 14

int main(int argc, char **argv)
{
    if (argc < 2)
        return NOT_ENOUGH_ARGS_ERROR;
    if (argc > 2)
        return TOO_MANY_ARGS_ERROR;

    FILE *file = fopen(argv[1], "r");
    if (!file)
        return FILE_ERROR;

    node_t *products, *new_products;
    create_list(&products);
    create_list(&new_products);

    int exit_code = read_products(file, &products);
    if (!exit_code)
    {
        copy_list(&new_products, &products);
        sort_unique_price_products(&new_products);
        exit_code = pop_print_last_products(&new_products, 3);
    }

    delete_products(&products);
    delete_list(new_products);

    fclose(file);

    return exit_code;
}
