#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root = NULL;

	if (!tree || !tree->right)
		return (tree);
	root = tree->right;
	root->parent = tree->parent;

	tree->parent = root;
	tree->right = root->left;
	if (tree->right)
		tree->right->parent = tree;
	root->left = tree;

	return (root);
}
