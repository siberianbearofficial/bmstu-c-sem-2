#include "logic.h"

int greater_than(student_struct *student1, student_struct *student2, int *gt);

int startswith(const char *substr, const char *str);

double average(uint32_t *arr);

int greater_than(student_struct *student1, student_struct *student2, int *gt)
{
    int exit_code = EXIT_FAILURE;

    char s_n_1[SURNAME_LEN + NAME_LEN];  // student1: surname + name
    char s_n_2[SURNAME_LEN + NAME_LEN];  // student2: surname + name

    if (sprintf(s_n_1, "%s%s", student1->surname, student1->name) > 0 &&
        sprintf(s_n_2, "%s%s", student2->surname, student2->name) > 0)
    {
        *gt = strcmp(s_n_1, s_n_2);
        exit_code = EXIT_SUCCESS;
    }

    return exit_code;
}

int startswith(const char *substr, const char *str)
{
    return strncmp(substr, str, strlen(substr)) == 0;
}

double average(uint32_t *arr)
{
    return ((double) (arr[0] + arr[1] + arr[2] + arr[3])) / 4;
}

int read_file(FILE *f, int n)
{
    int exit_code = EXIT_SUCCESS;
    for (int i = 0; i < n && !exit_code; i++)
    {
        student_struct student;
        if (!get_student_by_pos(f, i, &student))
            print_student(&student);
        else
            exit_code = EXIT_FAILURE;
    }
    return exit_code;
}

int sort_file(FILE *f, int n)
{
    int exit_code = EXIT_SUCCESS;
    for (int i = 0; i < n - 1 && !exit_code; i++)
    {
        for (int j = i + 1; j < n && !exit_code; j++)
        {
            student_struct student1, student2;
            if (!get_student_by_pos(f, i, &student1) && !get_student_by_pos(f, j, &student2))
            {
                int gt;
                if (!greater_than(&student1, &student2, &gt))
                    exit_code = (gt > 0) && (put_student_by_pos(f, i, &student2) || put_student_by_pos(f, j, &student1));
                else
                    exit_code = EXIT_FAILURE;
            }
            else
                exit_code = EXIT_FAILURE;
        }
    }
    return exit_code;
}

int filter_file(FILE *fin, FILE *fout, const char *substr, int n)
{
    int exit_code = EXIT_SUCCESS;
    int j = 0;
    for (int i = 0; i < n && !exit_code; i++)
    {
        student_struct student;
        if (!get_student_by_pos(fin, i, &student))
            exit_code = startswith(substr, student.surname) && put_student_by_pos(fout, j++, &student);
        else
            exit_code = EXIT_FAILURE;
    }
    return exit_code || !j;
}

int delete_file(FILE *f, int n)
{
    int exit_code = EXIT_SUCCESS;
    double file_av = 0;
    for (int i = 0; i < n && !exit_code; i++)
    {
        student_struct student;
        if (!get_student_by_pos(f, i, &student))
            file_av += average(student.marks);
        else
            exit_code = EXIT_FAILURE;
    }
    exit_code |= (n == 0);
    if (!exit_code)
    {
        file_av /= n;
        int j = 0;
        for (int i = 0; i < n && !exit_code; i++)
        {
            student_struct student;
            if (!get_student_by_pos(f, i, &student))
                exit_code = (average(student.marks) >= file_av) && put_student_by_pos(f, j++, &student);
            else
                exit_code = EXIT_FAILURE;
        }
        if (!exit_code && j)
        {
            cut(f, j);
        }
    }
    return exit_code;
}
