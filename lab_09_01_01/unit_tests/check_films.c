#include <check.h>
#include "films.h"



START_TEST(insert_film_sorted_empty)
{
    film_t a, b, c;
    
    malloc_film(&a);
    malloc_film(&b);
    malloc_film(&c);
    
    strcpy(a->name, "a");
    strcpy(a->title, "a");
    a->year = 1;
    
    strcpy(b->name, "b");
    strcpy(b->title, "b");
    b->year = 2;
    
    strcpy(c->name, "c");
    strcpy(c->title, "c");
    c->year = 3;
    
    films_t films = NULL;
    size_t count = 0;
    
    int (*cmp)(film_t, film_t);
    film_cmp_film_func(&cmp, YEAR);

    int return_code = insert_film_sorted(c, &films, &count, cmp);
    if (!return_code)
    {
        return_code = insert_film_sorted(a, &films, &count, cmp);
        if (!return_code)
            return_code = insert_film_sorted(b, &films, &count, cmp);
    }

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_ptr_eq(films[0], a);
    ck_assert_ptr_eq(films[1], b);
    ck_assert_ptr_eq(films[2], c);
    
    free_films(films, count);
}
END_TEST

START_TEST(insert_film_sorted_single_start)
{
    film_t a, b;
    
    malloc_film(&a);
    malloc_film(&b);
    
    strcpy(a->name, "a");
    strcpy(a->title, "a");
    a->year = 1;
    
    strcpy(b->name, "b");
    strcpy(b->title, "b");
    b->year = 2;
    
    films_t films = NULL;
    size_t count = 0;
    
    int (*cmp)(film_t, film_t);
    film_cmp_film_func(&cmp, YEAR);
    
    insert_film_sorted(b, &films, &count, cmp);

    int return_code = insert_film_sorted(a, &films, &count, cmp);

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_ptr_eq(films[0], a);
    
    free_films(films, count);
}
END_TEST

START_TEST(insert_film_sorted_single_end)
{
    film_t a, b;
    
    malloc_film(&a);
    malloc_film(&b);
    
    strcpy(a->name, "a");
    strcpy(a->title, "a");
    a->year = 1;
    
    strcpy(b->name, "b");
    strcpy(b->title, "b");
    b->year = 2;
    
    films_t films = NULL;
    size_t count = 0;
    
    int (*cmp)(film_t, film_t);
    film_cmp_film_func(&cmp, YEAR);
    
    insert_film_sorted(a, &films, &count, cmp);

    int return_code = insert_film_sorted(b, &films, &count, cmp);

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_ptr_eq(films[1], b);
    
    free_films(films, count);
}
END_TEST

START_TEST(insert_film_sorted_simple_start)
{
    film_t a, b, c;
    
    malloc_film(&a);
    malloc_film(&b);
    malloc_film(&c);
    
    strcpy(a->name, "a");
    strcpy(a->title, "a");
    a->year = 1;
    
    strcpy(b->name, "b");
    strcpy(b->title, "b");
    b->year = 2;
    
    strcpy(c->name, "c");
    strcpy(c->title, "c");
    c->year = 3;
    
    films_t films = NULL;
    size_t count = 0;
    
    int (*cmp)(film_t, film_t);
    film_cmp_film_func(&cmp, YEAR);
    
    insert_film_sorted(b, &films, &count, cmp);
    insert_film_sorted(c, &films, &count, cmp);

    int return_code = insert_film_sorted(a, &films, &count, cmp);

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_ptr_eq(films[0], a);
    
    free_films(films, count);
}
END_TEST

START_TEST(insert_film_sorted_simple_middle)
{
    film_t a, b, c;
    
    malloc_film(&a);
    malloc_film(&b);
    malloc_film(&c);
    
    strcpy(a->name, "a");
    strcpy(a->title, "a");
    a->year = 1;
    
    strcpy(b->name, "b");
    strcpy(b->title, "b");
    b->year = 2;
    
    strcpy(c->name, "c");
    strcpy(c->title, "c");
    c->year = 3;
    
    films_t films = NULL;
    size_t count = 0;
    
    int (*cmp)(film_t, film_t);
    film_cmp_film_func(&cmp, YEAR);
    
    insert_film_sorted(a, &films, &count, cmp);
    insert_film_sorted(c, &films, &count, cmp);

    int return_code = insert_film_sorted(b, &films, &count, cmp);

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_ptr_eq(films[1], b);
    
    free_films(films, count);
}
END_TEST

START_TEST(insert_film_sorted_simple_end)
{
    film_t a, b, c;
    
    malloc_film(&a);
    malloc_film(&b);
    malloc_film(&c);
    
    strcpy(a->name, "a");
    strcpy(a->title, "a");
    a->year = 1;
    
    strcpy(b->name, "b");
    strcpy(b->title, "b");
    b->year = 2;
    
    strcpy(c->name, "c");
    strcpy(c->title, "c");
    c->year = 3;
    
    films_t films = NULL;
    size_t count = 0;
    
    int (*cmp)(film_t, film_t);
    film_cmp_film_func(&cmp, YEAR);
    
    insert_film_sorted(a, &films, &count, cmp);
    insert_film_sorted(b, &films, &count, cmp);

    int return_code = insert_film_sorted(c, &films, &count, cmp);

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_ptr_eq(films[2], c);
    
    free_films(films, count);
}
END_TEST

