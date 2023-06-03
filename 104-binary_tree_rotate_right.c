#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: pointer to the root node of a binary tree.
 * Return: pointer to the root node of a rotated binary tree.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp, *tmp2;

	if (!tree || !tree->left)
		return (tree);

	tmp = tree;
	tmp2 = tree->left->right;

	tree = tree->left;
	tree->parent = NULL;
	tree->right = tmp;
	tmp->left =  NULL;
	tmp->parent = tree;

	tree->right->left = tmp2;
	if (tmp2)
		tree->right->left->parent = tree->right;

	return (tree);
}
