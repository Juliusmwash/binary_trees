#include "binary_trees.h"
#include <limits.h>

/**
 * helper - recursively checks if bst is valid.
 * @tree: pointer to root node of the binary tree.
 * @min: minimum value.
 * @max: maximum value.
 * Return: 1 if true. Otherwise 0.
 */

int helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);
	return (helper(tree->left, min, tree->n) &&
		helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - call the helper function which recursively
 * checks if bst is valid.
 * @tree: pointer to the root node of the binary tree.
 * Return: 1 if true. Otherwise 0.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (helper(tree, INT_MIN, INT_MAX));
}
