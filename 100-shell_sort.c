#include "sort.h"

/**
 * swap - Perform swaps of array elements
 * 
 * @array: array of integers
 * @x: First element
 * @y: Second element 
 */

void swap(int array[], int x, int y)
{
	int tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * 
 * @array: The array input to be sorted
 * @size: Size of the array
 */

void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j;

	while(gap < size)
		gap = gap * 3 + 1;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i - gap; j >= 0 ; j -= gap)
			{
				if (array[j] > array[j + gap])
					swap(array, j, j + gap);
				else
					break;
			}
		}
		print_array(array, size);
	}
}