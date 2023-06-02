#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal.
 * @tree: pointer to the root node of a binary tree.
 * @func: function for printing out the node's value.
 * Return: nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue, *current;
	int front = 0, rear = 0;

	queue = (binary_tree_t **)malloc(sizeof(binary_tree_t) * 100);
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);

	queue[rear++] = tree->left;
	queue[rear++] = tree->right;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;

		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	free(queue);
}
