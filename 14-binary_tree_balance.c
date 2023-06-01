#include "binary_trees.h"
int binary_tree_height2(const binary_tree_t *tree);

/**
 * binary_tree_balance - checks the balance of a binary tree.
 * @tree: root node of a binary tree.
 * Return: 0 if balanced, positive(+) number if the left side is
 * greater than the right side and negative(-) number if the right
 * side is greater than the left side.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height2(tree->left) -
			 binary_tree_height2(tree->right));
}

/**
 * binary_tree_height2 - finds the biggest height between the root node's
 * children heights of a binary tree.
 * @tree: root node of a binary tree.
 * Return: the measured height.
 */

int binary_tree_height2(const binary_tree_t *tree)
{
	int leftHeight, rightHeight;

	if (tree == NULL)
		return (0);

	leftHeight = binary_tree_height2(tree->left);
	rightHeight = binary_tree_height2(tree->right);

	return ((leftHeight > rightHeight ? leftHeight : rightHeight) + 1);
}
