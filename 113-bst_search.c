#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *current = (bst_t *)tree;

	while (current)
	{
if (current->n == value)
			return (current);
		else if (current->n > value)
			current = current->left;
		else
			current = current->right;
	}
	return (current);
}
