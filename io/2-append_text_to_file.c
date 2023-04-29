#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: a pointer to filename
 * @text_content: the string to add at the end of the file
 *
 * Return: if the function fails or filename is NULL - -1
 * (or of the file lacks wrote permissions)
 * otherwise - 1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, l);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
