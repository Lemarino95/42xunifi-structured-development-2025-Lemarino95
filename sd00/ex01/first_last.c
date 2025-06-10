#include "first_last.h"

// A function that receives An array of integers, its size, and a target integer,
//  and computes the first and last occurrence of Target in Arr[], or sets them at -1
//  if it doesn't appear.
void first_last(int arr[], int size, int target, int *first, int *last)
{
	*first = -1;
	*last = -1;
	int i = 0;

	while (i < size){
		if (arr[i] == target){
			*first = i;
			break;
		}
		i++;
	}

	i = size -1;
	while (i >= 0){
		if (arr[i] == target){
			*last = i;
			break;
		}
		i--;
	}
}

/* int main()
{
	int array[6] = {8, 11, 9, 43, 11, 60};
	int size = 6;
	int target = 43;
	int first = 0;
	int last = 0;

	first_last(array, size, target, &first, &last);
	printf(MAGENTA"First: %d\n"NO_ALL, first);
	printf(YELLOW"Last: %d\n"NO_ALL, last);
	return (0);
} */