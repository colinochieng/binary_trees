#include "binary_trees.h"

/**
 * binary_tree_is_root - function that checks if a given node is a root
 * @node: a pointer to the node to check
 * Your function must return 1 if node is a root, otherwise 0
 * If node is NULL, return 0
 * Return: 0 or 1
*/

int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->parent)
		return (1);
	return (0);
}
