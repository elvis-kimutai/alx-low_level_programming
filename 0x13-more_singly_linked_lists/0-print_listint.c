#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all the elements in the listint_t list.
 * @h: pointer of the head of the list_t list.
 *
 * Return: The number of nodes in the list_t list.
 *
 */

size_t print_listint(const listint_t *h)
{
	size_t no_nodes = 0;

	while (h)
	{
		no_nodes++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (no_nodes);
}
