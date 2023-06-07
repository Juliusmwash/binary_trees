#include "binary_trees.h"


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
	return;
}

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
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balanceCheck = 0, avlValid = 0, dupCheck = 0;

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

