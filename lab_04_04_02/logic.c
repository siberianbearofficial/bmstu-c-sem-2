#include "logic.h"

int string_to_int(const char *, int *);

int days_in_month(int, int);

int is_leap_year(int);

int valid_day(int, int, int);

int valid_year(int);

int get_month(const char *);

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

int string_to_int(const char *str, int *i_str)
{
    char exit_code = EXIT_SUCCESS;
    for (int i = 0; str[i] && !exit_code; i++)
        exit_code = !isdigit(str[i]);
    if (!exit_code)
        *i_str = atoi(str);
    return exit_code;
}

int valid_data(string_array data, int data_len)
{
    char exit_code = EXIT_FAILURE;
    if (data_len == 3)
    {
        int year;
        if (!string_to_int(data[2], &year) && valid_year(year))
        {
            int month = get_month(data[1]);
            if (month)
            {
                int day;
                if (!string_to_int(data[0], &day) && valid_day(day, month, year))
                    exit_code = EXIT_SUCCESS;
            }
        }
    }
    return exit_code;
}
