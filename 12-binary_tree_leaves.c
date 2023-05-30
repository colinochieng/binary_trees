#include "binary_trees.h"

/**
 * binary_tree_leaves - Function that counts the leaves in a binary tree
 * @tree: pointer to the root node of
 * the tree to count the number of leaves
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a leaf
 * Return: leaf count
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;

	if (!tree->left || !tree->right)
		return (1);
	if (!tree)
		return (0);
	leaf +=  binary_tree_leaves(tree->left);
	leaf += binary_tree_leaves(tree->right);
	return (leaf);
}
