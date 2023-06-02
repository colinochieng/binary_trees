#include "binary_trees.h"

/**
 * array_to_bst - function that builds
 * a Binary Search Tree from an array
 * @array: pointer to the first element of
 * the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created BST
 * or NULL on failure
 * If a value of the array is already present in
 * the tree, this value must be ignored
*/
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root = NULL;

	for (; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}
	return (root);
}