Suite *insert_film_sorted_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("insert_film_sorted");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, insert_film_sorted_empty);
    tcase_add_test(tc_core, insert_film_sorted_single_start);
    tcase_add_test(tc_core, insert_film_sorted_single_end);
    tcase_add_test(tc_core, insert_film_sorted_simple_start);
    tcase_add_test(tc_core, insert_film_sorted_simple_middle);
    tcase_add_test(tc_core, insert_film_sorted_simple_end);
    suite_add_tcase(s, tc_core);
    return s;
}


START_TEST(find_film_start)
{
    film_t a, b, c;
    
    malloc_film(&a);
    malloc_film(&b);
    malloc_film(&c);
    
    strcpy(a->name, "a");
    strcpy(a->title, "a");
    a->year = 1;
    
    strcpy(b->name, "b");
    strcpy(b->title, "b");
    b->year = 2;
    
    strcpy(c->name, "c");
    strcpy(c->title, "c");
    c->year = 3;
    
    films_t films = NULL;
    size_t count = 0;
    size_t position;
    
    int (*cmp)(film_t, film_t);
    film_cmp_film_func(&cmp, YEAR);
    
    insert_film_sorted(a, &films, &count, cmp);
    insert_film_sorted(b, &films, &count, cmp);
    insert_film_sorted(c, &films, &count, cmp);

    int return_code = find_film(YEAR, "1", &position, films, count);

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_int_eq(position, 0);
    
    free_films(films, count);
}
END_TEST

START_TEST(find_film_middle)
{
    film_t a, b, c;
    
    malloc_film(&a);
    malloc_film(&b);
    malloc_film(&c);
    
    strcpy(a->name, "a");
    strcpy(a->title, "a");
    a->year = 1;
    
    strcpy(b->name, "b");
    strcpy(b->title, "b");
    b->year = 2;
    
    strcpy(c->name, "c");
    strcpy(c->title, "c");
    c->year = 3;
    
    films_t films = NULL;
    size_t count = 0;
    size_t position;
    
    int (*cmp)(film_t, film_t);
    film_cmp_film_func(&cmp, YEAR);
    
    insert_film_sorted(a, &films, &count, cmp);
    insert_film_sorted(b, &films, &count, cmp);
    insert_film_sorted(c, &films, &count, cmp);

    int return_code = find_film(YEAR, "2", &position, films, count);

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_int_eq(position, 1);
    
    free_films(films, count);
}
END_TEST

START_TEST(find_film_end)
{
    film_t a, b, c;
    
    malloc_film(&a);
    malloc_film(&b);
    malloc_film(&c);
    
    strcpy(a->name, "a");
    strcpy(a->title, "a");
    a->year = 1;
    
    strcpy(b->name, "b");
    strcpy(b->title, "b");
    b->year = 2;
    
    strcpy(c->name, "c");
    strcpy(c->title, "c");
    c->year = 3;
    
    films_t films = NULL;
    size_t count = 0;
    size_t position;
    
    int (*cmp)(film_t, film_t);
    film_cmp_film_func(&cmp, YEAR);
    
    insert_film_sorted(a, &films, &count, cmp);
    insert_film_sorted(b, &films, &count, cmp);
    insert_film_sorted(c, &films, &count, cmp);

    int return_code = find_film(YEAR, "3", &position, films, count);

    ck_assert_int_eq(return_code, EXIT_SUCCESS);
    ck_assert_int_eq(position, 2);
    
    free_films(films, count);
}
END_TEST

START_TEST(find_film_no_exist)
{
    film_t a, b, c;
    
    malloc_film(&a);
    malloc_film(&b);
    malloc_film(&c);
    
    strcpy(a->name, "a");
    strcpy(a->title, "a");
    a->year = 1;
    
    strcpy(b->name, "b");
    strcpy(b->title, "b");
    b->year = 2;
    
    strcpy(c->name, "c");
    strcpy(c->title, "c");
    c->year = 3;
    
    films_t films = NULL;
    size_t count = 0;
    size_t position;
    
    int (*cmp)(film_t, film_t);
    film_cmp_film_func(&cmp, YEAR);
    
    insert_film_sorted(a, &films, &count, cmp);
    insert_film_sorted(b, &films, &count, cmp);
    insert_film_sorted(c, &films, &count, cmp);

    int return_code = find_film(YEAR, "4", &position, films, count);

    ck_assert_int_eq(return_code, NOT_FOUND_ERROR_CODE);
    
    free_films(films, count);
}
END_TEST

Suite *find_film_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("find_film");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, find_film_start);
    tcase_add_test(tc_core, find_film_middle);
    tcase_add_test(tc_core, find_film_end);
    tcase_add_test(tc_core, find_film_no_exist);
    suite_add_tcase(s, tc_core);
    return s;
}
