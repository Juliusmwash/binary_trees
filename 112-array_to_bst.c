#include "binary_trees.h"

/**
 * array_to_bst - makes a bst from an array.
 * @array: an int array containing values to add to bst.
 * @size: size of the array.
 * Return: pointer to root node of a bst.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t i = 0;

	tree = NULL;
	while (i < size)
	{
		bst_insert(&tree, array[i]);
		i++;
	}
	return (tree);
}
