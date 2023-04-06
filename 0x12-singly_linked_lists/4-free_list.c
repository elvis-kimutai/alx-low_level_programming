#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * free_list - Frees a list_t list.
 * @head: A pointer to the list_t list.
 */

void free_list(list_t *head)
{
	list_t *kim;

	while (head != NULL)
	{
		kim = head->next;
		free(head->str);
		free(head);
		head = kim;
	}
}
