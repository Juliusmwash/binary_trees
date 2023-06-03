#include "binary_trees.h"

/**
 * bst_search - recursively searches for a value in a bst.
 * @tree: pointer to the root node of a bst.
 * @value: value to look for in bst.
 * Return: node containing the value or null if not found.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	/*bst_t *tmp, *tmp2;*/

	if (tree)
	{
		if (value == tree->n)
			return ((bst_t *) tree);
		if (value > tree->n)
			return (bst_search(tree->right, value));
		return (bst_search(tree->left, value));
	}
	return (NULL);
}
