#include "binary_trees.h"

/**
 * binary_trees_ancestor -  function that finds
 * the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two nodes
 * If no common ancestor was found, your function must return NULL
*/
binary_tree_t *binary_trees_ancestor(cb *first, cb *second)
{
	binary_tree_t *temp;

	if (!first || !second)
		return (NULL);
	while (first)
	{
		temp = (binary_tree_t *)second;
		while (temp)
		{
			if (first == temp)
			{
				return (temp);
			}
			temp = temp->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
