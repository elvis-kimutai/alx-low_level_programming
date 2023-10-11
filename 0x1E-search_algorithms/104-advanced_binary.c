#include "search_algos.h"

/**
 * advanced_binary_recursive - searches for a value recursively
 * @array: array to search
 * @left: begining of an array/sub-array - index
 * @right: end of an array/subarray = index
 * @value: value of an array to search for
 * Return: index of the found value, -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (advanced_binary_recursive(array, left, i, value));
	return (advanced_binary_recursive(array, i + 1, right, value));
}


/**
 * advanced_binary - searches a value in a sorted arr of ints
 * @array: array to search for the value
 * @size: size of the array to search
 * @value: value to search for
 * Return: index of the searched value
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
