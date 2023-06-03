#include "binary_trees.h"

/**
 * bst_insert_helper - inserts the node at the suppossed location.
 * @tree: double pointer to the root node of a binary search tree.
 * @newNode: node to insert in a binary search tree
 * Return: pointer to the root node of a binary search tree.
 */

bst_t *bst_insert_helper(bst_t **tree, bst_t *newNode)
{
	if (!(*tree))
	{
		*tree = newNode;
		return (*tree);
	}
	if (newNode->n < (*tree)->n)
	{
		if ((*tree)->left)
			bst_insert_helper(&(*tree)->left, newNode);
		else
		{
			newNode->parent = (*tree);
			(*tree)->left = newNode;
		}
	}
	else if (newNode->n > (*tree)->n)
	{
		if ((*tree)->right)
			bst_insert_helper(&(*tree)->right, newNode);
		else
		{
			newNode->parent = (*tree);
			(*tree)->right = newNode;
		}
	}
	return (*tree);
}

/**
 * bst_insert - calls the bst_insert_helper which does the insertion.
 * @tree: double pointer to the root node of a binary search tree.
 * @value: value to add to the node to be inserted.
 * Return: pointer to the root node of a binary search tree.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *newNode;

	newNode = binary_tree_node(NULL, value);
	if (!newNode)
		return (NULL);
	bst_insert_helper(tree, newNode);
	return (*tree);
}
