#include "binary_trees.h"

/**
 * helper_func - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the current subarray.
 * @end: Ending index of the current subarray.
 * @parent: Pointer to the parent of the created node;
 * Return: Pointer to the root node of the created AVL tree, or NULL on
 * failure.
 */

avl_t *helper_func(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);

	if (root == NULL)
		return (NULL);

	root->left = helper_func(array, start, mid - 1, root);
	root->right = helper_func(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Return: Pointer to the root node of the created AVL tree, or NULL on
 * failure.
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (size == 0)
		return (NULL);

	return (helper_func(array, 0, size - 1, NULL));
}

