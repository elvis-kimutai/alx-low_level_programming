#include "main.h"

/**
 * print_alphabet -Entry point
 *
 * Descreption: prints alphabet in lowercase
 * Return: void
 */

void print_alphabet(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
		_putchar(i);
	_putchar('\n');
}
