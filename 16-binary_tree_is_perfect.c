#include "binary_trees.h"

/**
 * _binary_tree_height - returns the height of tree
 * @tree: tree to be measured
 * Return: 0 if tree is empty or height
*/

size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t lh, rh;

	if (!tree)
		return (0);

	lh = _binary_tree_height(tree->left);
	rh = _binary_tree_height(tree->right);

	return (1 + (lh > rh ? lh : rh));
}

/**
 *binary_tree_is_perfect - checks if a binary tree is perfect
 *@tree: a pointer to the root node of the tree to check
 *Return: If tree is NULL or not perfect 0 else 1
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (0);

	lh = _binary_tree_height(tree->left);
	rh = _binary_tree_height(tree->right);

	if (lh != rh)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right));

	return (0);
}
