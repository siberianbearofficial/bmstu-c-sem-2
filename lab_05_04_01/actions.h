#ifndef ACTIONS_H
#define ACTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "binary_files.h"
#include "logic.h"
#include "constants.h"

int process(int argc, char **argv);

int print(const char *path);

int sort(const char *path);

int filter(const char *src, const char *dst, const char *substr);

int delete(const char *path);

#endif //ACTIONS_H
