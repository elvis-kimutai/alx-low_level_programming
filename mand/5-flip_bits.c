#include "main.h"

/**
 * flip_bits - returns the number of bits needed to flip
 * to get from one number to another
 *
 * @n: the number
 * @m: the no to flip n to
 * Return: the number of bits to flip from n to m
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int f = n ^ m;
	unsigned int l = 0;

	while (f)
	{
		l += f & 1;
		f >>= 1;
	}

	return (l);
}
