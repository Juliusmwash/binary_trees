#include "binary_trees.h"

/**
 * node_balance_factor - finds the height which is used to find the node's
 * balance factor.
 * @tree: root node of an avl tree.
 * Return: height.
 */

size_t node_balance_factor(const binary_tree_t *tree)
{
	int leftHeight = 0, rightHeight = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		leftHeight = 1 + node_balance_factor(tree->left);
	else
		leftHeight = 1;

	if (tree->right)
		rightHeight = 1 + node_balance_factor(tree->right);
	else
		rightHeight = 1;

	if (leftHeight > rightHeight)
		return (leftHeight);

	return (rightHeight);
}

/**
 * binary_tree_is_avl_check - finds the base factors of tree nodes and based on
 * the found factors determines if a tree is a valid avl tree or not.
 * @tree: pointer to the root node of a tree to check its avl eligibility.
 * @balCheck: this is the final decission on whether a tree is avl or not.
 * if balCheck is 0, tree is an avl tree. If 1, tree is not an avl tree.
 * Return: Nothing.
 */

void binary_tree_is_avl_check(const binary_tree_t *tree, int *balCheck)
{
	int heightLeft, heightRight, balFactor;

	if (tree)
	{
		heightLeft = node_balance_factor(tree->left);
		heightRight = node_balance_factor(tree->right);
		balFactor = heightLeft - heightRight;
		if (balFactor > 1 || balFactor < -1)
			(*balCheck) = 1;

		binary_tree_is_avl_check(tree->left, balCheck);
		binary_tree_is_avl_check(tree->right, balCheck);
	}
}

/**
 * satisfy_avl_left_tree - checks whether the values on the left subtree of the
 * root node breaks the rules of an avl tree (must be less than the root node).
 * @tree: pointer to the root node of the tree to be satisfied.
 * @rootValue: value of the root node of the tree.
 * @avlValid: if 0 tree is an avl tree, else tree is not an avl tree.
 * Return: nothing.
 */

void satisfy_avl_left_tree(bst_t *tree, int rootValue, int *avlValid)
{
	if (!tree)
		return;
	if (tree && tree->n > rootValue)
	{
		*avlValid = 1;
		return;
	}
	satisfy_avl_left_tree(tree->left, rootValue, avlValid);
	satisfy_avl_left_tree(tree->right, rootValue, avlValid);
}

/**
 * satisfy_avl_right_tree - does exactly like the 'satisfy_avl_left_tree'
 * but on the right subtree of the root node of a tree.
 * @tree: pointer to the root node of the tree to be satisfied.
 * @rootValue: value of the root node of the tree.
 * @avlValid: if 0 tree is an avl tree, else tree is not an avl tree.
 * Return: nothing.
 */

void satisfy_avl_right_tree(bst_t *tree, int rootValue, int *avlValid)
{
	if (tree == NULL)
		return;
	if (tree && tree->n < rootValue)
	{
		*avlValid = 1;
		return;
	}
	satisfy_avl_right_tree(tree->left, rootValue, avlValid);
	satisfy_avl_right_tree(tree->right, rootValue, avlValid);
}

/**
 * avl_duplicate_check - checks if there is a duplicate value in the tree
 * before qualifying it as an avl tree.
 * @tree: pointer to the root node of a tree to be qualified.
 * @value: value to be checked against in finding duplicate/duplicates.
 * @dupCheck: if 0, no duplicates found and thus tree is an avl tree.
 * Otherwise, not an avl tree.
 * Return: Nothing.
 */

void avl_duplicate_check(const bst_t *tree, int value, int *dupCheck)
{
	if (!tree)
		return;
	if ((tree->left && value == tree->left->n) ||
			(tree->right && value == tree->right->n))
	{
		*dupCheck = 1;
		return;
	}
	avl_duplicate_check((const bst_t *) tree->left, value, dupCheck);
	avl_duplicate_check((const bst_t *) tree->right, value, dupCheck);
}

/**
 * avl_duplicate_check_caller - performs the duplicate check by recursively
 * calling the appropriate functions.
 * @tree: pointer to the root node of a tree.
 * @dupCheck: if any duplicate is found it's value becomes 1 proving tree is
 * not an avl tree. Otherwise, 0 meaning it can qualify as an avl tree.
 * Return: dupCheck.
 */

int avl_duplicate_check_caller(const bst_t *tree, int *dupCheck)
{
	int value;

	if (tree)
	{
		value = tree->n;
		avl_duplicate_check(tree, value, dupCheck);
		if (!(*dupCheck))
		{
			avl_duplicate_check_caller(tree->left, dupCheck);
			avl_duplicate_check_caller(tree->right, dupCheck);
		}
	}
	return (*dupCheck);

}

/**
 * binary_tree_is_avl - proves a given tree is an avl tree if all tests are
 * successfully passed.
 * @tree: pointer to the root node of a given tree.
 * Return: 1 if tree is an avl tree. Otherwise, 0.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balanceCheck = 0, avlValid = 0, dupCheck = 0;

	if (!tree)
		return (0);

	avl_duplicate_check_caller(tree, &dupCheck);
	if (dupCheck)
		return (0);

	satisfy_avl_left_tree(tree->left, tree->n, &avlValid);
	if (avlValid)
		return (0);

	satisfy_avl_right_tree(tree->right, tree->n, &avlValid);
	if (avlValid)
		return (0);

	binary_tree_is_avl_check(tree, &balanceCheck);
	if (balanceCheck)
		return (0);
	return (1);
}

