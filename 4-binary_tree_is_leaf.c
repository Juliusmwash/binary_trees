#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if node is a leaf or not.
 * @node: node to check
 * Return: 1 if node is a leaf and 0 otherwise.
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left || node->right)
		return (0);
	return (1);
}
