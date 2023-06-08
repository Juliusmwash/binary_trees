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
 * @key: node's value searched for in the deletion process.
 * Return: root node to the avl tree after remival of the key.
 */

avl_t *avl_remove(avl_t *root, int key)
{
	avl_t *temp;

	if (root == NULL)
		return (root);

	/* Perform normal BST delete */

	if (key < root->n)
		root->left = avl_remove(root->left, key);
	else if (key > root->n)
		root->right = avl_remove(root->right, key);
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
		return (rotateRight(&root));
	/* Left Right Case */
	if (balanceFactor > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = rotateLeft(&root->left);
		return (rotateRight(&root));
	}
	/* Right Right Case */
	if (balanceFactor < -1 && binary_tree_balance(root->right) <= 0)
		return (rotateLeft(&root));
	/* Right Left Case */
	if (balanceFactor < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = rotateRight(&root->right);
		return (rotateLeft(&root));
	}
	/* Return the updated root */
	return (root);
}

