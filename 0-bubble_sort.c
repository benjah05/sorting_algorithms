#include "sort.h"
/**
 * bubble_sort - use bubble sort algorithm to sort numbers
 * in ascending order
 * @array: the array of numbers
 * @size: the size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	bool swap;

	for (i = 0; i < size; i++)
	{
		swap = false;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swap = true;
				print_array(array, size);
			}
		}
		if (!swap)
			return;
	}
}
