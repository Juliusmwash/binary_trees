#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of the given node.
 * @node: node to find its sibling.
 * Return: pointer to the found sibling or null if none.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);

	return (NULL);
}
