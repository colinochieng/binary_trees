#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * If tree is NULL, your function must return 0
 * Return: height
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (!tree)
		return (0);
	if (tree->right)
	right_h = 1 + binary_tree_height(tree->right);

	if (tree->left)
		left_h = 1 + binary_tree_height(tree->left);

	return (right_h > left_h ? right_h : left_h);
}
