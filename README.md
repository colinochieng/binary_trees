# C - Binary trees

![image](https://miro.medium.com/v2/resize:fit:1194/1*ziYvZzrttFYMXkkV9u66jw.png)
## Resources
- [Binary tree](https://intranet.alxswe.com/rltoken/1F2x42-8vUbOmU4L1C1KMg)
- [Data Structure and Algorithms - Tree](https://intranet.alxswe.com/rltoken/QmcTMCkQyrgMjrqoWxYdhw)
- [Tree Traversal](https://intranet.alxswe.com/rltoken/z6ZaXr_RxwE5nTHAUx_dfQ)
- [Binary Search Tree](https://intranet.alxswe.com/rltoken/qO5dBlMnYJzbaWG3xVpcnQ)
- [Data structures: Binary Tree](https://intranet.alxswe.com/rltoken/BeyJ2gjlE7_djwRiDyeHig)

## General
- `What is a binary tree`
- `What is the difference between a binary tree and a Binary Search Tree`
- `What is the possible gain in terms of time complexity compared to linked lists`
- `What are the depth, the height, the size of a binary tree`
- `What are the different traversal methods to go through a binary tree`
- `What is a complete, a full, a perfect, a balanced binary tree`

## Data structures
Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.

```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

## Binary Search Tree
```
typedef struct binary_tree_s bst_t;
```
## AVL Tree
```
typedef struct binary_tree_s avl_t;
```
## Max Binary Heap
```
typedef struct binary_tree_s heap_t;
```
```
PS C:\binary_trees> cat 0-main.c
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);

    root->right = binary_tree_node(root, 402);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    return (0);
}
PS C:\binary_trees> ./0-node    
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
PS C:\binary_trees>
```
