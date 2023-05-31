#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using
 * pre-order traversal.
 * @tree: pointer to the root of the binary tree.
 * @func: function which is being passed the node's value.
 * Return: Nothing.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
