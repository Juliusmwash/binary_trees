#include "binary_trees.h"

/**
 * binary_tree_node - creates binary tree node with left
 * and right pointers set to null.
 * @parent: pointer to the parent of the newly created node.
 * @value: value to add to the n variable of the newly created node.
 * Return: pointer to the created node.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = malloc(sizeof(binary_tree_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}
