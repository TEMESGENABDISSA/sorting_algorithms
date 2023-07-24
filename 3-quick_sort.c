#include "sort.h"

/**
 * swap - swap two the  integer
 * @a: integer
 * @b: integer
 * Return: Swaped int or void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Partition an array and using pivot
 * @array:the  Array
 * @low:the integer
 * @high:the integer
 * @size: the size of array 
 * Return: the index of pivote 
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}
/**
 * lomuto_qsort - Sort the  Recursively the  Array
 * @array:the  Array to be sorted
 * @low: The lowest value of Arr
 * @high: highest value of the ARR
 * @size: Size of The Array
 * Return: void or return nothing
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		lomuto_qsort(array, low, i - 1, size);
		lomuto_qsort(array, i + 1, high, size);
	}
}
/**
 * quick_sort - Quick Sort Algorithme using lomuto partition
 * @array: the Array to sort
 * @size:the Size of  Array
 * Return:the  Sorted Arr
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
