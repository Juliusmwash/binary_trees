#include "binary_trees.h"

/**
 * binary_tree_depth - mrasures the depth of a node from
 * the root of a binary tree.
 * @tree: node to find depth for.
 * Return: Nothing.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return (tree && tree->parent ? 1 + binary_tree_depth(tree->parent) : 0);
}
