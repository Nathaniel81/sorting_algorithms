#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * 				 in ascending order using the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: Size of the array.
 * 
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, tmp, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (i != min_idx)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
