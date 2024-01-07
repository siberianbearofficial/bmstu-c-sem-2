#include <check.h>
#include "list.h"

int comparator(const void *a, const void *b)
{
    return *((const int *) a) - *((const int *) b);
}




START_TEST(push_back_empty)
{
    node_t *head;
    create_list(&head);
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    node->data = data;

    push_back(&head, node);

    for (node_t *current = head; current; current = current->next)
        ck_assert_ptr_eq(current->data, data);
    free(data);
    delete_list(head);
}
END_TEST

START_TEST(push_back_full)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    node->data = data;
    push_back(&head, node);
    
    node_t *node2;
    create_node(&node2);
    int *data2 = malloc(sizeof(int));
    node2->data = data2;
    push_back(&head, node2);
    
    node_t *node3;
    create_node(&node3);
    int *data3 = malloc(sizeof(int));
    node3->data = data3;
    
    int *correct[] = {data, data2, data3};

    push_back(&head, node3);

    int i = 0;
    for (node_t *current = head; current; current = current->next, i++)
        ck_assert_ptr_eq(current->data, correct[i]);
    free(data);
    free(data2);
    free(data3);
    delete_list(head);
}
END_TEST

Suite *push_back_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("push_back");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, push_back_empty);
    tcase_add_test(tc_core, push_back_full);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(pop_back_empty)
{
    node_t *head;
    create_list(&head);

    node_t *res = pop_back(&head);

    ck_assert_ptr_eq(res, NULL);
    delete_list(head);
}
END_TEST

START_TEST(pop_back_single)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    node->data = data;
    push_back(&head, node);

    void *res = pop_back(&head);

    ck_assert_ptr_eq(head, NULL);
    ck_assert_ptr_eq(res, data);
    free(data);
    delete_list(head);
}
END_TEST

START_TEST(pop_back_full)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    node->data = data;
    push_back(&head, node);
    
    node_t *node2;
    create_node(&node2);
    int *data2 = malloc(sizeof(int));
    node2->data = data2;
    push_back(&head, node2);
    
    node_t *node3;
    create_node(&node3);
    int *data3 = malloc(sizeof(int));
    node3->data = data3;
    push_back(&head, node3);
    
    int *correct[] = {data, data2};

    void *res = pop_back(&head);

    int i = 0;
    for (node_t *current = head; current; current = current->next, i++)
        ck_assert_ptr_eq(current->data, correct[i]);
    ck_assert_ptr_eq(res, data3);
    free(data);
    free(data2);
    free(data3);
    delete_list(head);
}
END_TEST

Suite *pop_back_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("pop_back");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, pop_back_empty);
    tcase_add_test(tc_core, pop_back_single);
    tcase_add_test(tc_core, pop_back_full);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(pop_front_empty)
{
    node_t *head;
    create_list(&head);

    node_t *res = pop_front(&head);

    ck_assert_ptr_eq(res, NULL);
    delete_list(head);
}
END_TEST

START_TEST(pop_front_single)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    node->data = data;
    push_back(&head, node);

    void *res = pop_front(&head);

    ck_assert_ptr_eq(head, NULL);
    ck_assert_ptr_eq(res, data);
    free(data);
    delete_list(head);
}
END_TEST

START_TEST(pop_front_full)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    node->data = data;
    push_back(&head, node);
    
    node_t *node2;
    create_node(&node2);
    int *data2 = malloc(sizeof(int));
    node2->data = data2;
    push_back(&head, node2);
    
    node_t *node3;
    create_node(&node3);
    int *data3 = malloc(sizeof(int));
    node3->data = data3;
    push_back(&head, node3);
    
    int *correct[] = {data2, data3};

    void *res = pop_front(&head);

    int i = 0;
    for (node_t *current = head; current; current = current->next, i++)
        ck_assert_ptr_eq(current->data, correct[i]);
    ck_assert_ptr_eq(res, data);
    free(data);
    free(data2);
    free(data3);
    delete_list(head);
}
END_TEST

Suite *pop_front_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("pop_front");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, pop_front_empty);
    tcase_add_test(tc_core, pop_front_single);
    tcase_add_test(tc_core, pop_front_full);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(remove_duplicates_empty)
{
    node_t *head;
    create_list(&head);

    remove_duplicates(&head, comparator);

    ck_assert_ptr_eq(head, NULL);
    delete_list(head);
}
END_TEST

START_TEST(remove_duplicates_nothing)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    *data = 1;
    node->data = data;
    push_back(&head, node);
    
    node_t *node2;
    create_node(&node2);
    int *data2 = malloc(sizeof(int));
    *data2 = 2;
    node2->data = data2;
    push_back(&head, node2);
    
    node_t *node3;
    create_node(&node3);
    int *data3 = malloc(sizeof(int));
    *data3 = 3;
    node3->data = data3;
    push_back(&head, node3);
    
    int *correct[] = {data, data2, data3};

    remove_duplicates(&head, comparator);

    int i = 0;
    for (node_t *current = head; current; current = current->next, i++)
        ck_assert_ptr_eq(current->data, correct[i]);
    free(data);
    free(data2);
    free(data3);
    delete_list(head);
}
END_TEST

