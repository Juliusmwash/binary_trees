#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: pointer to the root node of a binary tree.
 * Return: pointer to the root node of a rotated binary tree.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp, *tmp2;

	if (!tree || !tree->right)
		return (tree);

	tmp = tree;
	tmp2 = tree->right->left;

	tree = tree->right;
	tree->parent = NULL;
	tree->left = tmp;
	tmp->right =  NULL;
	tmp->parent = tree;

	tree->left->right = tmp2;
	if (tmp2)
		tree->left->right->parent = tree->left;

	return (tree);
}
