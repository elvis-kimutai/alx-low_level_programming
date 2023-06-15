#include "lists.h"

/**
 * print_dlistint - prints elemets of a doubly linked list
 * @h: pointer to the head node
 * Return: The number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t index = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		index++;
	}
	return (index);
}
