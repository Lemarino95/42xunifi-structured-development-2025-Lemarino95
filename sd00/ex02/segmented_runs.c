#include "segmented_runs.h"

// Returns the number of segments from the array of integers arr[] containing at least
//  one increasing sequence of length 3 or more (strictly increasing consecutive numbers).
// Segment are marked by a special sentinel value ‘-1‘ (which is not part of any segment).
int count_segments(const int *arr, int size)
{
	int i = 0;
	int count = 0;
	int len = 0;

	while (i < size)
	{
		while (i < size && arr[i + 1] == (arr[i] + 1) && arr[i] >= 0 )
		{
			len++;
			i++;
		}
		if ((arr[i + 1] == -1 || i == size - 1) && len >= 2)
			count += 1;
		else
		{
			while (i < size && arr[i] != -1)
				i++;
		}
		if (i < size)
			i++;
		len = 0;
	}
	return (count);
}

/* int	main()
{
	int array[] = {1, 2, 3, -1, 4, -1, -1, 4, 5, 10, 11, 12, 13, -1, 8, 9, 10};
	int size = 17;

	
	printf("count: %d\n", count_segments(array, size));
} */