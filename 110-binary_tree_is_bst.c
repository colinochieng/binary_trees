#include "binary_trees.h"

/**
 * is_bst - A recursive function that checks if a binary tree is a valid BST
 * @node: pointer binary tree
 * @min: keep track of the valid range
 * @max: keep track of the valid range
 * Return: 0 or 1
 */
int is_bst(binary_tree_t *node, int min, int max)
{
	int i, j;

	if (node == NULL)
		return (1);

	if (node->n < min || node->n > max)
		return (0);
	i = is_bst(node->left, min, node->n - 1);
	j = is_bst(node->right, node->n + 1, max);

	return (i && j);
}

/**
 * binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst((binary_tree_t *)tree, INT_MIN, INT_MAX));
}
