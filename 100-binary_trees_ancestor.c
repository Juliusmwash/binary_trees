#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: first node of a binary tree.
 * @second: second node of a binary tree.
 * Return: found ancestor or null if not found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *node1, *node2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	node1 = first->parent;
	node2 = second->parent;
	if (first == node2 || !node1 || (!node1->parent && node2))
		return (binary_trees_ancestor(first, node2));
	else if (node1 == second || !node2 || (!node2->parent && node1))
		return (binary_trees_ancestor(node1, second));
	return (binary_trees_ancestor(node1, node2));
}
