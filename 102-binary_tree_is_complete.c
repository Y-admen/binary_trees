#include "binary_trees.h"
/**
 * get_nodes_count - Counts the number of nodes in a binary tree
 * @tree: A pointer to the root node of the tree to count nodes for
 *
 * Return: the number of nodes in the binary tree.
 */
int get_nodes_count(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_nodes_count(tree->left) + get_nodes_count(tree->right));
}
/**
 * is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 * @index: The index of the current node (0 for root node)
 * @number_nodes: The number of nodes in the tree
 *
 * Return: 1 if the binary tree is complete, 0 if not.
 * A complete binary tree has all levels filled except the last, with nodes
 * as far left as possible.
 */
int is_complete(const binary_tree_t *tree, int index, int number_nodes)
{
	int left_complete, right_complete;

	if (!tree)
		return (1);
	if (index >= number_nodes)
		return (0);
	left_complete = is_complete(tree->left, 2 * index + 1, number_nodes);
	right_complete = is_complete(tree->right, 2 * index + 2, number_nodes);
	if (left_complete == 1 && right_complete == 1)
		return (1);
	else
		return (0);
}
/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the binary tree is complete, 0 if not.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int num_of_nodes;

	num_of_nodes = get_nodes_count(tree);
	return (is_complete(tree, 0, num_of_nodes));
}
