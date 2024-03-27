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
 * _binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if BST 0 if not
*/

int _binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bst_util(tree, INT_MIN, INT_MAX));
}

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
 * _binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: If tree is NULL, return 0 else balance factor
*/

int _binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_height(tree->left) - _binary_tree_height(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance, is_BST, is_avl_l, is_avl_r;

	if  (!tree)
		return (0);
	balance = _binary_tree_balance(tree);
	is_BST = _binary_tree_is_bst(tree);

	if (balance > 1 || balance < -1 || is_BST == 0)
		return (0);

	if (tree->left)
	{
		is_avl_l = binary_tree_is_avl(tree->left);
		if (is_avl_l == 0)
			return (0);
	}

	if (tree->right)
	{
		is_avl_r = binary_tree_is_avl(tree->right);
		if (is_avl_r == 0)
			return (0);
	}

	return (1);
}
