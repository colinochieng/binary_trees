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
* binary_tree_balance -  function that measures
* the balance factor of a binary tree
* @tree: pointer to the root node of the tree
* to measure the balance factor
* If tree is NULL, return 0
* Return: balance
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (height(tree->left) - height(tree->right));
}
