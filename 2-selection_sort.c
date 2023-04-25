#include "sort.h"

/**
 * selection_sort -  function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: unsorted array
 * @size: size of array
*/

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;
	size_t idx_min;

	while (i < (size - 1))
	{
		idx_min = i;
		j = i + 1;

		while (j < size)
		{
			if (array[j] < array[idx_min])
			{
				idx_min = j;
			}
			j++;
		}

		if (idx_min != i)
		{
			array[i] += array[idx_min];
			array[idx_min] =  array[i] - array[idx_min];
			array[i] = array[i] - array[idx_min];
			print_array(array, size); 
		}
		i++;
	}
}
