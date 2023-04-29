#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * @n: A pointer to the bit
 * @index: The index to set the value at 0.
 *
 * Return: If an error occurs  -1.
 *         Otherwise  1.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	else
	{
		*n |= bit;

		return (1);
	}
}
