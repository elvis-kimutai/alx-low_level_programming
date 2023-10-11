#include "search_algos.h"
#include  <math.h>

/**
 * jump_search - searches for a value in a sorted array of integers
 * @array: array to look into
 * @size: size of the array
 * @value: value to search
 *
 * Return: index of the value found, or -1 if not found
 */

int jump_search(int *array, size_t size, int value)
{
	size_t i, jumpstep, previndex;

	if (array == NULL || size == 0)
		return (-1);

	/* Handle invalid input */
	jumpstep = sqrt(size);
	for (i = previndex = 0; previndex < size && array[previndex] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", previndex, array[previndex]);
		i = previndex;
		previndex += jumpstep;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, previndex);

	previndex = previndex < size - 1 ? previndex : size - 1;
	for (; i < previndex && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
