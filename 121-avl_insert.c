#include "binary_trees.h"
avl_t *rotationFunction(avl_t **root, int key);

/**
 * rotateRight - performs a right rotation.
 * @y: node to be rotated.
 * Return: new root after rotation.
 */

avl_t *rotateRight(avl_t **y)
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
 * rotateLeft - performs a left rotation.
 * @x: node to be rotated.
 * Return: new root after rotation.
 */

avl_t *rotateLeft(avl_t **x)
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
 * insertNode - inserts a node into an avl tree.
 * @root: double pointer to the root node of an avl tree.
 * @key: value to add to an avl tree.
 * @createdNode: pointer to the created node.
 * Return: pointer to the root node of an avl tree.
 */

avl_t *insertNode(avl_t **root, int key, avl_t **createdNode)
{
	avl_t *tree;

	/* Perform normal BST insertion */
	if (*root == NULL)
	{
		*createdNode = binary_tree_node(NULL, key);
		return (*createdNode);
	}

	if (key < (*root)->n)
	{
		avl_t *leftChild = insertNode(&(*root)->left, key, createdNode);
		(*root)->left = leftChild;
		leftChild->parent = *root;
	}
	else if (key > (*root)->n)
	{
		avl_t *rightChild = insertNode(&(*root)->right, key, createdNode);
		(*root)->right = rightChild;
		rightChild->parent = *root;
	}
	else
		/*Duplicate keys are not allowed in AVL tree */
		return (*root);
	tree = rotationFunction(root, key);
	return (tree);
}

/**
 * rotationFunction - performs the required avl tree rotations.
 * @root: double pointer to the root node of an avl tree.
 * @key: value to add to an avl tree.
 * Return: pointer to the root node of an avl tree.
 */

avl_t *rotationFunction(avl_t **root, int key)
{
	/* Check the balance factor and perform rotations if needed */
	int balanceFactor = binary_tree_balance(*root);
	/* Left Left Case */
	if (balanceFactor > 1 && key < (*root)->left->n)
		return (rotateRight(root));
	/* Right Right Case */
	if (balanceFactor < -1 && key > (*root)->right->n)
		return (rotateLeft(root));
	/* Left Right Case */
	if (balanceFactor > 1 && key > (*root)->left->n)
	{
		(*root)->left = rotateLeft(&(*root)->left);
		return (rotateRight(root));
	}
	/* Right Left Case */
	if (balanceFactor < -1 && key < (*root)->right->n)
	{
		(*root)->right = rotateRight(&(*root)->right);
		return (rotateLeft(root));
	}

	/* Return the updated root */
	return (*root);
}

/**
 * avl_insert - calls the appropriate functions which facilitates creation
 * of an avl tree.
 * @tree: double pointer to the root node of an avl tree.
 * @value: value to be added to the avl tree.
 * Return: pointer to the created node.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *createdNode;

	createdNode = NULL;
	*tree = insertNode(tree, value, &createdNode);
	return (createdNode);
}
