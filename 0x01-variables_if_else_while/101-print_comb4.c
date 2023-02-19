#include <stdio.h>
#include <time.h>

/**
 * main -Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int k, i, m;

	for (k = '0'; k <= '9'; k++)
	{
		for (i = '0'; i <= '9'; i++)
		{
			for (m = '0'; m <= '9'; m++)
			{
				if (k < i && i < m)
				{
					putchar(k);
					putchar(i);
					putchar(m);

					if (k != '7')
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
