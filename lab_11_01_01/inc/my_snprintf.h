#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

#include <stdlib.h>

/* Maximum chars of output to write in N.  */
extern int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...);

#endif //MY_SNPRINTF_H
