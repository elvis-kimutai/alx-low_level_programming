#include "main.h"
#include <stdio.h>
#include <ctype.h>
/**
 * _isupper - Afunction checking for uppercase characters
 * @c: Character input checked if is upper
 *
 * Return: returns 1 if c is uppercase and 0 if c is lowercase
 */
int _isupper(int c)
{
	if (isupper(c))
		return (1);
	else
		return (0);
}
