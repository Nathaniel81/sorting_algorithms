#include "sort.h"

void swap(int *x, int *y);
void quick_sort(int *array, size_t size);
void quicksort_recursion(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high);

/**
 * swap - Perform swaps of array elements in quicksort partition
 * 
 * @x: First element
 * @y: Second element
 */

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * 
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{  
  /*srand(time(NULL));*/
  quicksort_recursion(array, 0, size - 1, size);
}

/**
 * quicksort_recursion - applies the recursive divide
 * and conquer portion of the quicksort algorithm
 * 
 * @array: The array to be sorted
 * @low: Low index
 * @high: High index
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
  if (low < high)
  {
    int pivot_index = partition(array, low, high);
    print_array(array, size);
    quicksort_recursion(array, low, pivot_index - 1, size);
    quicksort_recursion(array, pivot_index + 1, high, size);
  }
}

/**
 * partition - randomly select a pivot value between low-high
 * by randomly selecting an index in the range low - high
 * 
 * @array: The array input
 * @low: low index
 * @high: high index
 * Return: The pivot index 
 */
int partition(int *array, int low, int high)
{
  /**
   * if (pivot_index != high)
    swap(&array[pivot_index], &array[high]);
   */

  int pivot_value = array[high];
  
  int i = low; 
  
  for (int j = low; j < high; j++)
  {

    if (array[j] <= pivot_value)
    {
      swap(&array[i], &array[j]);
      i++;
    }
  }
  swap(&array[i], &array[high]);

   return i;
}
