/*--------------------------------------------------\\
||                                                  ||
||         Written by:  lemarino                    ||
||                                                  ||
\\--------------------------------------------------*/

#include "critical_windows.h"

// Verifies wether the windows cointains at least
//  3 values above or equal 70.
// If so, returns "true".
static bool	minimum_readings(const int *readings, int i)
{
	int end = i + 4;
	int count = 0;

	while (i <= end && count < 3)
	{
		if (readings[i] >= 70)
			count += 1;
		i++;
	}
	if (count == 3)
		return (true);
	return (false);
}

// Verifies wether the windows cointains only values below 150.
// If not, returns "false".
static bool	max_reading(const int *readings, int i)
{
	int end = i + 4;

	while (i <= end)
	{
		if (readings[i] > 150)
			return (false);
		i++;
	}
	return (true);
}

// Verifies that the average value of the window is equal or above 90.
// If so, returns "true".
static bool	compute_average(const int *readings, int i)
{
	int end = i + 4;
	int	sum = 0;
	int average = 0;

	while (i <= end)
	{
		sum += readings[i];
		i++;
	}
	average = sum / 5;

	if (average >= 90)
		return (true);
	
	return (false);
}

// A function that takes an array of daily seismic tremor readings and its size,
//  and returns how many critical windows occurred.
// A critical window is any 5 day period that meets all the following conditions:
// • At least 3 of the 5 days had readings ≥ 70 .
// • No reading exceeded 150 .
// • The average of the 5 values is ≥ 90 .
int count_critical_windows(const int *readings, int size)
{
	int i = 0;
	int n_windows = 0;

	if (size < 5)
		return (0);
	while (i < size - 4)
	{
		if (minimum_readings(readings, i) && \
				max_reading(readings, i) && \
				compute_average(readings, i))
		{
			n_windows++;
		}
		i++;
	}
	return (n_windows);
}
