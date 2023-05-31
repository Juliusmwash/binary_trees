#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using
 * pre-order traversal.
 * @tree: pointer to the root of the binary tree.
 * @func: function which is being passed the node's value.
 * Return: Nothing.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
