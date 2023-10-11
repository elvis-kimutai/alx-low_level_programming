#include "search_algos.h"

/**
 * _binary_search - searches for a value in an array using BS
 * @array: pointer to the array to search
 * @left:  beginnig of an array
 * @right: end of an array
 * @value: value to search for
 * Return: index where the value is created
 */

int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			right = i - 1;
		else
			left = i + 1;
	}

	return (-1);
}

/**
 * exponential_search - searches a value using ES
 * @array: array to search
 * @size: size of the array to search
 * @value: value to search in the array
 * Return: first index where the value is located
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0;
	size_t  right;

	if (array == NULL || size == 0)
		return (-1);
	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i *= 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	right = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);
	return (_binary_search(array, i / 2, right, value));
}
