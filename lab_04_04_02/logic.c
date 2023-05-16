#include "logic.h"

int string_to_int(const char *, int *);

int string_to_lower(char *);

int days_in_month(int, int);

int is_leap_year(int);

int valid_day(int, int, int);

int valid_year(int);

int get_month(char *);

int valid_data(string_array, int);

int valid(char *str)
{
    string_array data;
    int data_len;
    return split_string(str, data, &data_len) || valid_data(data, data_len);
}

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

int string_to_lower(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
    return EXIT_SUCCESS;
}

int get_month(char *month_str)
{
    string_to_lower(month_str);
    int month = 0;
    for (int i = 0; i < 12 && !month; i++)
        if (!strcmp(month_str, months_strings[i]))
            month = i + 1;
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
