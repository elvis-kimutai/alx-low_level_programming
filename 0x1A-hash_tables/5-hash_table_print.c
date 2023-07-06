#include "hash_tables.h"
/**
 * hash_table_print - prints a hash table.
 * @ht: pointer to the hash table to print.
 * 
 * Return: nothing
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int n;
	hash_node_t *node;
	int hasprinted = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (n = 0; n < ht->size; n++)
	{
		node = ht->array[n];
		while (node != NULL)
		{
			if (hasprinted == 1)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			hasprinted = 1;
			node = node->next;
		}
	}
	printf("}\n");
}
