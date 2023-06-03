#include "binary_trees.h"

/**
 * bst_insert_helper - inserts the node at the suppossed location.
 * @tree: double pointer to the root node of a binary search tree.
 * @newNode: node to insert in a binary search tree
 * @check: 0 if value not in bst.Otherwise adjusted
 *to 1 if value exist in bst
 * Return: pointer to the root node of a binary search tree.
 */

void arr_bst_insert_helper(bst_t **tree, bst_t *newNode, int *check)
{
	if (!(*tree))
	{
		*tree = newNode;
		return;
	}
	else if (newNode->n < (*tree)->n)
	{
		if ((*tree)->left)
			arr_bst_insert_helper(&(*tree)->left, newNode, check);
		else
		{
			newNode->parent = (*tree);
			(*tree)->left = newNode;
		}
	}
	else if (newNode->n > (*tree)->n)
	{
		if ((*tree)->right)
			arr_bst_insert_helper(&(*tree)->right, newNode, check);
		else
		{
			newNode->parent = (*tree);
			(*tree)->right = newNode;
		}
	}
	else
	{
		*check = 1;
		return;
	}
}

/**
 * array_to_bst - calls the bst_insert_helper which does the insertion.
 * @tree: double pointer to the root node of a binary search tree.
 * @size: size of the array containing values to add to bst.
 * Return: pointer to the root node of a binary search tree.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree, *newNode;
	int check = 0, i = 0;

	while (i < size)
	{
		newNode = binary_tree_node(NULL, array[i]);
		if (!newNode)
			return (NULL);
		arr_bst_insert_helper(&tree, newNode, &check);
		if (check)
			free(newNode);
		i++;
	}
	return (tree);
}
