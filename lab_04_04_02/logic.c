#include "logic.h"

char get_year(const char *, int *);

char get_day(const char *, int *);

char append_word(const char *, string_array, int *);

char append_word(const char *word, string_array array, int *n)
{
    char exit_code = EXIT_SUCCESS;
    int i;
    for (i = 0; word[i] && i < W_LEN; i++)
        array[*n][i] = word[i];
    if (i < (W_LEN - 1))
    {
        array[*n][i] = '\0';
        (*n)++;
        exit_code |= word[i];
    }
    return exit_code;
}

char split_string(char *str, string_array words, int *words_count)
{
    *words_count = 0;
    const char *delim = " \n";
    if (strrchr(str, '\n'))
    {
        char *token = strtok(str, delim);
        do
            if (!append_word(token, words, words_count))
                token = strtok(NULL, delim);
        while (token);
    }
    return (char) (*words_count <= 0);
}

int days_in_month(int, int);

int is_leap_year(int);

int is_leap_year(int year)
{
    return !(year % 4) && (!(year % 400) || (year % 100));
}

int days_in_month(int month, int year)
{
    return 28 + (month + month / 8) % 2 + 2 % month + 2 * 1 / month - (!is_leap_year(year) && month == 2);
}

int valid_day(int day, int month, int year)
{
    return day > 0 && day <= days_in_month(month, year);
}

int valid_year(int year)
{
    return year > 0;
}

int get_month(const char *month_str)
{
    int month = 0;
    if (!strcmp(month_str, "january"))
        month = 1;
    else if (!strcmp(month_str, "february"))
        month = 2;
    else if (!strcmp(month_str, "march"))
        month = 3;
    else if (!strcmp(month_str, "april"))
        month = 4;
    else if (!strcmp(month_str, "may"))
        month = 5;
    else if (!strcmp(month_str, "june"))
        month = 6;
    else if (!strcmp(month_str, "july"))
        month = 7;
    else if (!strcmp(month_str, "august"))
        month = 8;
    else if (!strcmp(month_str, "september"))
        month = 9;
    else if (!strcmp(month_str, "october"))
        month = 10;
    else if (!strcmp(month_str, "november"))
        month = 11;
    else if (!strcmp(month_str, "december"))
        month = 12;
    return month;
}

char get_year(const char *str_year, int *year)
{
    char exit_code = EXIT_SUCCESS;
    for (int i = 0; str_year[i] && !exit_code; i++)
        exit_code = !isdigit(str_year[i]);
    if (!exit_code)
        *year = atoi(str_year);
    return exit_code;
}

char get_day(const char *str_day, int *day)
{
    char exit_code = EXIT_SUCCESS;
    for (int i = 0; str_day[i] && !exit_code; i++)
        exit_code = !isdigit(str_day[i]);
    if (!exit_code)
        *day = atoi(str_day);
    return exit_code;
}

char valid_data(string_array data, int data_len)
{
    char exit_code = EXIT_FAILURE;
    if (data_len == 3)
    {
        int year;
        if (!get_year(data[2], &year))
        {
            if (valid_year(year))
            {
                int month;
                if ((month = get_month(data[1])))
                {
                    int day;
                    if (!get_day(data[0], &day))
                        if (valid_day(day, month, year))
                            exit_code = EXIT_SUCCESS;
                }
            }
        }
    }
    return exit_code;
}
