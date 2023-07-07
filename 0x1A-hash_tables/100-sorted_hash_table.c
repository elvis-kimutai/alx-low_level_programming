#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the new sorted hash table
 * Return: if an error occurs - NULL.
 *         otherwise - a pointer to the new sorted hash table.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *htb;
	unsigned long int i;

	htb = malloc(sizeof(shash_table_t));
	if (htb == NULL)
		return (NULL);

	htb->size = size;
	htb->array = malloc(sizeof(shash_node_t *) * size);
	if (htb->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		htb->array[i] = NULL;
	htb->shead = NULL;
	htb->stail = NULL;

	return (htb);
}

/**
 * shash_table_set - adds an element to hash table
 * @ht: pointer to the sorted hash table
 * @key: key to add - cannot be an empty
 * @value: The value associated with key.
 *
 * Return: upon failure - 0.
 *         otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copy);
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - retrieve the value associated with a key
 * @ht: A pointer to the sorted hash table
 * @key: key to get the value of.
 *
 * Return: if not matched - NULL.
 *         otherwise - value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *anode;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	anode = ht->shead;
	while (anode != NULL && strcmp(anode->key, key) != 0)
		anode = anode->snext;

	return ((anode == NULL) ? NULL : anode->value);
}

/**
 * shash_table_print - print a hash table in order
 *
 * @ht: pointer to the sorted hash table.
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *anode;

	if (ht == NULL)
		return;

	anode = ht->shead;
	printf("{");
	while (anode != NULL)
	{
		printf("'%s': '%s'", anode->key, anode->value);
		anode = anode->snext;
		if (anode != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse order
 *
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *anode;

	if (ht == NULL)
		return;

	anode = ht->stail;
	printf("{");
	while (anode != NULL)
	{
		printf("'%s': '%s'", anode->key, anode->value);
		anode = anode->sprev;
		if (anode != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - delete sorted hash table
 *
 * @ht: A pointer to the sorted hash table
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *tm;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		tm = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tm;
	}

	free(head->array);
	free(head);
}
