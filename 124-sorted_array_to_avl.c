#include "binary_trees.h"
/**
 * build_avl_tree - Recursively constructs the AVL tree
 * @array: Pointer to the array
 * @left: Left index
 * @right: Right index
 * @parent: Pointer to the parent node
 * Return: Pointer to the root node of the AVL tree
 */
binary_tree_t *build_avl_tree(int *array, int left, int right, binary_tree_t *parent)
{
    if (left > right)
        return (NULL);

    int mid = (left + right) / 2;
    binary_tree_t *root = binary_tree_node(parent, array[mid]);

    if (!root)
        return (NULL);

    root->left = build_avl_tree(array, left, mid - 1, root);
    root->right = build_avl_tree(array, mid + 1, right, root);

    return (root);
}
/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
binary_tree_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (build_avl_tree(array, 0, size - 1, NULL));
}
