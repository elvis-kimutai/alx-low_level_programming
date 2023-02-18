#include <stdio.h>
#include <time.h>

/**
 * main -Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int k;

	for (k = '0'; k <= '9' ; k++)
	{
		putchar(k);

		if (k != '9')
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');
	return (0);
}
