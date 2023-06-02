#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a given node in a binary tree.
 * @node: node in a binary tree to find uncle for.
 * Return: pointer to the uncle node if found, otherwise null.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	else if (node->parent->parent->right == node->parent)
		return (node->parent->parent->left);
	return (NULL);
}
