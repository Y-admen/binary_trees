#include "binary_trees.h"
#include <limits.h>

/**
 * bst_util - Utility function to check if a binary tree is a valid BST
 * @tree: a pointer to the root node of the tree to check
 * @min: The minimum allowed value for the current node
 * @max: The maximum allowed value for the current node
 * Return: 1 if BST 0 if not
*/

int bst_util(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bst_util(tree->left, min, tree->n - 1) &&
			bst_util(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if BST 0 if not
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bst_util(tree, INT_MIN, INT_MAX));
}
