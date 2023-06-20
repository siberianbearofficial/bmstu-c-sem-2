#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constants.h"

int process(int argc, char **argv, double *nearest_value);

int average(FILE *fin, double *av);

int nearest(FILE *fin, double value, double *nearest_value);

#endif //LOGIC_H
