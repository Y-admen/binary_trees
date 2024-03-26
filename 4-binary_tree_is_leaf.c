#include "binary_trees.h"
/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: A pointer to the node to check
 *
 * Return: If the node is the leaf - 1.
 *         If the node is not the leaf - 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->left && !node->right)
		return (1);
	else
		return (0);
}
