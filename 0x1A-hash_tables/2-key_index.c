#include "hash_tables.h"
/**
 * key_index - get the index at which a key pair should
 *             be stored
 * @key: key to get the index of
 * @size: size of the array of the hash table.
 *
 * Return: index of the key
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	hash = hash_djb2(key) % size;
	return (hash);
}
