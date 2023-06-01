#include "binary_trees.h"

/**
 * binary_tree_balance - checks the balance of a binary tree.
 * @tree: node of a binary tree to check balance for.
 * Return: 2 if balanced, -1 if one side unbalanced and otherwise 0.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else if (tree->left && tree->right)
		return (2);
	else if (!tree->left && !tree->right)
		return (0);
	else
		return (-1);
}