START_TEST(remove_duplicates_some)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    *data = 2;
    node->data = data;
    push_back(&head, node);
    
    node_t *node2;
    create_node(&node2);
    int *data2 = malloc(sizeof(int));
    *data2 = 2;
    node2->data = data2;
    push_back(&head, node2);
    
    node_t *node3;
    create_node(&node3);
    int *data3 = malloc(sizeof(int));
    *data3 = 3;
    node3->data = data3;
    push_back(&head, node3);
    
    int *correct[] = {data, data3};

    remove_duplicates(&head, comparator);

    int i = 0;
    for (node_t *current = head; current; current = current->next, i++)
        ck_assert_ptr_eq(current->data, correct[i]);
    free(data);
    free(data2);
    free(data3);
    delete_list(head);
}
END_TEST

START_TEST(remove_duplicates_everything)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    *data = 3;
    node->data = data;
    push_back(&head, node);
    
    node_t *node2;
    create_node(&node2);
    int *data2 = malloc(sizeof(int));
    *data2 = 3;
    node2->data = data2;
    push_back(&head, node2);
    
    node_t *node3;
    create_node(&node3);
    int *data3 = malloc(sizeof(int));
    *data3 = 3;
    node3->data = data3;
    push_back(&head, node3);

    remove_duplicates(&head, comparator);

    ck_assert_ptr_eq(head, node);
    free(data);
    free(data2);
    free(data3);
    delete_list(head);
}
END_TEST

Suite *remove_duplicates_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("remove_duplicates");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, remove_duplicates_empty);
    tcase_add_test(tc_core, remove_duplicates_nothing);
    tcase_add_test(tc_core, remove_duplicates_some);
    tcase_add_test(tc_core, remove_duplicates_everything);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(sort_empty)
{
    node_t *head;
    create_list(&head);

    head = sort(head, comparator);

    ck_assert_ptr_eq(head, NULL);
    delete_list(head);
}
END_TEST

START_TEST(sort_single)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    *data = 1;
    node->data = data;
    push_back(&head, node);
    
    int *correct[] = {data};

    head = sort(head, comparator);

    int i = 0;
    for (node_t *current = head; current; current = current->next, i++)
        ck_assert_ptr_eq(current->data, correct[i]);
    free(data);
    delete_list(head);
}
END_TEST

START_TEST(sort_random)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    *data = 5;
    node->data = data;
    push_back(&head, node);
    
    node_t *node2;
    create_node(&node2);
    int *data2 = malloc(sizeof(int));
    *data2 = 2;
    node2->data = data2;
    push_back(&head, node2);
    
    node_t *node3;
    create_node(&node3);
    int *data3 = malloc(sizeof(int));
    *data3 = 3;
    node3->data = data3;
    push_back(&head, node3);
    
    int *correct[] = {data2, data3, data};

    head = sort(head, comparator);

    int i = 0;
    for (node_t *current = head; current; current = current->next, i++)
        ck_assert_ptr_eq(current->data, correct[i]);
    free(data);
    free(data2);
    free(data3);
    delete_list(head);
}
END_TEST

START_TEST(sort_sorted)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    *data = 1;
    node->data = data;
    push_back(&head, node);
    
    node_t *node2;
    create_node(&node2);
    int *data2 = malloc(sizeof(int));
    *data2 = 2;
    node2->data = data2;
    push_back(&head, node2);
    
    node_t *node3;
    create_node(&node3);
    int *data3 = malloc(sizeof(int));
    *data3 = 3;
    node3->data = data3;
    push_back(&head, node3);
    
    int *correct[] = {data, data2, data3};

    head = sort(head, comparator);

    int i = 0;
    for (node_t *current = head; current; current = current->next, i++)
        ck_assert_ptr_eq(current->data, correct[i]);
    free(data);
    free(data2);
    free(data3);
    delete_list(head);
}
END_TEST

START_TEST(sort_sorted_reversed)
{
    node_t *head;
    create_list(&head);
    
    node_t *node;
    create_node(&node);
    int *data = malloc(sizeof(int));
    *data = 5;
    node->data = data;
    push_back(&head, node);
    
    node_t *node2;
    create_node(&node2);
    int *data2 = malloc(sizeof(int));
    *data2 = 4;
    node2->data = data2;
    push_back(&head, node2);
    
    node_t *node3;
    create_node(&node3);
    int *data3 = malloc(sizeof(int));
    *data3 = 3;
    node3->data = data3;
    push_back(&head, node3);
    
    int *correct[] = {data3, data2, data};

    head = sort(head, comparator);

    int i = 0;
    for (node_t *current = head; current; current = current->next, i++)
        ck_assert_ptr_eq(current->data, correct[i]);
    free(data);
    free(data2);
    free(data3);
    delete_list(head);
}
END_TEST

Suite *sort_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("sort");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, sort_empty);
    tcase_add_test(tc_core, sort_single);
    tcase_add_test(tc_core, sort_random);
    tcase_add_test(tc_core, sort_sorted);
    tcase_add_test(tc_core, sort_sorted_reversed);
    suite_add_tcase(s, tc_core);
    return s;
}
