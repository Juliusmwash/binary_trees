#include "binary_trees.h"

avl_t *rotationAfterDeletion(avl_t *root);

/**
 * findSuccessorNode - finds the successor node.
 * @node: node from which the search is to begin.
 * Return: successor node.
 */

avl_t *findSuccessorNode(avl_t *node)
{
	avl_t *current;

	current = node;
	while (current->left != NULL)
		current = current->left;
	return (current);
}

/**
 * avl_remove - performs a node deletion in the AVL tree
 * @root: pointer to the root node of an avl tree.
 * @value: node's value searched for in the deletion process.
 * Return: root node to the avl tree after remival of the key.
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (root == NULL)
		return (root);

	/* Perform normal BST delete */

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		/* Node with only one child or no child */
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			/* No child case */
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				/* One child case */
			       *root = *temp;
			}
			free(temp);
		}
		else
		{
			/* Node with two children */
			temp = findSuccessorNode(root->right);
			/* Copy the successor's data to this node */
			root->n = temp->n;
			/* Delete the successor */
			root->right = avl_remove(root->right, temp->n);
		}
	}
	/* If the tree had only one node, return */
	if (root == NULL)
		return (root);

	root = rotationAfterDeletion(root);
	return (root);
}

/**
 * rotateLeft2 - performs a left rotation.
 * @x: node to be rotated.
 * Return: new root after rotation.
 */

avl_t *rotateLeft2(avl_t **x)
{
	avl_t *y = (*x)->right;
	avl_t *T2 = y->left;

	/* Perform rotation */
	y->left = *x;
	(*x)->right = T2;

	/* Update parent pointers */
	if (T2 != NULL)
		T2->parent = *x;

	y->parent = (*x)->parent;
	(*x)->parent = y;

	/* Return the new root */
	return (y);
}


/**
 * rotateRight2 - performs a right rotation.
 * @y: node to be rotated.
 * Return: new root after rotation.
 */

avl_t *rotateRight2(avl_t **y)
{
	avl_t *x = (*y)->left;
	avl_t *T2 = x->right;

	/* Perform rotation */
	x->right = *y;
	(*y)->left = T2;

	/* Update parent pointers */
	if (T2 != NULL)
		T2->parent = *y;
	x->parent = (*y)->parent;
	(*y)->parent = x;

	/* Return the new root */
	return (x);
}

/**
 * rotationAfterDeletion - performs the rotation if necessary after
 * the deletion process.
 * @root: pointer to the root node of an avl tree.
 * Return: pointer to the root node of an avl tree.
 */

avl_t *rotationAfterDeletion(avl_t *root)
{
	int balanceFactor;

	/* Check the balance factor and perform rotations if needed */
	balanceFactor = binary_tree_balance(root);
	/* Left Left Case */
	if (balanceFactor > 1 && binary_tree_balance(root->left) >= 0)
		return (rotateRight2(&root));
	/* Left Right Case */
	if (balanceFactor > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = rotateLeft2(&root->left);
		return (rotateRight2(&root));
	}
	/* Right Right Case */
	if (balanceFactor < -1 && binary_tree_balance(root->right) <= 0)
		return (rotateLeft2(&root));
	/* Right Left Case */
	if (balanceFactor < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = rotateRight2(&root->right);
		return (rotateLeft2(&root));
	}
	/* Return the updated root */
	return (root);
}

