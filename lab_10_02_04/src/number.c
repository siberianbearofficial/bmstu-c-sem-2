#include <stdio.h>
#include <math.h>

#include "number.h"

// List

void delete_list(node_t node)
{
    if (!node)
        return;

    node_t buffer = node->next;
    free(node->data);
    free(node);
    delete_list(buffer);
}

int append_list(node_t *head, int multiplier, int degree)
{
    if (!*head)
    {
        element_t element;
        element = malloc(sizeof(struct element));
        if (!element)
            return MEMORY_ERROR;

        element->degree = degree;
        element->multiplier = multiplier;

        node_t node;
        node = malloc(sizeof(struct node));
        if (!node)
        {
            free(element);
            return MEMORY_ERROR;
        }

        node->data = element;
        node->next = NULL;

        *head = node;
        return EXIT_SUCCESS;
    }

    return append_list(&(*head)->next, multiplier, degree);
}

void pop_list(node_t *head, int *multiplier, int *degree)
{
    if (!*head)
        return;

    if (!(*head)->next)
    {
        *multiplier = (*head)->data->multiplier;
        *degree = (*head)->data->degree;
        free((*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    if (!(*head)->next->next)
    {
        *multiplier = (*head)->next->data->multiplier;
        *degree = (*head)->next->data->degree;
        free((*head)->next->data);
        free((*head)->next);
        (*head)->next = NULL;
        return;
    }

    pop_list(&(*head)->next, multiplier, degree);
}

// Number

int create_number(number_t *number, int n)
{
    *number = malloc(sizeof(struct number));
    if (!*number)
        return MEMORY_ERROR;

    (*number)->head = NULL;

    int return_code = EXIT_SUCCESS;
    if (n)
        return_code = from_int_number(*number, n);
    else
        (*number)->head = NULL;

    if (return_code)
    {
        delete_list((*number)->head);
        free(number);
    }

    return return_code;
}

void delete_number(number_t number)
{
    delete_list(number->head);
    free(number);
}

void output_number(number_t number)
{
    while (number->head)
    {
        int multiplier, degree;
        pop_list(&number->head, &multiplier, &degree);
        printf("%d %d ", multiplier, degree);
    }
    printf("1\n");
}

int to_int_number(number_t number)
{
    if (!number->head)
        return 0;

    double n = 1;
    while (number->head)
    {
        int multiplier, degree;
        pop_list(&number->head, &multiplier, &degree);
        n *= pow(multiplier, degree);
    }
    return (int) n;
}

int from_int_number(number_t number, int n)
{
    int return_code = EXIT_SUCCESS;
    int i = 2;
    while (!return_code && i <= n)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        if (count)
            return_code = append_list(&number->head, i, count);
        i++;
    }
    return return_code;
}

int multiply_number(number_t a, number_t b, number_t answer)
{
    int return_code = EXIT_SUCCESS;

    node_t a_node = a->head, b_node = b->head;
    while (!return_code && a_node && b_node)
    {
        if (a_node->data->multiplier < b_node->data->multiplier)
        {
            return_code = append_list(&answer->head, a_node->data->multiplier, a_node->data->degree);
            a_node = a_node->next;
        }
        else if (a_node->data->multiplier == b_node->data->multiplier)
        {
            return_code = append_list(&answer->head, a_node->data->multiplier, a_node->data->degree + b_node->data->degree);
            a_node = a_node->next;
            b_node = b_node->next;
        }
        else
        {
            return_code = append_list(&answer->head, b_node->data->multiplier, b_node->data->degree);
            b_node = b_node->next;
        }
    }
    while (a_node)
    {
        return_code = append_list(&answer->head, a_node->data->multiplier, a_node->data->degree);
        a_node = a_node->next;
    }
    while (b_node)
    {
        return_code = append_list(&answer->head, b_node->data->multiplier, b_node->data->degree);
        b_node = b_node->next;
    }

    return return_code;
}

int sqr_number(number_t a, number_t answer)
{
    int return_code = EXIT_SUCCESS;
    for (node_t node = a->head; node; node = node->next)
        return_code = append_list(&answer->head, node->data->multiplier, node->data->degree * 2);
    return return_code;
}

int div_number(number_t a, number_t b, number_t answer)
{
    int return_code = EXIT_SUCCESS;

    node_t a_node = a->head, b_node = b->head;
    while (!return_code && a_node && b_node)
    {
        if (a_node->data->multiplier < b_node->data->multiplier)
        {
            return_code = append_list(&answer->head, a_node->data->multiplier, a_node->data->degree);
            a_node = a_node->next;
        }
        else if (a_node->data->multiplier == b_node->data->multiplier)
        {
            if (a_node->data->degree - b_node->data->degree)
                return_code = append_list(&answer->head, a_node->data->multiplier, a_node->data->degree - b_node->data->degree);
            a_node = a_node->next;
            b_node = b_node->next;
        }
        else
        {
            return_code = append_list(&answer->head, b_node->data->multiplier, -b_node->data->degree);
            b_node = b_node->next;
        }
    }
    while (a_node)
    {
        return_code = append_list(&answer->head, a_node->data->multiplier, a_node->data->degree);
        a_node = a_node->next;
    }
    while (b_node)
    {
        return_code = append_list(&answer->head, b_node->data->multiplier, -b_node->data->degree);
        b_node = b_node->next;
    }

    int n = to_int_number(answer);

    if (n == 0)
        return ZERO_ERROR;

    if (!return_code)
        return_code = from_int_number(answer, n);

    return return_code;
}
