#include "sort.h"
void swap(int *a, int *b);
int partition(int *array, size_t size, int low, int high);
void quick_sort_helper(int *array, size_t size, int low, int high);
/**
 * swap - swap element
 * @a: first element
 * @b: second element
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - partition for the new quicksort
 * @array: pointer to the array
 * @size: size of the array
 * @low: starting index of current subarray
 * @high: ending index of cuurent subarray
 * Return: void
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high], i, j;

	for (i = j = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			if (j < i)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			j++;
		}
	}
	if (array[j] > pivot)
	{
		swap(&array[j], &array[high]);
		print_array(array, size);
	}
	return (j);
}
/**
 * quick_sort_recursion - quick_sort helper for multiple partitions
 * @array: pointer to the array
 * @size: size of the array
 * @low: starting index of current subarray
 * @high: ending index of current subbarray
 * Return: void
 */
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
	int pi; /*pivot*/

	if (low < high)
	{
		pi = partition(array, size, low, high);
		/*Recursively sort elements before and after partition*/
		quick_sort_recursion(array, size, low, pi - 1);
		quick_sort_recursion(array, size, pi + 1, high);
	}
}
/**
 * quick_sort - sort an array of integers in asc using quicksort
 * @array: pointer to the array
 * @size: size  of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, size, 0, size - 1);
}
