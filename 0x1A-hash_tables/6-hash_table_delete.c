#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table.
 * @ht: pointer to a hash table
 *
 * Return: Nothing
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *table = ht;
	hash_node_t *node, *tm;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			node = ht->array[i];
			while (node != NULL)
			{
				tm = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tm;
			}
		}
	}
	free(table->array);
	free(table);
}
