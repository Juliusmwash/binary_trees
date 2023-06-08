#include "binary_trees.h"

/**
 * array_to_avl - makes an avl tree from an array.
 * @array: pointer to the first element of an array.
 * @size: size of an array.
 * Return: pointer to the root node of an avl tree.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t i = 0;

	tree = NULL;
	while (i < size)
	{
		avl_insert(&tree, array[i]);
		i++;
	}
	return (tree);
}
