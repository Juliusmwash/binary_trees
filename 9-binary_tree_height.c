#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: root node of a binary tree.
 * Return: height of a binary tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int leftHeight = 0, rightHeight = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		leftHeight = 1 + binary_tree_height(tree->left);
	else
		leftHeight = 0;
	if (tree->right)
		rightHeight = 1 + binary_tree_height(tree->right);
	else
		rightHeight = 0;

	if (leftHeight > rightHeight)
		return (leftHeight);

	return (rightHeight);
}
