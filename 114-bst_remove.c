#include "binary_trees.h"

/**
 * *minValueNode - find minimum value node in a BST
 * @node: pointer to the root node of the BST
 * Return: the leftmost(least val from right)
 */
bst_t *minValueNode(bst_t *node)
{
	bst_t *current;

	current = node;
	while (current && current->left != NULL)
		current = current->left;
	return (current);
}
/**
 * bst_remove - Removes a node from a binary search tree
 * @root: A pointer to the root node of the BST
 * @value: The value to remove from the BST
 * Return: A pointer to the new root node of the BST after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
		{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = root->right;
		while (temp->left)

			temp = temp->left;
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
		}
	return (root);
}
