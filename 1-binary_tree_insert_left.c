#include "binary_trees.h"

/**
 * binary_tree_insert_left - adds a node to the left side of
 * the parent.
 * @parent: pointer to the parent of the newly created node.
 * @value: value to add to the n variable of the created node.
 * Return: newly created node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(parent, value);
	if (newNode == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		newNode->left = parent->left;
		parent->left->parent = newNode;
	}

	parent->left = newNode;

	return (newNode);
}
