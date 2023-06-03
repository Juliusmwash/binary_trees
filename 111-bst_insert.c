#include "binary_trees.h"

/**
 * bst_insert_helper - inserts the node at the suppossed location.
 * @tree: double pointer to the root node of a binary search tree.
 * @newNode: node to insert in a binary search tree
 * @check: 0 if value not in bst.Otherwise adjusted
 *to 1 if value exist in bst
 * Return: pointer to the root node of a binary search tree.
 */

bst_t *bst_insert_helper(bst_t **tree, bst_t *newNode, int *check)
{
	if (!(*tree))
	{
		*tree = newNode;
		return (*tree);
	}
	else if (newNode->n < (*tree)->n)
	{
		if ((*tree)->left)
			bst_insert_helper(&(*tree)->left, newNode, check);
		else
		{
			newNode->parent = (*tree);
			(*tree)->left = newNode;
		}
	}
	else if (newNode->n > (*tree)->n)
	{
		if ((*tree)->right)
			bst_insert_helper(&(*tree)->right, newNode, check);
		else
		{
			newNode->parent = (*tree);
			(*tree)->right = newNode;
		}
	}
	else
	{
		*check = 1;
		return (NULL);
	}
	return (newNode);
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
	int check = 0;

	newNode = binary_tree_node(NULL, value);
	if (!newNode)
		return (NULL);
	bst_insert_helper(tree, newNode, &check);
	if (check)
	{
		free(newNode);
		return (NULL);
	}
	return (newNode);
}
