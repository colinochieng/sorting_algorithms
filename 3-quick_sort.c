#include "sort.h"

/**
 * lomuto_partition - function that partitions an array around
 * a pivot element using the Lomuto scheme
 * @array: array
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: index of the pivot element
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; /*Choose the last element as the pivot*/
	int i = low - 1; /*Initialize the index of smaller element*/
	int j, temp;

	/*Loop through the array from low to high - 1*/
	for (j = low; j <= high - 1; j++)
	{
		/*If the current element is smaller than or equal to the pivot*/
		if (array[j] <= pivot)
		{
			i++; /*Then Increment the index of smaller element*/
			/*If the index of smaller element is not equal to the current index*/
			if (i != j)
			{
				/*Swap the elements at i and j and print the array*/
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	/*If the index of smaller element plus one is not equal to the high index*/
	if (i + 1 != high)
	{
		/*Swap the pivot element with the element at i + 1 and print the array*/
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: unsorted array
 * @size: size of array
*/
void quick_sort(int *array, size_t size)
	{
	int low = 0; /*Initialize the low index as zero*/
	int high = size - 1; /*Initialize the high index as size - 1*/

	/*Create a stack to store indexes*/
	int *stack = malloc(sizeof(size_t) * size);
	int top = -1; /*Initialize the top of stack as -1*/
	int pivot_index;

	/*If the array is null or has less than two elements, return*/
	if (!array || size < 2)
		return;

	stack[++top] = low; /* Push low to stack*/
	stack[++top] = high; /*Push high to stack*/

	while (top >= 0) /*While stack is not empty*/
	{
		high = stack[top--]; /*Pop high from stack*/
		low = stack[top--]; /*Pop low from stack*/

		/*Partition the array around a pivot and get its index*/
		pivot_index = lomuto_partition(array, low, high, size);

		if (pivot_index - 1 > low) /*If there are elements on left side of pivot*/
		{
			stack[++top] = low; /*Push low to stack*/
			stack[++top] = pivot_index - 1; /*Push pivot_index - 1 to stack*/
		}

		if (pivot_index + 1 < high) /*If there are elements on right side of pivot*/
		{
			stack[++top] = pivot_index + 1; /* Push pivot_index + 1 to stack*/
			stack[++top] = high; /*Push high to stack*/
		}
	}

	free(stack);
}
