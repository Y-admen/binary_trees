#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	const binary_tree_t *current1, *current2;

	if (!first || !second)
		return (NULL);

	current1 = first;
	current2 = second;
	while (current1)
	{
		while (current2)
		{
			if (current1 == current2)
				return ((binary_tree_t *) current1);
			current2 = current2->parent;
		}
		current2 = second;
		current1 = current1->parent;
	}
	return (NULL);
}
