#include "binary_trees.h"

/**
 * tree_size - a function that measures
 * the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 * If tree is NULL, the function must return 0
 * Return: size
*/

size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (tree_size(tree->left) + 1 + tree_size(tree->right));
}

/**
 * tree_leaves - Function that counts the leaves in a binary tree
 * @tree: pointer to the root node of
 * the tree to count the number of leaves
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a leaf
 * Return: leaf count
*/

size_t tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;

	if (!tree)
		return (0);

	if (!tree->left || !tree->right)
		return (1);
	leaf +=  tree_leaves(tree->left);
	leaf += tree_leaves(tree->right);
	return (leaf);
}

/**
 * binary_tree_nodes - function that counts
 * the nodes with at least 1 child in a binary tree
 * @tree: is a pointer to the root node of
 * the tree to count the number of nodes
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a node
 * Return: non-leaf nodes
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	return (tree_size(tree) - tree_leaves(tree));
}
