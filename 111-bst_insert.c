#include "binary_trees.h"
/**
 * bst_insert - function that inserts a value in a Binary
 * Search Tree
 * @tree: is a double pointer to the
 * root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * If the address stored in tree is NULL, the created node
 * must become the root node.
 * Return: a pointer to the created node, or NULL on failure
 * If the value is already present in the tree, it must be ignored
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = *tree, *new = NULL;

	if (!temp)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	while (temp)
	{
		if (value < temp->n)
		{
			if (!temp->left)
			{
				new = binary_tree_node(temp, value);
				temp->left = new;
				return (new);
			}
			temp = temp->left;
		}
		else if (value > temp->n)
		{
			if (!temp->right)
			{
				new = binary_tree_node(temp, value);
				temp->right = new;
				return (new);
			}
			temp = temp->right;
		}
		else if (value == temp->n)
			return (NULL);
	}
	return (NULL);
}
