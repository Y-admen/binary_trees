#include "binary_trees.h"
/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: A pointer to the root node of the tree to delete
 *
 * Recursively deletes the given binary tree by freeing each
 * node after deleting its left and right subtrees. Sets the
 * original node pointer to NULL after freeing it.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *del;

	if (!tree)
		return;
	del = tree;
	if (tree->left)
		binary_tree_delete(tree->left);
	if (tree->right)
		binary_tree_delete(tree->right);
	free(del);
}
