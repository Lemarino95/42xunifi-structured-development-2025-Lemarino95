#ifndef SEGMENTED_RUNS_H
# define SEGMENTED_RUNS_H

#include <stdio.h>


// Returns the number of segments from the array of integers arr[] containing at least
//  one increasing sequence of length 3 or more (strictly increasing consecutive numbers).
// Segment are marked by a special sentinel value ‘-1‘ (which is not part of any segment).
int count_segments(const int *arr, int size);

#endif
