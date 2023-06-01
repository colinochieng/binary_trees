#include "binary_trees.h"

/**
 * count_tree - function that counts the nodes of a binary tree
 *@tree: pointer to a binary tree
 * If tree is NULL, your function must return 0
 * Return: height
*/

int count_tree(binary_tree_t *tree)
{
	int count = 0;

	if (!tree)
		return (0);
	count = 1 + count_tree(tree->left) + count_tree((tree->right));
	return (count);
}

/**
* binary_tree_is_perfect - function that checks if a binary tree is perfect
* @tree: pointer to the root node of the tree to check
* If tree is NULL, your function must return 0
* Return: 1 or 0
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (count_tree(tree->left) == count_tree(tree->right));
}
