#include "binary_trees.h"

/**
 * bst_search - Searches for a node with the given value in the binary search tree.
 * @tree: a pointer to the root node of the tree to search
 * @value: The value to be searched for
 * Return: a pointer to the node if found, otherwise NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
