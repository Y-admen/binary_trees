#include "binary_trees.h"

/**
 * _binary_tree_height - calculates the height of tree
 * @tree:a pointer to the root node of the tree to measure it's height
 * Return: 0 if NULL or height
*/

int _binary_tree_height(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (0);

	lh = _binary_tree_height(tree->left);
	rh = _binary_tree_height(tree->right);

	return (1 + (lh > rh ? lh : rh));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: If tree is NULL, return 0 else balance factor
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_height(tree->left) - _binary_tree_height(tree->right));
}
