#ifndef C_BINSEARCH_H
#define C_BINSEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// OS X
#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

int binsearch_middle_calc(int *arr, size_t size, int num);

#endif // C_BINSEARCH_H
