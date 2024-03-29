#include "main.h"
#include <fcntl.h>

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int fdd_r, fdd_w, e, m, n;
	char buf[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fdd_r = open(argv[1], O_RDONLY);
	if (fdd_r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fdd_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((e = read(fdd_r, buf, BUFSIZ)) > 0)
	{
		if (fdd_w < 0 || write(fdd_w, buf, e) != e)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fdd_r);
			exit(99);
		}
	}
	if (e < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	m = close(fdd_r);
	n = close(fdd_w);
	if (m < 0 || n < 0)
	{
		if (m < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdd_r);
		if (n < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdd_w);
		exit(100);
	}
	return (0);
}
