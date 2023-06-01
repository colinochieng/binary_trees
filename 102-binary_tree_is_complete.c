#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 *num_pow - calculates power of a number
 *@base: base number
 *@exponent: exponent
 *Return: power
 */
double num_pow(double base, int exponent)
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
 * height_bt - function that measures the height of a binary tree
 * If tree is NULL, your function must return 0
 *@tree: Pointer to the root node of the tree to traverse
 * Return: height
*/
int height_bt(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = height_bt(tree->left);
	right_height = height_bt(tree->right);
	return ((left_height > right_height ? left_height : right_height) + 1);
}


/**
 * array_gen - function that Performs
 *level-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * Return: an array
 */
binary_tree_t **array_gen(const binary_tree_t *tree)
{
	binary_tree_t *current = NULL;
	int front = 0, rear = 0;
	int size = num_pow(2, (height_bt(tree) + 1));
	binary_tree_t **queue = NULL;

	if (!tree)
		return (NULL);
	queue = malloc(sizeof(binary_tree_t *) * size);

	if (!queue)
		return (NULL);
	for (int i = 0; i < size; i++)
		queue[i] = NULL;
	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];
		if (!current)
		{
			while (current == NULL && front < rear)
				current = queue[front++];

			if (!current)
				break;
		}
		queue[rear++] = current->left;
		queue[rear++] = current->right;
	}
	return (queue);
}

/**
 * count_nodes - function that counts the nodes of a binary tree
 *@tree: pointer to a binary tree
 * If tree is NULL, your function must return 0
 * Return: height
*/

int count_nodes(const binary_tree_t *tree)
{
	int count = 0;

	if (!tree)
		return (0);
	count = 1 + count_nodes(tree->left) + count_nodes((tree->right));
	return (count);
}

/**
 * binary_tree_is_complete -  function that checks if
 * a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 or 0
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int j, i = count_nodes(tree);
	binary_tree_t **queue = NULL;

	if (!tree)
		return (0);
	queue = array_gen(tree);

	for (j = 0; j < i; j++)
	{
		if (!queue[j])
		return (0);
	}
	free(queue);
	return (1);
}
