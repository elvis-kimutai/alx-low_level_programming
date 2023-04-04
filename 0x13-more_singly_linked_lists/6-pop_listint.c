#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t list
 *	and returns the head node’s data (n).
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 *
 * Return: If the linked list is empty - return 0.
 *         Otherwise - The head node's data (n).
 */

int pop_listint(listint_t **head)
{
	listint_t *current;
	int kim;

	if (*head == NULL)
		return (0);

	current = *head;
	kim = (*head)->n;
	*head = (*head)->next;

	free(current);

	return (kim);
}
