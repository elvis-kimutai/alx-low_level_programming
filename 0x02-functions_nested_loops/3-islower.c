#include "main.h"

/**
 * _islower -Entry point
 * Descreption: checks lowercase characters
 * @c: the integer value it receives
 *
 * Return: 0 false 1 true
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
