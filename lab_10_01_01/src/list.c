#include <stdio.h>
#include "list.h"

int create_node(node_t **head)
{
    *head = malloc(sizeof(node_t));
    if (!*head)
        return MEMORY_ERROR;

    (*head)->data = NULL;
    (*head)->next = NULL;

    return EXIT_SUCCESS;
}

void create_list(node_t **head)
{
    *head = NULL;
}

void delete_list(node_t *head)
{
    if (!head)
        return;

    node_t *buffer = head->next;
    free(head);
    delete_list(buffer);
}

void copy_list(node_t **dst, node_t **src)
{
    for (node_t *node = *src; node; node = node->next)
    {
        node_t *new_node;
        create_node(&new_node);
        new_node->data = node->data;
        push_back(dst, new_node);
    }
}

void each_list(node_t *head, void (*function)(void *))
{
    if (!head)
        return;

    function(head->data);

    each_list(head->next, function);
}

void push_back(node_t **head, node_t *element)
{
    if (!head || !element)
        return;

    if (!*head)
    {
        *head = element;
        element->next = NULL;
        return;
    }

    push_back(&(*head)->next, element);
}

void *pop_front(node_t **head)
{
    if (!head || !*head)
        return NULL;

    node_t *node = *head;
    void *data = node->data;
    *head = (*head)->next;
    free(node);
    return data;
}

void *pop_back(node_t **head)
{
    if (!head || !*head)
        return NULL;

    if (!(*head)->next)
    {
        void *data = (*head)->data;
        free(*head);
        *head = NULL;
        return data;
    }

    if (!(*head)->next->next)
    {
        void *data = (*head)->next->data;
        free((*head)->next);
        (*head)->next = NULL;
        return data;
    }

    return pop_back(&(*head)->next);
}

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    if (!*head)
        return;

    if (!(*head)->next)
        return;

    while ((*head)->next && !comparator((*head)->data, (*head)->next->data))
    {
        node_t *buffer = (*head)->next;
        (*head)->next = (*head)->next->next;
        free(buffer);
    }

    remove_duplicates(&(*head)->next, comparator);
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (!*head)
    {
        *head = element;
        return;
    }

    if (comparator((*head)->data, element->data) > 0)
    {
        element->next = *head;
        *head = element;
        return;
    }

    sorted_insert(&(*head)->next, element, comparator);
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node_t *sorted;
    create_list(&sorted);

    while (head)
    {
        node_t *node = head;
        head = head->next;
        node->next = NULL;
        sorted_insert(&sorted, node, comparator);
    }

    return sorted;
}
