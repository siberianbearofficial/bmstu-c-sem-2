#include "my_string.h"

char *my_strpbrk(const char *s, const char *accept)
{
    char *pos = NULL;
    for (int i = 0; s[i] && !pos; i++)
        for (int j = 0; accept[j] && !pos; j++)
            if (s[i] == accept[j])
                pos = (char *) (s + i);
    return pos;
}

size_t my_strspn(const char *s, const char *accept)
{
    size_t n;
    int sym_in_accept = 0;
    for (n = 0; s[n] && !sym_in_accept; n++)
    {
        sym_in_accept = 1;
        for (size_t j = 0; accept[j] && sym_in_accept; j++)
            sym_in_accept = s[n] != accept[j];
    }
    return n - sym_in_accept;
}

size_t my_strcspn(const char *s, const char *reject)
{
    size_t n;
    int sym_in_reject = 0;
    for (n = 0; s[n] && !sym_in_reject; n++)
        for (size_t j = 0; reject[j] && !sym_in_reject; j++)
            sym_in_reject = s[n] == reject[j];
    return n - sym_in_reject;
}

char *my_strchr(const char *s, int c)
{
    char *pos = NULL;
    int i;
    for (i = 0; s[i] && !pos; i++)
        if (s[i] == c)
            pos = (char *) (s + i);
    if (c == '\0')
        pos = (char *) (s + i);
    return pos;
}

char *my_strrchr(const char *s, int c)
{
    char *pos = NULL;
    int i;
    for (i = 0; s[i]; i++)
        if (s[i] == c)
            pos = (char *) (s + i);
    if (c == '\0')
        pos = (char *) (s + i);
    return pos;
}
