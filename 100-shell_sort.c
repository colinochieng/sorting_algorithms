#include "sort.h"

/**
 * shell_sort - a function that sorts an array
 * of integers in ascending order using the Shell
 * sort algorithm, using the Knuth sequence
 * @array: an array
 * @size: size of array
*/

void shell_sort(int *array, size_t size)
{
	size_t inter = 1;
	size_t i, j;
	int temp;

	if (!array || size == 0)
		return;

	while (inter < size / 3)
		inter = inter * 3 + 1;

	while (inter > 0)
	{
		for (i = inter; i < size; i++)
		{
			temp = array[i];
			for (j = i; (j > inter - 1) && (array[j - inter] >= temp); j -= inter)
				array[j] = array[j - inter];

			array[j] = temp;
		}

		print_array(array, size);
		inter = (inter - 1) / 3;
	}
}
