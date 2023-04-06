#include "lists.h"

/**
 * list_len - Finds the number of elements.
 * @h: The linked list_t list.
 *
 * Return: The number of elements in h.
 */
size_t list_len(const list_t *h)
{
	int element = 0;

	while (h != NULL)
	{
		element++;
		h = h->next;
	}

	return (element);
}
