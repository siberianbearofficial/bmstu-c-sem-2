#ifndef LAB_04_01_MY_STRING_H
#define LAB_04_01_MY_STRING_H

#include <stdlib.h>

char *my_strpbrk(const char *s, const char *accept);

size_t my_strspn(const char *s, const char *accept);

size_t my_strcspn(const char *s, const char *reject);

char *my_strchr(const char *s, int c);

char *my_strrchr(const char *s, int c);

#endif //LAB_04_01_MY_STRING_H
