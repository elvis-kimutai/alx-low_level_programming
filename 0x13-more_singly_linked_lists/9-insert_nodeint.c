#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node to a listint_t
 *                           list at a given position.
 * @head: A pointer to the address of the head
 *	of the listint_t list.
 * @idx: The index of the listint_t list where the new
 *       node should be added - indices start at 0.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the new node.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *ins = *head;
	unsigned int a;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = ins;
		*head = new;
		return (new);
	}

	for (a = 0; a < (idx - 1); a++)
	{
		if (ins == NULL || ins->next == NULL)
			return (NULL);

		ins = ins->next;
	}

	new->next = ins->next;
	ins->next = new;

	return (new);
}
