#include "binary_trees.h"

/**
 * _binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: If tree is NULL 0 else size
*/

size_t _binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + _binary_tree_size(tree->left) + _binary_tree_size(tree->right));
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue, *current;
	int front = 0, rear = 0;

	if (!tree || !func)
		return;

	queue = malloc(sizeof(binary_tree_t *) * _binary_tree_size(tree));
	if (!queue)
		return;

	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left)
			queue[rear++] = current->left;

		if (current->right)
			queue[rear++] = current->right;
	}
	free(queue);
}
