#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>

#include "my_snprintf.h"

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
        i++;
    }
    if (s1[i])
        return 1;
    if (s2[i])
        return -1;
    return 0;
}

void my_strncpy(char *dst, const char *src, size_t len)
{
    size_t i;
    for (i = 0; i < len && src && src[i]; i++)
        dst[i] = src[i];
    dst[i] = '\0';
}

void append_c(char **s, int *len, char c)
{
    char *tmp;
    do
    {
        tmp = realloc(*s, sizeof(char) * (*len + 2));
    }
    while (!tmp);

    *s = tmp;
    *(*s + *len) = c;
    (*len)++;
    *(*s + *len) = '\0';
}

void append_s(char **s, int *len, const char *src)
{
    for (int j = 0; src && src[j]; j++)
        append_c(s, len, src[j]);
}

void clean_s(char **s, int *len)
{
    if (s)
    {
        if (*s)
            free(*s);
        *s = NULL;
    }

    if (len)
        *len = 0;
}

void append_d(char **s, int *len, long long num, unsigned base)
{
    if (num == 0)
    {
        append_c(s, len, '0');
        return;
    }

    int sign = 1;
    if (num < 0)
        sign = -1;

    char *digits = NULL;
    int digits_len = 0;

    while (num)
    {
        append_c(&digits, &digits_len, "0123456789abcdef"[num % base * sign]);
        num /= base;
    }

    for (int i = 0; i < digits_len / 2; i++)
    {
        char digit = digits[i];
        digits[i] = digits[digits_len - i - 1];
        digits[digits_len - i - 1] = digit;
    }

    if (sign == -1)
        append_c(s, len, '-');
    append_s(s, len, digits);

    clean_s(&digits, &digits_len);
}

void append_specified(char **s, int *len, va_list vl, char **specifier, int *specifier_len)
{
    if (!my_strcmp(*specifier, "d") || !my_strcmp(*specifier, "i"))
        append_d(s, len, (long long) va_arg(vl, int), 10);
    else if (!my_strcmp(*specifier, "ld") || !my_strcmp(*specifier, "li"))
        append_d(s, len, (long long) va_arg(vl, long), 10);
    else if (!my_strcmp(*specifier, "hd") || !my_strcmp(*specifier, "hi"))
        append_d(s, len, (long long) ((short) va_arg(vl, int)), 10);
    else if (!my_strcmp(*specifier, "o"))
        append_d(s, len, (long long) va_arg(vl, unsigned), 8);
    else if (!my_strcmp(*specifier, "lo"))
    {
        long unsigned num = va_arg(vl, long unsigned);
        if (num > LONG_MAX)
        {
            append_d(s, len, (long long) (num / 8), 8);
            append_d(s, len, (long long) (num % 8), 8);
        }
        else
            append_d(s, len, (long long) num, 8);
    }
    else if (!my_strcmp(*specifier, "ho"))
        append_d(s, len, (long long) ((short unsigned) va_arg(vl, unsigned)), 8);
    else if (!my_strcmp(*specifier, "x"))
        append_d(s, len, (long long) va_arg(vl, unsigned), 16);
    else if (!my_strcmp(*specifier, "lx"))
    {
        long unsigned num = va_arg(vl, long unsigned);
        if (num > LONG_MAX)
        {
            append_d(s, len, (long long) (num / 16), 16);
            append_d(s, len, (long long) (num % 16), 16);
        }
        else
            append_d(s, len, (long long) num, 16);
    }
    else if (!my_strcmp(*specifier, "hx"))
        append_d(s, len, (long long) ((unsigned short) va_arg(vl, unsigned)), 16);
    else if (!my_strcmp(*specifier, "u"))
        append_d(s, len, (long long) va_arg(vl, unsigned), 10);
    else if (!my_strcmp(*specifier, "lu"))
    {
        long unsigned num = va_arg(vl, long unsigned);
        if (num > LONG_MAX)
        {
            append_d(s, len, (long long) (num / 10), 10);
            append_d(s, len, (long long) (num % 10), 10);
        }
        else
            append_d(s, len, (long long) num, 10);
    }
    else if (!my_strcmp(*specifier, "hu"))
        append_d(s, len, (long long) ((unsigned short) va_arg(vl, unsigned)), 10);
    else if (!my_strcmp(*specifier, "s"))
        append_s(s, len, va_arg(vl, const char *));
    else if (!my_strcmp(*specifier, "c"))
        append_c(s, len, (const char) va_arg(vl, int));
    else
    {
        (void) va_arg(vl, void *);
        append_c(s, len, '%');
        append_s(s, len, *specifier);
    }

    clean_s(specifier, specifier_len);
}

extern int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...)
{
    if (!format)
        return -1;

    va_list vl;
    va_start(vl, format);

    char *buffer = NULL;
    int buffer_len = 0;

    char *specifier = NULL;
    int specifier_len = 0;

    int is_specifier = 0;
    for (int i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            if (is_specifier && specifier_len)
                append_specified(&buffer, &buffer_len, vl, &specifier, &specifier_len);
            else if (is_specifier)
            {
                is_specifier = 0;
                append_c(&buffer, &buffer_len, '%');
            }
            else
                is_specifier = 1;
        }
        else if (!isalpha(format[i]) && is_specifier)
        {
            append_specified(&buffer, &buffer_len, vl, &specifier, &specifier_len);
            is_specifier = 0;
            append_c(&buffer, &buffer_len, format[i]);
        }
        else if (is_specifier)
        {
            append_c(&specifier, &specifier_len, format[i]);
            if (format[i] != 'h' && format[i] != 'l')
            {
                append_specified(&buffer, &buffer_len, vl, &specifier, &specifier_len);
                is_specifier = 0;
            }
        }
        else
            append_c(&buffer, &buffer_len, format[i]);
    }
    if (is_specifier && specifier_len)
        append_specified(&buffer, &buffer_len, vl, &specifier, &specifier_len);
    else if (is_specifier)
        buffer_len = -1;

    if (s)
        my_strncpy(s, buffer, n > 0 ? (n - 1) : 0);

    clean_s(&buffer, NULL);
    clean_s(&specifier, &specifier_len);

    va_end(vl);
    return buffer_len;
}
