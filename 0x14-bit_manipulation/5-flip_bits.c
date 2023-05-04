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
	unsigned long int k = n ^ m;
	unsigned int e = 0;

	while (k)
	{
		e += k & 1;
		k >>= 1;
	}

	return (e);
}
