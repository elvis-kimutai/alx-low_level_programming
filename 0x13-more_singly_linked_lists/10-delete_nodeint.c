#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node.
 *
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 * @index: The index of the node to be deleted.
 *
 * Return: On success - 1.
 *         On error - -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *ind, *delete = *head;
	unsigned int node;

	if (delete == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(delete);
		return (1);
	}

	for (node = 0; node < (index - 1); node++)
	{
		if (delete->next == NULL)
			return (-1);

		delete = delete->next;
	}

	ind = delete->next;
	delete->next = ind->next;
	free(ind);
	return (1);
}
