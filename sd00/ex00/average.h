#ifndef AVERAGE_H
# define AVERAGE_H

#include <stdio.h>
#include <float.h>

# define NO_ALL "\033[0m"
# define NO_COLOR "\e[39m"
# define BLACK "\e[30m"
# define RED "\033[31m"
# define GREEN "\e[32m"
# define BRGREEN "\033[32;1m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[95m"
# define BRCYAN "\033[96m"

// A function that takes an array of integers and its size, and returns the average as
//  a float. The elements must be in range 0-100 inclusive and will be
//  ignored if invalid.
float average(const int *arr, int size);

#endif
