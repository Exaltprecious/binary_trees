#include <stdlib.h>
#include "binary_trees.h"

avl_t *s_array_to_avl(int *arr, int l, int r, avl_t *parent);

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size == 0)
		return (NULL);
	root = s_array_to_avl(array, 0, size - 1, root);
	return (root);
}


/**
 * s_array_to_avl - builds an AVL tree from an array
 * Description: This function is a helper function for sorted_array_to_avl
 * It takes advantage of the fact that bst result in ordered arrays
 * when traversed inorder
 * @arr: pointer to the first element of the array to be converted
 * @l: left index
 * @r: right index
 * @parent: pointer to the parent node
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *s_array_to_avl(int *arr, int l, int r, avl_t *parent)
{
	int index;
	avl_t *new_node = NULL;

	if (!arr || l > r)
		return (NULL);
	index = l + (r - l) / 2;
	new_node = binary_tree_node(parent, arr[index]);

	if (!new_node)
		return (NULL);
	new_node->left = s_array_to_avl(arr, l, index - 1, new_node);
	new_node->right = s_array_to_avl(arr, index + 1, r, new_node);
	return (new_node);
}
