#include "lists.h"

/**
 * free_listint_safe - a function that frees a listint_t list
 * @h: the datatype pointer of the struct
 *
 * Return: the size of the list that was freed, sets the head to NULL
 */

size_t free_listint_safe(listint_t **h)
{
	size_t freed = 0;
	int a;
	listint_t *tmp;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		a = *h - (*h)->next;
		if (a > 0)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			freed++;
		}
		else
		{
			free(*h);
			*h = NULL;
			freed++;
			break;
		}
	}

	*h = NULL;
	return (freed);
}
