#include "sort.h"
/**
 * selection_sort - sort an array using selection sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest_index;
	int tmp;

	for (i = 0; i < size; i++)
	{
		smallest_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_index])
				smallest_index = j;
		}
		if (smallest_index != i)
		{
			tmp = array[smallest_index];
			array[smallest_index] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
