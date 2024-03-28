#include "binary_trees.h"

/**
 *_bst_insert - inserts a value in a Binary Search Tree
 *@tree: a double pointer to the root node of the BST to insert the value
 *@value: value to store in the node to be inserted
 *Return: a pointer to the created node, or NULL on failure
*/

avl_t *_bst_insert(avl_t **tree, int value)
{
	avl_t *new, *current, *parent;

	if (!*tree)
	{
		new = binary_tree_node(NULL, value);
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

/**
 * 
 * 
*/

avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new, *unbalanced, *parent;
    int balance;


    if (!*tree)
    {
        new = _bst_insert(tree, value);
        *tree = new;
        return (*tree);
    }
    new = _bst_insert(tree, value);
    unbalanced = new;
    while (unbalanced)
    {
        balance = binary_tree_balance(unbalanced);
    
        parent = unbalanced->parent;
        if (balance > 1 && value < unbalanced->left->n)
        {
            // Left-Left case: Perform right rotation
            unbalanced = binary_tree_rotate_right(unbalanced);
        }
        else if (balance < -1 && value > unbalanced->right->n)
        {                // Right-Right case: Perform left rotation
           unbalanced = binary_tree_rotate_left(unbalanced);
        }
        else if (balance > 1 && value > unbalanced->left->n)
        {
            // Left-Right case: Perform left-right rotation
            unbalanced->left = binary_tree_rotate_left(unbalanced->left);
            unbalanced = binary_tree_rotate_right(unbalanced);
        }
        else if (balance < -1 && value < unbalanced->right->n)
        {
            // Right-Left case: Perform right-left rotation
            unbalanced->right = binary_tree_rotate_right(unbalanced->right);
            unbalanced = binary_tree_rotate_left(unbalanced);
        }


        // Update the parent of the rotated subtree
        
        if (parent)
        {
            if (parent->left != unbalanced)
                parent->right = unbalanced;
            unbalanced->parent = parent;
        }
        else
        {
            *tree = unbalanced;
            break;
        }

        
        unbalanced = parent;
    }
    return (new);
}
