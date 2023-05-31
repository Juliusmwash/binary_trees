#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: root node of a binary tree.
 * Return: height of a binary tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int leftHeight, rightHeight;

	if (tree == NULL)
		return (-1);
	else
	{
		leftHeight = binary_tree_height(tree->left);
		rightHeight = binary_tree_height(tree->right);
		if (leftHeight > rightHeight)
			return leftHeight + 1;
		else
			return rightHeight + 1;
	}
}
