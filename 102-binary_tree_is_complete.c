#include "binary_trees.h"

size_t get_number_of_node(const binary_tree_t *tree);
int is_complete(const binary_tree_t *tree, size_t index, size_t nodes);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes;

	if (!tree)
		return (0);
	nodes = get_number_of_node(tree);
	return (is_complete(tree, 0, nodes));
}

/**
 * get_number_of_node - get the number of node
 * @tree: pointer to the root node of the tree to check
 * Return: number of node
 */
size_t get_number_of_node(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_number_of_node(tree->left) + get_number_of_node(tree->right));
}
if (!tree)
		return (0);
	return (1 + get_number_of_node(tree->left) + get_number_of_node(tree->right));
}

/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the node
 * @nodes: number of nodes
 * Return: 1 if tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t nodes)
{
	if (!tree)
		return (1);
	if (index >= nodes)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, nodes) &&
			is_complete(tree->right, 2 * index + 2, nodes));
}

