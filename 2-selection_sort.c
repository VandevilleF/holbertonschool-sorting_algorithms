#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, i_min;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		i_min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i_min])
				i_min = j;
		}

		if (i_min != i)
		{
			temp = array[i];
			array[i] = array[i_min];
			array[i_min] = temp;
			print_array(array, size);
		}
	}
}
