#include "binary_trees.h"

bst_t *look_for_successor(bst_t **node)
{
	bst_t *tmp;

	tmp = *node;
	if (tmp)
	{
		while (tmp->left)
			tmp = tmp->left;
	}
	return (tmp);
}

void remove_node_no_successor(bst_t **node)
{
	bst_t *tmp;

	tmp = *node;
	*node = (*node)->left;
	if (tmp->parent->left == tmp)
		tmp->parent->left = *node;
	else
		tmp->parent->right = *node;
	if (*node)
		(*node)->parent = tmp->parent;
	free(tmp);
}

void remove_node_with_successor(bst_t **remNode, bst_t **node, int check)
{
	(*remNode)->n = (*node)->n;
	if (check)
	{
		if ((*node)->right)
			(*node)->right->parent = *remNode;
		(*remNode)->right = (*node)->right;
	}
	else
	{
		if ((*node)->parent->left == *node)
			(*node)->parent->left = NULL;
		else if ((*node)->parent->right == *node)
			(*node)->parent->right = NULL;
	}
	free(*node);

}

void bst_remove_helper(bst_t **root, int value)
{
	bst_t *tmp;
	int check = 0;

	if (*root)
	{
	bst_remove((*root)->left, value);
	if ((*root)->n == value)
	{
		if (!(*root)->right)
		{
			remove_node_no_successor(root);
			return;
		}

		if ((*root)->right && !(*root)->right->left)
			check = 1;
		tmp = look_for_successor(&(*root)->right);
		remove_node_with_successor(&(*root), &tmp, check);
		return;
	}
	bst_remove((*root)->right, value);
	}
	return;
}

bst_t *bst_remove(bst_t *root, int value)
{
	bst_remove_helper(&root, value);
	return (root);
}

