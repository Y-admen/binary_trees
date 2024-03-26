#include "binary_trees.h"
/**
 * binary_tree_insert_left - Inserts a node as the left child of another node
 * @parent: Pointer to the node to insert the left child into
 * @value: Value to store in the new node
 *
 * Return: a pointer to the created node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	if (!parent->right)
	{
		new_node->n = value;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = parent;
		parent->right = new_node;
		return (new_node);
	}
	else
	{
		new_node->n = value;
		new_node->right = parent->right;
		new_node->right = NULL;
		new_node->parent = parent;
		parent->right->parent = new_node;
		parent->right = new_node;
		return (new_node);
	}
}
