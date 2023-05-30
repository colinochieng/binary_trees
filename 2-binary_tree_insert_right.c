#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node as
 * the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 * Function must return a pointer to the created node
 * or NULL on failure or if parent is NULL
 * If parent already has a right-child, the new node must take its place
 * and the old right-child must be set as the right-child of the new node
 * Return: new node or NULL
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	if (!parent)
	{
		return (NULL);
	}
	new = binary_tree_node(parent, value);

	if (!new)
	{
		return (NULL);
	}

	if (!parent->right)
	{
		parent->right = new;
	}
	else
	{
		parent->right->parent = new;
		new->right = parent->right;
		parent->right = new;
	}

	return (new);
}
