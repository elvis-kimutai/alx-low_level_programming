#include "main.h"

/*
 * get_endiannes - checks the endiannes
 * desc: checks the ediannes
 *
 * return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	int e = 1;
	char *endian = (char *)&e;

	if (*endian == 1)
		return (1);

	return (0);
}
