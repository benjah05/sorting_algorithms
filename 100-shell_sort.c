#include "sort.h"
/**
 * shell_sort -  sort using  shell sort with the knuth sequence
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, h = 1;
	int tmp;

	while (h < size / 3)
		h = 3 * h + 1;
	while (h >= 1)
	{
		for (i = h; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= h && array[j - h] > tmp)
			{
				array[j] = array[j - h];
				j -= h;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		h = (h - 1) / 3;
	}

}
