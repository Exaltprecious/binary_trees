#include <stdlib.h>
#include "binary_trees.h"

int is_balanced(const binary_tree_t *tree, int *height);
int is_bst(const binary_tree_t *tree, int min, int max);
int max(int a, int b);
int abs(int n);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;
	binary_tree_t *left, *right;

	if (!tree)
		return (0);

	left = right = (binary_tree_t *)tree;
	while (left->left)
		left = left->left;
	while (right->right)
		right = right->right;
	return (is_balanced(tree, &height) && is_bst(tree, left->n, right->n));
}

/**
 * is_balanced - checks if a binary tree is balanced
 * @tree: pointer to the root node of the tree to check
 * @height: height of the tree
 * Return: 1 if tree is balanced, and 0 otherwise
 */
int is_balanced(const binary_tree_t *tree, int *height)
{
	int right_height = 0, left_height = 0, l, r;

	if (!tree)
		return (1);

	l = is_balanced(tree->left, &left_height);
	r = is_balanced(tree->right, &right_height);

	if (abs(left_height - right_height) > 1)
		return (0);
	*height = max(left_height, right_height) + 1;
	return (l && r);
}

/**
 * is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst(tree->left, min, tree->n - 1) &&
			is_bst(tree->right, tree->n + 1, max));
}

/**
 * max - returns the maximum of two integers
 * @a: first integer
 * @b: second integer
 * Return: maximum of a and b
 */
int max(int a, int b)
{
	return (a > b ? a : b);

