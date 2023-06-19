#include "main.h"
#include <string.h>
/**
 * _memset - copies a single character for a specified no of times
 * @s: pointer to the block of memory to fill
 * @b: value to be set
 * @n: Number of bytes to be set to the value
 *
 * Return: Returns a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	memset(s, b, n);
	return (s);
}
