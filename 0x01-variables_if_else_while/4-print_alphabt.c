#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Description: prints lowercase alphabets exept q and e
 * Return: Always 0
 */
int main(void)
{
	char k;

	for (k = 'a' ; k <= 'z' ; k++)
		if (k != 'q' && k != 'e')
			putchar(k);
	putchar('\n');
	return (0);
}
