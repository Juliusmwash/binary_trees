#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: root node of a binary tree.
 * Return: height of a binary tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int leftHeight = 0, rightHeight = 0;
	binary_tree_t *tmp, *tmp2;

	if (tree == NULL)
		return (0);
	tmp = tree->left;
	tmp2 = tree->right;
	leftHeight = binary_tree_height(tree->left);
	rightHeight = binary_tree_height(tree->right);
	if (leftHeight > rightHeight)
	{
		if (tmp == NULL)
			return (leftHeight);
		return (leftHeight + 1);
	}

	if (tmp2 == NULL)
		return (rightHeight);
	return (rightHeight + 1);
}
