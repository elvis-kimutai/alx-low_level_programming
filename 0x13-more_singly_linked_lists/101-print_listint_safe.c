#include "lists.h"
#include <stdio.h>
/**
 *  print_listint_safe - a function that prints a listint_t linked list
 * @head: Pointer to pointer of first node of linked list.
 *
 * Return: Pointer to the first node of the reversed list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t no_nodes = 0; /* the number of nodes */
	long int a;

	while (head)
	{
		a = head - head->next;
		no_nodes++;

		printf("[%p] %d\n", (void *)head, head->n);
		if (a > 0)
			head = head->next;

		else
		{
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			break;
		}
	}

	return (no_nodes);
}
