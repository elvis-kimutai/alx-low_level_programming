#include "lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - Adds a new node.
 * @head: A pointer the head.
 * @str: The string to be added.
 *
 * Return: the address of the new element.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	int index = 0;
	list_t *new, *e;

	while (str[index])
		index++;
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->len = index;
	new->next = NULL;
	if (strdup(str) == NULL)
	{
		free(new);
		return (NULL);
	}
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	else
	{
		e = *head;
		while (e->next != NULL)
			e = e->next;
		e->next = new;
		return (new);
	}
}
