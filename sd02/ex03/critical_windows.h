#ifndef CRITICAL_WINDOWS_H
# define CRITICAL_WINDOWS_H

#include <stdio.h>
#include <stdbool.h>

// A function that takes an array of daily seismic tremor readings and its size,
//  and returns how many critical windows occurred.
// A critical window is any 5 day period that meets all the following conditions:
// • At least 3 of the 5 days had readings ≥ 70 .
// • No reading exceeded 150 .
// • The average of the 5 values is ≥ 90 .
int count_critical_windows(const int *readings, int size);

#endif
