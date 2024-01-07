#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#define MEMORY_ERROR 2

typedef struct node node_t;
struct node
{
    void *data;
    node_t *next;
};

int create_node(node_t **head);

void create_list(node_t **head);

void delete_list(node_t *head);

void copy_list(node_t **dst, node_t **src);

void each_list(node_t *head, void (*function)(void *));

void push_back(node_t **head, node_t *element);

void *pop_front(node_t **head);

void *pop_back(node_t **head);

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *));

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

#endif //LIST_H
