#ifndef SEGMENTED_RUNS_H
# define SEGMENTED_RUNS_H

#include <stdio.h>

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

// Returns the number of segments from the array of integers arr[] containing at least
//  one increasing sequence of length 3 or more (strictly increasing consecutive numbers).
// Segment are marked by a special sentinel value ‘-1‘ (which is not part of any segment).
int count_segments(const int *arr, int size);

#endif
