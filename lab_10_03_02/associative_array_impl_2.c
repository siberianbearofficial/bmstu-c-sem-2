#include <stdlib.h>
#include <string.h>

#include "../lab_10_03_common/associative_array.h"

typedef struct node
{
    char *key;
    int *value;
    struct node *next;
} *node_t;

struct assoc_array_type
{
    node_t head;
};

assoc_array_t assoc_array_create(void)
{
    assoc_array_t arr = malloc(sizeof(struct assoc_array_type));
    if (!arr)
        return NULL;

    arr->head = NULL;

    return arr;
}

void assoc_array_destroy(assoc_array_t *arr)
{
    if (arr && *arr)
    {
        if ((*arr)->head)
        {
            for (node_t node = (*arr)->head, buffer; node; node = buffer)
            {
                buffer = node->next;
                free(node->key);
                free(node->value);
                free(node);
            }
        }
        free(*arr);
        *arr = NULL;
    }
}

assoc_array_error_t assoc_array_insert(assoc_array_t arr, const char *key, int num)
{
    if (!arr || !key || !*key)
        return ASSOC_ARRAY_INVALID_PARAM;
    int *found_num;
    assoc_array_error_t return_code = assoc_array_find(arr, key, &found_num);
    if (return_code == ASSOC_ARRAY_NOT_FOUND)
    {
        node_t node = malloc(sizeof(struct node));
        if (!node)
            return ASSOC_ARRAY_MEM;

        char *k_tmp = malloc(sizeof(char) * (strlen(key) + 1));
        if (!k_tmp)
        {
            free(node);
            return ASSOC_ARRAY_MEM;
        }
        strcpy(k_tmp, key);
        node->key = k_tmp;

        int *v_tmp = malloc(sizeof(int));
        if (!v_tmp)
        {
            free(node);
            free(k_tmp);
            return ASSOC_ARRAY_MEM;
        }
        *v_tmp = num;
        node->value = v_tmp;

        node->next = arr->head;
        arr->head = node;

        return ASSOC_ARRAY_OK;
    }
    else if (return_code == ASSOC_ARRAY_OK)
        return ASSOC_ARRAY_KEY_EXISTS;
    else
        return return_code;
}

assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    if (!arr || !key || !*key || !num)
        return ASSOC_ARRAY_INVALID_PARAM;
    for (node_t node = arr->head; node; node = node->next)
    {
        if (!strcmp(node->key, key))
        {
            *num = node->value;
            return ASSOC_ARRAY_OK;
        }
    }
    return ASSOC_ARRAY_NOT_FOUND;
}

assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    if (!arr || !key || !*key)
        return ASSOC_ARRAY_INVALID_PARAM;

    if (!arr->head)
        return ASSOC_ARRAY_NOT_FOUND;

    if (!strcmp(arr->head->key, key))
    {
        node_t node = arr->head->next;
        free(arr->head->key);
        free(arr->head->value);
        free(arr->head);
        arr->head = node;

        return ASSOC_ARRAY_OK;
    }

    if (!arr->head->next)
        return ASSOC_ARRAY_NOT_FOUND;

    int found = 0;
    for (node_t prev = arr->head, node = arr->head->next, buffer; !found && prev && node; prev = node, node = buffer)
    {
        buffer = node->next;
        if (!strcmp(node->key, key))
        {
            prev->next = node->next;
            free(node->key);
            free(node->value);
            free(node);

            found = 1;
        }
    }

    if (!found)
        return ASSOC_ARRAY_NOT_FOUND;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    if (!arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    for (node_t node = arr->head, buffer; node; node = buffer)
    {
        buffer = node->next;
        free(node->key);
        free(node->value);
        free(node);
    }

    arr->head = NULL;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t
assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (!arr || !action)
        return ASSOC_ARRAY_INVALID_PARAM;
    for (node_t node = arr->head; node; node = node->next)
        action(node->key, node->value, param);
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;
    if (!arr->head)
        return ASSOC_ARRAY_NOT_FOUND;
    node_t min_node = arr->head;
    for (node_t node = arr->head; node; node = node->next)
        if (strcmp(node->key, min_node->key) < 0)
            min_node = node;
    *num = min_node->value;
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;
    if (!arr->head)
        return ASSOC_ARRAY_NOT_FOUND;
    node_t max_node = arr->head;
    for (node_t node = arr->head; node; node = node->next)
        if (strcmp(node->key, max_node->key) > 0)
            max_node = node;
    *num = max_node->value;
    return ASSOC_ARRAY_OK;
}
