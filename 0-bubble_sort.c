#include "sort.h"

/**
*bubble_sort - function that sorts an array of integers in
*ascending order using the Bubble sort algorithm
*@array: array to sort
*@size: array size
*print the array after each time you swap two elements
*/
void bubble_sort(int *array, size_t size)
{
	bool swapped = true;
	int arr_size = size;
	size_t i = 1;

	while (swapped)
	{
		swapped = false;
		i = 1;

		while (i < size)
		{
			if (array[i - 1] > array[i])
			{
				array[i - 1] += array[i];
				array[i] =  array[i - 1] - array[i];
				array[i - 1] = array[i - 1] - array[i];
				print_array(array, arr_size);
				swapped = true;
			}
		i++;
		}
		size -= 1;
	}
}
