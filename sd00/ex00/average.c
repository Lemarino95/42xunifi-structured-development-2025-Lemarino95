#include "average.h"

// A function that takes an array of integers and its size, and returns the average as
//  a float. The elements must be in range 0-100 inclusive and will be
//  ignored if invalid.
float average(const int *arr, int size)
{
	int 	i = 0;
	int		sum = 0;
	float 	average = 0;

	while (i < size){
		if (arr[i] >= 0 && arr[i] <= 100){
			sum += arr[i];
		}
		i++;
	}

	average = (float)sum / (float)size;
	return (average);
}

// int main()
// {
// 	int			size = 6;
// 	const int	array[6] = {1, 466, 6, 88, 30, 724};

// 	printf(BRCYAN"average = %f\n"NO_ALL, average(array, size));
// }
