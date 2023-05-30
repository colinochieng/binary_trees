#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node
 * as the left-child of another node
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Function must return a pointer to the created node
 * or NULL on failure or if parent is NULL
 * If parent already has a left-child, the new node must take its place
 * and the old left-child must be set as the left-child of the new node
 * Return: new node or NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	if (!parent)
	{
		return (NULL);
	}
	new = binary_tree_node(parent, value);

	if (!new)
		return (NULL);

	if (!parent->left)
	{
		parent->left = new;
	}
	else
	{
		parent->left->parent = new;
		new->left = parent->left;
		parent->left = new;
	}
	return (new);
}
