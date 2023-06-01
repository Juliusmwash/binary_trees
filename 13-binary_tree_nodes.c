#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the leaves in a binary tree.
 * @tree: binary tree root node.
 * Return: number of nodes with at least one child in a binary tree.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		count++;

	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);
	return (count);
}
