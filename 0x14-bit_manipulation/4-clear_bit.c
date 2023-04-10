#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0
 * @n: A pointer to the bit
 * @index: the index starting from 0
 * Return: success 1, error -1;
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}

	*n &= ~(1UL << index);

	return (1);
}
