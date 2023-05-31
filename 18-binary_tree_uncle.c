#include "binary_trees.h"

/**
 * search_sibling - function that finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 * If node is NULL or the parent is NULL, return NULL
 * If node has no sibling, return NULL
 * Return:  a pointer to the sibling node
*/

binary_tree_t *search_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}

/**
 * binary_tree_uncle - function that finds the uncle of a node
 * @node: a pointer to the node to find the sibling
 * If node is NULL or the parent is NULL, return NULL
 * If node has no sibling, return NULL
 * Return:  a pointer to the uncle node
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	return (search_sibling(node->parent));
}
