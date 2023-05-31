#include "binary_trees.h"

/**
* height - function that measures the height of a binary tree
* @tree: pointer to binary tree/node
* If tree is NULL, your function must return 0
* Return: height
*/

int height(binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (!tree)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);
	return ((left_height > right_height ? left_height : right_height) + 1);
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

	return (height(tree->left) == height(tree->right));
}
