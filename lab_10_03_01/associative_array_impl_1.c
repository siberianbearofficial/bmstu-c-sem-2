#include <stdlib.h>
#include <string.h>

#include "../lab_10_03_common/associative_array.h"

struct assoc_array_type
{
    char **keys;
    int **values;
    int length;
};

assoc_array_t assoc_array_create(void)
{
    assoc_array_t arr = malloc(sizeof(struct assoc_array_type));
    if (!arr)
        return NULL;

    arr->keys = NULL;
    arr->values = NULL;
    arr->length = 0;

    return arr;
}

void assoc_array_destroy(assoc_array_t *arr)
{
    if (arr && *arr)
    {
        if ((*arr)->keys)
        {
            for (int i = 0; i < (*arr)->length; i++)
            {
                free((*arr)->keys[i]);
                free((*arr)->values[i]);
            }
            free((*arr)->keys);
            free((*arr)->values);
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
        char **keys_tmp = realloc(arr->keys, sizeof(char *) * (arr->length + 1));
        if (!keys_tmp)
            return ASSOC_ARRAY_MEM;
        arr->keys = keys_tmp;

        int **values_tmp = realloc(arr->values, sizeof(int *) * (arr->length + 1));
        if (!values_tmp)
            return ASSOC_ARRAY_MEM;
        arr->values = values_tmp;

        char *k_tmp = malloc(sizeof(char) * (strlen(key) + 1));
        if (!k_tmp)
            return ASSOC_ARRAY_MEM;
        strcpy(k_tmp, key);
        arr->keys[arr->length] = k_tmp;

        int *v_tmp = malloc(sizeof(int));
        if (!v_tmp)
        {
            free(k_tmp);
            return ASSOC_ARRAY_MEM;
        }
        *v_tmp = num;
        arr->values[arr->length] = v_tmp;

        arr->length++;

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
    for (int i = 0; i < arr->length; i++)
    {
        if (!strcmp(arr->keys[i], key))
        {
            *num = arr->values[i];
            return ASSOC_ARRAY_OK;
        }
    }
    return ASSOC_ARRAY_NOT_FOUND;
}

assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    if (!arr || !key || !*key)
        return ASSOC_ARRAY_INVALID_PARAM;
    int index = -1;
    for (int i = 0; index == -1 && i < arr->length; i++)
    {
        if (!strcmp(arr->keys[i], key))
            index = i;
    }
    if (index == -1)
        return ASSOC_ARRAY_NOT_FOUND;

    free(arr->keys[index]);
    free(arr->values[index]);
    for (int i = index; i < arr->length - 1; i++)
    {
        arr->keys[i] = arr->keys[i + 1];
        arr->values[i] = arr->values[i + 1];
    }

    char **keys_tmp = realloc(arr->keys, sizeof(char *) * (arr->length - 1));
    if (!keys_tmp && arr->length > 1)
        return ASSOC_ARRAY_MEM;
    arr->keys = keys_tmp;

    int **values_tmp = realloc(arr->values, sizeof(int *) * (arr->length - 1));
    if (!values_tmp && arr->length > 1)
        return ASSOC_ARRAY_MEM;
    arr->values = values_tmp;

    arr->length--;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    if (!arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    for (int i = 0; i < arr->length; i++)
    {
        free(arr->keys[i]);
        free(arr->values[i]);
    }
    free(arr->keys);
    free(arr->values);

    arr->keys = NULL;
    arr->values = NULL;
    arr->length = 0;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (!arr || !action)
        return ASSOC_ARRAY_INVALID_PARAM;
    for (int i = 0; i < arr->length; i++)
        action(arr->keys[i], arr->values[i], param);
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;
    if (arr->length == 0)
        return ASSOC_ARRAY_NOT_FOUND;
    int min_index = 0;
    for (int i = 0; i < arr->length; i++)
        if (strcmp(arr->keys[i], arr->keys[min_index]) < 0)
            min_index = i;
    *num = arr->values[min_index];
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;
    if (arr->length == 0)
        return ASSOC_ARRAY_NOT_FOUND;
    int max_index = 0;
    for (int i = 0; i < arr->length; i++)
        if (strcmp(arr->keys[i], arr->keys[max_index]) > 0)
            max_index = i;
    *num = arr->values[max_index];
    return ASSOC_ARRAY_OK;
}
