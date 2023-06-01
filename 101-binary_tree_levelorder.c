#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 *power - calculates power of a number
 *@base: base number
 *@exponent: exponent
 *Return: power
 */
double power(double base, int exponent)
{
	double result = 1.0;
	int i;

	if (exponent >= 0)
	{
	for (i = 0; i < exponent; i++)
	{
		result *= base;
	}
	}
	else
	{
		base = 1.0 / base;
		exponent = -exponent;

		for (i = 0; i < exponent; i++)
		{
			result *= base;
		}
	}

	return (result);
}

/**
 * height - function that measures the height of a binary tree
 * If tree is NULL, your function must return 0
 *@tree: Pointer to the root node of the tree to traverse
 * Return: height
*/
int height(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);
	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_levelorder - function that Performs
 *level-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to the function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *current = NULL;
	int front = 0, rear = 0;
	int size = power(2, (height(tree) + 1));
	binary_tree_t **queue = NULL;

	if (!tree || !func)
		return;
	queue = malloc(sizeof(binary_tree_t *) * size);
	queue[rear++] = (binary_tree_t *)tree;

	if (!queue)
		return;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;

		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	free(queue);
}
