#include "binary_trees.h"
/**
 * binary_tree_is_root - Checks if a node is root
 * @node: A pointer to the node to check
 *
 * Return: If the node is the root - 1.
 *         If the node is not the root - 0.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->parent)
		return (1);
	else
		return (0);
}
