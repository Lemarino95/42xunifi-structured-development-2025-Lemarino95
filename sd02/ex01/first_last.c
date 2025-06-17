/*--------------------------------------------------\\
||                                                  ||
||         Written by: giusnob and lemarino         ||
||                                                  ||
\\--------------------------------------------------*/

#include "first_last.h"

// A function that receives An array of integers, its size, and a target integer,
//  and computes the first and last occurrence of Target in Arr[], or sets them at -1
//  if it doesn't appear.
void first_last(int arr[], int size, int target, int *first, int *last)
{
	*first = -1;
	*last = -1;
	int i = 0;

	if (size == 0)
		return ;
	while (i < size && arr[i] != target){
		i++;
	}
	if (arr[i] == target){
		*first = i;
	}
	else {
		*first = -1;
	}

	i = size -1;
	while (i >= 0 && arr[i] != target){
		i--;
	}
	if (arr[i] == target){
		*last = i;
	}
	else{
		*last = -1;
	}
}
