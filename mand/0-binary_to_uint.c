#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: pointer to a string.
 *
 * Return: If b is NULL or contains chars not 0 or 1 - 0.
 *	Otherwise - the converted number.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int no = 0;
	int a = 0;

	if (b[a] == '\0')
		return (0);

	while ((b[a] == '0') || (b[a] == '1'))
	{
		no <<= 1;
		no += b[a] - '0';
		a++;
	}

	return (no);
}
