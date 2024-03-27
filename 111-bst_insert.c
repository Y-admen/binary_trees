#include "binary_trees.h"

/**
 *bst_insert - inserts a value in a Binary Search Tree
 *@tree: a double pointer to the root node of the BST to insert the value
 *@value: value to store in the node to be inserted
 *Return: a pointer to the created node, or NULL on failure
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *current, *parent;

	if (!*tree)
	{
		new = binary_tree_node(*tree, value);
		*tree = new;
		return (new);
	}
	current = *tree;
	parent = NULL;
	while (1)
	{
		parent = current;
		if (value < current->n)
		{
			current = current->left;
			if (!current)
			{
				new = binary_tree_node(parent, value);
				parent->left = new;
				return (new);
			}
		}
		else if (value > current->n)
		{
			current = current->right;
			if (!current)
			{
				new = binary_tree_node(parent, value);
				parent->right = new;
				return (new);
			}
		}
		else
			return (NULL);
	}
}
