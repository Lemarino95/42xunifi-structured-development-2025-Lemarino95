#ifndef FIRST_LAST_H
# define FIRST_LAST_H

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

// A function that receives An array of integers, its size, and a target integer,
//  and computes the first and last occurrence of Target in Arr[], or sets them at -1
//  if it doesn't appear.
void first_last(int arr[], int size, int target, int *first, int *last);

#endif
